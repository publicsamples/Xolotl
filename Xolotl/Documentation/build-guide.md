# Xolotl Build Guide

This project uses separate packaging scripts for macOS, Windows, and Linux.

The scripts do not build the plugin binaries for you. Export or build the target format first in HISE or via your platform build system, then run the relevant packaging script.

## macOS

Prebuilt files expected:

- `Binaries/Builds/MacOSX/build/Release/Xolotl.vst3`
- `Binaries/Builds/MacOSX/build/Release/Xolotl.component`

Package command:

```bash
export APPLE_ID="modularsamples@gmail.com"
export APPLE_TEAM_ID="F38B5MUZNM"
export APPLE_APP_PASSWORD="your-app-specific-password"

./installer/build_sign_package_macos.sh
```

Skip notarization:

```bash
./installer/build_sign_package_macos.sh --skip-notarize
```

Output:

- `dist/Xolotl-<version>.pkg`

## Windows

Prebuilt file expected:

- `Binaries\Compiled\VST3\Xolotl.vst3`

Requirement:

- Inno Setup 6 installed

Package command:

```powershell
powershell -ExecutionPolicy Bypass -File .\installer\build_package_windows.ps1
```

Custom VST3 path or output folder:

```powershell
powershell -ExecutionPolicy Bypass -File .\installer\build_package_windows.ps1 `
  -Vst3Path "D:\path\to\Xolotl.vst3" `
  -OutputDir "D:\packaged"
```

Output:

- `dist-windows\Xolotl-<version>-windows.exe`

## Linux

Prebuilt file expected by default:

- `Binaries/Builds/LinuxMakefile/build/Xolotl.vst3`

Package command:

```bash
./installer/build_package_linux.sh
```

Custom VST3 path:

```bash
./installer/build_package_linux.sh --vst3-path /path/to/Xolotl.vst3
```

Package and install locally:

```bash
./installer/build_package_linux.sh --install-local
```

Output:

- `dist-linux/Xolotl-<version>-linux.tar.gz`
