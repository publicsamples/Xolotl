#!/usr/bin/env bash

set -euo pipefail

usage() {
  cat <<'EOF'
Usage: build_package_linux.sh [options]

Creates a Linux release tarball containing:
  - Xolotl.vst3 for per-user installation into ~/.vst3
  - shared content for ~/.local/share/modularsamples/Xolotl
  - samples for the user's Music folder
  - generated install.sh and uninstall.sh helpers

Options:
  --vst3-path PATH   Path to the prebuilt Linux VST3 bundle.
                     Default: <repo>/Binaries/Builds/LinuxMakefile/build/Xolotl.vst3
  --output-dir DIR   Output directory for the final tarball.
                     Default: <repo>/dist-linux
  --install-local    Also run the generated installer on the current machine.
  --help             Show this help text.
EOF
}

log() {
  printf '[xolotl-linux-pkg] %s\n' "$*"
}

fail() {
  printf '[xolotl-linux-pkg] ERROR: %s\n' "$*" >&2
  exit 1
}

copy_dir_contents() {
  local src="$1"
  local dst="$2"
  mkdir -p "$dst"
  cp -R "$src"/. "$dst"/
}

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
PROJECT_NAME="$(sed -n 's/.*<Name value="\([^"]*\)".*/\1/p' "$REPO_ROOT/project_info.xml" | head -n 1)"
PROJECT_VERSION="$(sed -n 's/.*<Version value="\([^"]*\)".*/\1/p' "$REPO_ROOT/project_info.xml" | head -n 1)"

[[ -n "$PROJECT_NAME" ]] || fail "Could not parse project name from project_info.xml"
[[ -n "$PROJECT_VERSION" ]] || fail "Could not parse project version from project_info.xml"

VST3_PATH="$REPO_ROOT/Binaries/Builds/LinuxMakefile/build/${PROJECT_NAME}.vst3"
OUTPUT_DIR="$REPO_ROOT/dist-linux"
INSTALL_LOCAL=0

while [[ $# -gt 0 ]]; do
  case "$1" in
    --vst3-path)
      shift
      [[ $# -gt 0 ]] || fail "--vst3-path requires a value"
      VST3_PATH="$1"
      ;;
    --output-dir)
      shift
      [[ $# -gt 0 ]] || fail "--output-dir requires a value"
      OUTPUT_DIR="$1"
      ;;
    --install-local)
      INSTALL_LOCAL=1
      ;;
    --help)
      usage
      exit 0
      ;;
    *)
      fail "Unknown argument: $1"
      ;;
  esac
  shift
done

[[ -d "$VST3_PATH" ]] || fail "Missing Linux VST3 bundle: $VST3_PATH"
[[ -d "$REPO_ROOT/AudioFiles" ]] || fail "Missing AudioFiles source folder"
[[ -d "$REPO_ROOT/Expansions" ]] || fail "Missing Expansions source folder"
[[ -d "$REPO_ROOT/UserPresets" ]] || fail "Missing UserPresets source folder"
[[ -d "$REPO_ROOT/Samples" ]] || fail "Missing Samples source folder"

mkdir -p "$OUTPUT_DIR"

STAGE_DIR="$(mktemp -d "/tmp/${PROJECT_NAME}-linux-pkg.XXXXXX")"
PACKAGE_ROOT="$STAGE_DIR/${PROJECT_NAME}-linux"
APP_SUPPORT_STAGE="$PACKAGE_ROOT/payload/appdata"
SAMPLES_STAGE="$PACKAGE_ROOT/payload/music/modularsamples/${PROJECT_NAME}/Samples"
VST3_STAGE="$PACKAGE_ROOT/payload/vst3/${PROJECT_NAME}.vst3"
ARCHIVE_PATH="$OUTPUT_DIR/${PROJECT_NAME}-${PROJECT_VERSION}-linux.tar.gz"

cleanup() {
  rm -rf "$STAGE_DIR"
}
trap cleanup EXIT

mkdir -p "$APP_SUPPORT_STAGE" "$SAMPLES_STAGE" "$PACKAGE_ROOT/payload/vst3"

log "Staging Linux VST3 bundle"
copy_dir_contents "$VST3_PATH" "$VST3_STAGE"

log "Staging shared content"
copy_dir_contents "$REPO_ROOT/AudioFiles" "$APP_SUPPORT_STAGE/AudioFiles"
copy_dir_contents "$REPO_ROOT/Expansions" "$APP_SUPPORT_STAGE/Expansions"
copy_dir_contents "$REPO_ROOT/UserPresets" "$APP_SUPPORT_STAGE/User Presets"
cat >"$APP_SUPPORT_STAGE/GeneralSettings.xml" <<'EOF'
<?xml version="1.0" encoding="UTF-8"?>

<GLOBAL_SETTINGS DISK_MODE="0" SCALE_FACTOR="1.0" VOICE_AMOUNT_MULTIPLIER="8"
                 MIDI_CHANNELS="1" SAMPLES_FOUND="1" OPEN_GL="0"/>
EOF
: >"$APP_SUPPORT_STAGE/LinkLinux"

log "Staging sample library"
copy_dir_contents "$REPO_ROOT/Samples" "$SAMPLES_STAGE"

cat >"$PACKAGE_ROOT/install.sh" <<'EOF'
#!/usr/bin/env bash

set -euo pipefail

log() {
  printf '[xolotl-linux-install] %s\n' "$*"
}

resolve_music_dir() {
  if [[ -n "${XDG_MUSIC_DIR:-}" ]]; then
    printf '%s\n' "$XDG_MUSIC_DIR"
    return
  fi

  local config_file="$HOME/.config/user-dirs.dirs"
  if [[ -f "$config_file" ]]; then
    local value
    value="$(sed -n 's/^XDG_MUSIC_DIR=\"\(.*\)\"$/\1/p' "$config_file" | head -n 1)"
    if [[ -n "$value" ]]; then
      value="${value//\$HOME/$HOME}"
      printf '%s\n' "$value"
      return
    fi
  fi

  printf '%s\n' "$HOME/Music"
}

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PAYLOAD_DIR="$SCRIPT_DIR/payload"
PLUGIN_SRC="$PAYLOAD_DIR/vst3/Xolotl.vst3"
APPDATA_SRC="$PAYLOAD_DIR/appdata"
SAMPLES_SRC="$PAYLOAD_DIR/music/modularsamples/Xolotl/Samples"

PLUGIN_DEST_DIR="${XDG_DATA_HOME:-$HOME/.local/share}"
PLUGIN_DEST_VST3="$HOME/.vst3"
APPDATA_DEST="$PLUGIN_DEST_DIR/modularsamples/Xolotl"
MUSIC_DIR="$(resolve_music_dir)"
SAMPLES_DEST="$MUSIC_DIR/modularsamples/Xolotl/Samples"
LINK_FILE="$APPDATA_DEST/LinkLinux"

mkdir -p "$PLUGIN_DEST_VST3" "$APPDATA_DEST" "$SAMPLES_DEST"
cp -R "$PLUGIN_SRC" "$PLUGIN_DEST_VST3/"
cp -R "$APPDATA_SRC"/. "$APPDATA_DEST"/
cp -R "$SAMPLES_SRC"/. "$SAMPLES_DEST"/
printf '%s' "$SAMPLES_DEST" >"$LINK_FILE"

log "Installed VST3 to $PLUGIN_DEST_VST3/Xolotl.vst3"
log "Installed shared content to $APPDATA_DEST"
log "Installed samples to $SAMPLES_DEST"
EOF

cat >"$PACKAGE_ROOT/uninstall.sh" <<'EOF'
#!/usr/bin/env bash

set -euo pipefail

resolve_music_dir() {
  if [[ -n "${XDG_MUSIC_DIR:-}" ]]; then
    printf '%s\n' "$XDG_MUSIC_DIR"
    return
  fi

  local config_file="$HOME/.config/user-dirs.dirs"
  if [[ -f "$config_file" ]]; then
    local value
    value="$(sed -n 's/^XDG_MUSIC_DIR=\"\(.*\)\"$/\1/p' "$config_file" | head -n 1)"
    if [[ -n "$value" ]]; then
      value="${value//\$HOME/$HOME}"
      printf '%s\n' "$value"
      return
    fi
  fi

  printf '%s\n' "$HOME/Music"
}

APPDATA_BASE="${XDG_DATA_HOME:-$HOME/.local/share}"
APPDATA_DEST="$APPDATA_BASE/modularsamples/Xolotl"
PLUGIN_DEST="$HOME/.vst3/Xolotl.vst3"
MUSIC_DIR="$(resolve_music_dir)"
SAMPLES_ROOT="$MUSIC_DIR/modularsamples/Xolotl"

rm -rf "$PLUGIN_DEST" "$APPDATA_DEST" "$SAMPLES_ROOT"

printf '[xolotl-linux-install] Removed %s\n' "$PLUGIN_DEST"
printf '[xolotl-linux-install] Removed %s\n' "$APPDATA_DEST"
printf '[xolotl-linux-install] Removed %s\n' "$SAMPLES_ROOT"
EOF

chmod +x "$PACKAGE_ROOT/install.sh" "$PACKAGE_ROOT/uninstall.sh"

log "Creating release archive"
(
  cd "$STAGE_DIR"
  tar -czf "$ARCHIVE_PATH" "$(basename "$PACKAGE_ROOT")"
)

if [[ "$INSTALL_LOCAL" -eq 1 ]]; then
  log "Running generated installer locally"
  "$PACKAGE_ROOT/install.sh"
fi

log "Linux release archive ready: $ARCHIVE_PATH"
