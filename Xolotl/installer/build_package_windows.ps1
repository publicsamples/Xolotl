param(
    [string]$OutputDir,
    [string]$Vst3Path,
    [string]$IsccPath
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

function Write-Log {
    param([string]$Message)
    Write-Host "[xolotl-win-pkg] $Message"
}

function Fail {
    param([string]$Message)
    throw "[xolotl-win-pkg] $Message"
}

function Get-ProjectValue {
    param(
        [string]$XmlPath,
        [string]$TagName
    )

    $match = Select-String -Path $XmlPath -Pattern "<$TagName value=`"([^`"]+)`"" | Select-Object -First 1
    if (-not $match) {
        Fail "Could not parse $TagName from $XmlPath"
    }

    return $match.Matches[0].Groups[1].Value
}

function Resolve-IsccPath {
    param([string]$RequestedPath)

    $candidates = @()

    if ($RequestedPath) {
        $candidates += $RequestedPath
    }

    if ($env:ISCC_PATH) {
        $candidates += $env:ISCC_PATH
    }

    $candidates += @(
        "C:\Program Files (x86)\Inno Setup 6\ISCC.exe",
        "C:\Program Files\Inno Setup 6\ISCC.exe"
    )

    foreach ($candidate in $candidates) {
        if ($candidate -and (Test-Path -LiteralPath $candidate)) {
            return (Resolve-Path -LiteralPath $candidate).Path
        }
    }

    Fail "Inno Setup compiler not found. Install Inno Setup 6 or pass -IsccPath."
}

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$RepoRoot = Split-Path -Parent $ScriptDir

$ProjectInfoPath = Join-Path $RepoRoot "project_info.xml"
$ProjectName = Get-ProjectValue -XmlPath $ProjectInfoPath -TagName "Name"
$ProjectVersion = Get-ProjectValue -XmlPath $ProjectInfoPath -TagName "Version"
$ProjectSlug = $ProjectName.ToLowerInvariant()

if (-not $OutputDir) {
    $OutputDir = Join-Path $RepoRoot "dist-windows"
}

if (-not $Vst3Path) {
    $Vst3Path = Join-Path $RepoRoot "Binaries\Compiled\VST3\$ProjectName.vst3"
}

$InstallerContentDir = Join-Path $ScriptDir "Xolotl"
$SamplesDir = Join-Path $RepoRoot "Samples"

foreach ($pathToCheck in @($Vst3Path, $InstallerContentDir, $SamplesDir)) {
    if (-not (Test-Path -LiteralPath $pathToCheck)) {
        Fail "Missing required path: $pathToCheck"
    }
}

$IsccExe = Resolve-IsccPath -RequestedPath $IsccPath
New-Item -ItemType Directory -Path $OutputDir -Force | Out-Null

$WorkDir = Join-Path ([System.IO.Path]::GetTempPath()) "$ProjectSlug-win-installer"
$StageRoot = Join-Path $WorkDir "stage"
$ProgramDataStage = Join-Path $StageRoot "ProgramDataXolotl"
$IssPath = Join-Path $WorkDir "$ProjectSlug-installer.iss"
$SamplesPayloadDir = Join-Path $OutputDir "Samples"

if (Test-Path -LiteralPath $WorkDir) {
    Remove-Item -LiteralPath $WorkDir -Recurse -Force
}

New-Item -ItemType Directory -Path $ProgramDataStage -Force | Out-Null

Write-Log "Staging ProgramData content from installer\\Xolotl"
Copy-Item -Path (Join-Path $InstallerContentDir "*") -Destination $ProgramDataStage -Recurse

Write-Log "Staging sample library"
$SampleFiles = @(Get-ChildItem -Path $SamplesDir -Recurse -File -ErrorAction SilentlyContinue)
$HasSampleFiles = $SampleFiles.Count -gt 0

if ($HasSampleFiles) {
    if (Test-Path -LiteralPath $SamplesPayloadDir) {
        Remove-Item -LiteralPath $SamplesPayloadDir -Recurse -Force
    }
    New-Item -ItemType Directory -Path $SamplesPayloadDir -Force | Out-Null
    Copy-Item -Path (Join-Path $SamplesDir "*") -Destination $SamplesPayloadDir -Recurse
    Write-Log "Sample payload prepared at $SamplesPayloadDir"
} else {
    Fail "No sample files found in $SamplesDir. Populate this folder before packaging samples."
}

$SafeOutputDir = $OutputDir.Replace('\', '\\')
$SafeVst3Path = $Vst3Path.Replace('\', '\\')
$SafeProgramDataStage = $ProgramDataStage.Replace('\', '\\')

$IssContent = @"
#define MyAppName "$ProjectName"
#define MyAppVersion "$ProjectVersion"
#define MyAppPublisher "modularsamples"
#define MyAppSlug "$ProjectSlug"
#define MyVst3Source "$SafeVst3Path"
#define MyProgramDataSource "$SafeProgramDataStage"

[Setup]
AppId={{8CDE9C1C-4F79-4E75-9380-5E44A0F23B7A}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\{#MyAppName}
DisableDirPage=yes
DisableProgramGroupPage=yes
Uninstallable=yes
OutputDir=$SafeOutputDir
OutputBaseFilename={#MyAppName}-{#MyAppVersion}-windows
Compression=lzma2
SolidCompression=yes
ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible
WizardStyle=modern
CloseApplications=yes
ForceCloseApplications=yes
RestartApplications=no

[Types]
Name: "full"; Description: "Full installation"; Flags: iscustom

[Components]
Name: "vst3"; Description: "VST3 plugin"; Types: full; Flags: fixed
Name: "content"; Description: "Shared content and sample library"; Types: full; Flags: fixed

[Dirs]
Name: "{commonappdata}\modularsamples\Xolotl"; Components: content
Name: "{code:GetSamplesInstallDir}"; Components: content

[Files]
Source: "{#MyVst3Source}"; DestDir: "{commoncf}\VST3"; DestName: "{#MyAppName}.vst3"; Flags: ignoreversion restartreplace; Components: vst3
Source: "{#MyProgramDataSource}\*"; DestDir: "{commonappdata}\modularsamples\Xolotl"; Flags: ignoreversion recursesubdirs createallsubdirs; Components: content
Source: "{src}\Samples\*"; DestDir: "{code:GetSamplesInstallDir}"; Flags: external ignoreversion recursesubdirs createallsubdirs; Components: content

[Code]
function GetUserShellFolderValue(const ValueName: String; const DefaultPath: String): String;
begin
  if not RegQueryStringValue(HKCU, 'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders', ValueName, Result) then
  begin
    if not RegQueryStringValue(HKCU, 'Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders', ValueName, Result) then
      Result := DefaultPath;
  end;
  Result := RemoveBackslashUnlessRoot(ExpandConstant(Result));
end;

function ResolveSamplesRoot: String;
var
  MusicRoot: String;
  DocumentsRoot: String;
  UserHome: String;
  PreferredSamplesDir: String;
  FallbackSamplesDir: String;
  ProbeFile: String;
begin
  DocumentsRoot := GetUserShellFolderValue('Personal', ExpandConstant('{userdocs}'));
  UserHome := ExtractFileDir(DocumentsRoot);
  MusicRoot := GetUserShellFolderValue('My Music', UserHome + '\Music');

  PreferredSamplesDir := MusicRoot + '\modularsamples\Xolotl\Samples';
  FallbackSamplesDir := DocumentsRoot + '\modularsamples\Xolotl\Samples';

  if not DirExists(PreferredSamplesDir) then
  begin
    try
      ForceDirectories(PreferredSamplesDir);
    except
    end;
  end;

  if DirExists(PreferredSamplesDir) then
  begin
    ProbeFile := PreferredSamplesDir + '\.__xolotl_write_probe';
    if SaveStringToFile(ProbeFile, 'ok', False) then
    begin
      DeleteFile(ProbeFile);
      Result := PreferredSamplesDir;
      exit;
    end;
  end;

  if not DirExists(FallbackSamplesDir) then
    ForceDirectories(FallbackSamplesDir);

  Result := FallbackSamplesDir;
end;

function GetSamplesInstallDir(Param: String): String;
begin
  Result := ResolveSamplesRoot();
end;

procedure CurStepChanged(CurStep: TSetupStep);
var
  LinkTarget: String;
  LinkFile: String;
begin
  if CurStep = ssPostInstall then
  begin
    LinkTarget := ResolveSamplesRoot();
    LinkFile := ExpandConstant('{commonappdata}\modularsamples\Xolotl\LinkWindows');
    SaveStringToFile(LinkFile, LinkTarget, False);
  end;
end;
"@

$Utf8NoBom = New-Object System.Text.UTF8Encoding($false)
[System.IO.File]::WriteAllText($IssPath, $IssContent, $Utf8NoBom)

Write-Log "Compiling installer with Inno Setup"
& $IsccExe $IssPath

Write-Log "Installer ready in $OutputDir"
