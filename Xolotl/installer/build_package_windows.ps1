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

$AudioFilesDir = Join-Path $RepoRoot "AudioFiles"
$ExpansionsDir = Join-Path $RepoRoot "Expansions"
$UserPresetsDir = Join-Path $RepoRoot "UserPresets"
$SamplesDir = Join-Path $RepoRoot "Samples"

foreach ($pathToCheck in @($Vst3Path, $AudioFilesDir, $ExpansionsDir, $UserPresetsDir, $SamplesDir)) {
    if (-not (Test-Path -LiteralPath $pathToCheck)) {
        Fail "Missing required path: $pathToCheck"
    }
}

$IsccExe = Resolve-IsccPath -RequestedPath $IsccPath
New-Item -ItemType Directory -Path $OutputDir -Force | Out-Null

$WorkDir = Join-Path ([System.IO.Path]::GetTempPath()) "$ProjectSlug-win-installer"
$StageRoot = Join-Path $WorkDir "stage"
$AppSupportStage = Join-Path $StageRoot "AppSupport"
$SamplesStage = Join-Path $StageRoot "SamplesRoot\Samples"
$IssPath = Join-Path $WorkDir "$ProjectSlug-installer.iss"

if (Test-Path -LiteralPath $WorkDir) {
    Remove-Item -LiteralPath $WorkDir -Recurse -Force
}

New-Item -ItemType Directory -Path $AppSupportStage -Force | Out-Null
New-Item -ItemType Directory -Path $SamplesStage -Force | Out-Null

Write-Log "Staging Application Support content"
Copy-Item -LiteralPath $AudioFilesDir -Destination (Join-Path $AppSupportStage "AudioFiles") -Recurse
Copy-Item -LiteralPath $ExpansionsDir -Destination (Join-Path $AppSupportStage "Expansions") -Recurse
Copy-Item -LiteralPath $UserPresetsDir -Destination (Join-Path $AppSupportStage "User Presets") -Recurse

$GeneralSettingsPath = Join-Path $AppSupportStage "GeneralSettings.xml"
$LinkWindowsPath = Join-Path $AppSupportStage "LinkWindows"

@'
<?xml version="1.0" encoding="UTF-8"?>

<GLOBAL_SETTINGS DISK_MODE="0" SCALE_FACTOR="1.0" VOICE_AMOUNT_MULTIPLIER="8"
                 MIDI_CHANNELS="1" SAMPLES_FOUND="1" OPEN_GL="0"/>
'@ | Set-Content -LiteralPath $GeneralSettingsPath -Encoding UTF8

[System.IO.File]::WriteAllText($LinkWindowsPath, "")

Write-Log "Staging sample library"
Copy-Item -Path (Join-Path $SamplesDir "*") -Destination $SamplesStage -Recurse

$SafeOutputDir = $OutputDir.Replace('\', '\\')
$SafeVst3Path = $Vst3Path.Replace('\', '\\')
$SafeAppSupportStage = $AppSupportStage.Replace('\', '\\')
$SafeSamplesStage = $SamplesStage.Replace('\', '\\')

$IssContent = @"
#define MyAppName "$ProjectName"
#define MyAppVersion "$ProjectVersion"
#define MyAppPublisher "modularsamples"
#define MyAppSlug "$ProjectSlug"
#define MyVst3Source "$SafeVst3Path"
#define MyAppSupportSource "$SafeAppSupportStage"
#define MySamplesSource "$SafeSamplesStage"

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

[Types]
Name: "full"; Description: "Full installation"; Flags: iscustom

[Components]
Name: "vst3"; Description: "VST3 plugin"; Types: full; Flags: fixed
Name: "content"; Description: "Shared content and sample library"; Types: full; Flags: fixed

[Dirs]
Name: "{commonappdata}\Common Files\modularsamples\Xolotl"; Components: content
Name: "{code:GetMusicInstallRoot}\modularsamples\Xolotl\Samples"; Components: content

[Files]
Source: "{#MyVst3Source}"; DestDir: "{commoncf}\VST3"; DestName: "{#MyAppName}.vst3"; Flags: ignoreversion; Components: vst3
Source: "{#MyAppSupportSource}\*"; DestDir: "{commonappdata}\Common Files\modularsamples\Xolotl"; Flags: ignoreversion recursesubdirs createallsubdirs; Components: content
Source: "{#MySamplesSource}\*"; DestDir: "{code:GetMusicInstallRoot}\modularsamples\Xolotl\Samples"; Flags: ignoreversion recursesubdirs createallsubdirs; Components: content

[Code]
function GetMusicInstallRoot(Param: String): String;
begin
  if not RegQueryStringValue(HKCU, 'Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders', 'My Music', Result) then
    Result := ExpandConstant('{userprofile}') + '\Music';
  Result := ExpandConstant(Result);
end;

procedure CurStepChanged(CurStep: TSetupStep);
var
  LinkTarget: String;
  LinkFile: String;
begin
  if CurStep = ssPostInstall then
  begin
    LinkTarget := GetMusicInstallRoot('') + '\modularsamples\Xolotl\Samples';
    LinkFile := ExpandConstant('{commonappdata}\Common Files\modularsamples\Xolotl\LinkWindows');
    SaveStringToFile(LinkFile, LinkTarget, False);
  end;
end;
"@

$Utf8NoBom = New-Object System.Text.UTF8Encoding($false)
[System.IO.File]::WriteAllText($IssPath, $IssContent, $Utf8NoBom)

Write-Log "Compiling installer with Inno Setup"
& $IsccExe $IssPath

Write-Log "Installer ready in $OutputDir"
