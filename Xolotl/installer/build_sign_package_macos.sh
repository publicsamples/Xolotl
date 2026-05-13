#!/bin/bash

set -euo pipefail

usage() {
  cat <<'EOF'
Usage: build_sign_package_macos.sh [options]

Signs prebuilt Xolotl AU + VST3 bundles, creates a signed macOS installer
package, and optionally notarizes and staples the final pkg.

Options:
  --skip-notarize    Create and sign the pkg, but do not notarize or staple it.
  --output-dir DIR   Write final artifacts to DIR. Default: <repo>/dist
  --help             Show this help text.

Environment:
  APP_SIGN_IDENTITY        Default: Developer ID Application: Richard Taylor (F38B5MUZNM)
  INSTALLER_SIGN_IDENTITY  Default: Developer ID Installer: Richard Taylor (F38B5MUZNM)
  APPLE_ID                 Apple ID for notarization
  APPLE_TEAM_ID            Team ID for notarization
  APPLE_APP_PASSWORD       App-specific password for notarization
  NOTARY_PROFILE           Optional keychain profile name for notarytool
EOF
}

log() {
  printf '[xolotl-pkg] %s\n' "$*"
}

fail() {
  printf '[xolotl-pkg] ERROR: %s\n' "$*" >&2
  exit 1
}

require_cmd() {
  command -v "$1" >/dev/null 2>&1 || fail "Missing required command: $1"
}

copy_dir_contents() {
  local src="$1"
  local dst="$2"
  mkdir -p "$dst"
  ditto "$src" "$dst"
}

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
PROJECT_NAME="$(sed -n 's/.*<Name value="\([^"]*\)".*/\1/p' "$REPO_ROOT/project_info.xml" | head -n 1)"
PROJECT_VERSION="$(sed -n 's/.*<Version value="\([^"]*\)".*/\1/p' "$REPO_ROOT/project_info.xml" | head -n 1)"

[[ -n "$PROJECT_NAME" ]] || fail "Could not parse project name from project_info.xml"
[[ -n "$PROJECT_VERSION" ]] || fail "Could not parse project version from project_info.xml"

SKIP_NOTARIZE=0
OUTPUT_DIR="$REPO_ROOT/dist"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --skip-notarize)
      SKIP_NOTARIZE=1
      ;;
    --output-dir)
      shift
      [[ $# -gt 0 ]] || fail "--output-dir requires a value"
      OUTPUT_DIR="$1"
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

APP_SIGN_IDENTITY="${APP_SIGN_IDENTITY:-Developer ID Application: Richard Taylor (F38B5MUZNM)}"
INSTALLER_SIGN_IDENTITY="${INSTALLER_SIGN_IDENTITY:-Developer ID Installer: Richard Taylor (F38B5MUZNM)}"
APPLE_ID="${APPLE_ID:-}"
APPLE_TEAM_ID="${APPLE_TEAM_ID:-}"
APPLE_APP_PASSWORD="${APPLE_APP_PASSWORD:-${APPLE_APP_SPECIFIC_PASSWORD:-}}"
NOTARY_PROFILE="${NOTARY_PROFILE:-}"

BUILD_DIR="$REPO_ROOT/Binaries/Builds/MacOSX/build/Release"
VST3_BUNDLE="$BUILD_DIR/${PROJECT_NAME}.vst3"
AU_BUNDLE="$BUILD_DIR/${PROJECT_NAME}.component"
PROJECT_SLUG="$(printf '%s' "$PROJECT_NAME" | tr '[:upper:]' '[:lower:]')"

STAGE_DIR="$(mktemp -d "/tmp/${PROJECT_SLUG}-pkg.XXXXXX")"
PAYLOAD_ROOT="$STAGE_DIR/root"
SCRIPTS_DIR="$STAGE_DIR/scripts"
OUTPUT_DIR_ABS="$OUTPUT_DIR"

cleanup() {
  rm -rf "$STAGE_DIR"
}
trap cleanup EXIT

require_cmd codesign
require_cmd pkgbuild
require_cmd productsign
require_cmd ditto
require_cmd dscl
require_cmd stat
require_cmd awk

mkdir -p "$OUTPUT_DIR_ABS"

if [[ "$SKIP_NOTARIZE" -eq 0 ]]; then
  require_cmd xcrun
fi

[[ -d "$VST3_BUNDLE" ]] || fail "Missing VST3 bundle: $VST3_BUNDLE"
[[ -d "$AU_BUNDLE" ]] || fail "Missing Audio Unit bundle: $AU_BUNDLE"
[[ -d "$REPO_ROOT/AudioFiles" ]] || fail "Missing AudioFiles source folder"
[[ -d "$REPO_ROOT/Expansions" ]] || fail "Missing Expansions source folder"
[[ -d "$REPO_ROOT/UserPresets" ]] || fail "Missing UserPresets source folder"
[[ -d "$REPO_ROOT/Samples" ]] || fail "Missing Samples source folder"

log "Signing plugin bundles"
codesign --force --deep --options runtime --timestamp --sign "$APP_SIGN_IDENTITY" "$VST3_BUNDLE"
codesign --force --deep --options runtime --timestamp --sign "$APP_SIGN_IDENTITY" "$AU_BUNDLE"
codesign --verify --deep --strict --verbose=2 "$VST3_BUNDLE"
codesign --verify --deep --strict --verbose=2 "$AU_BUNDLE"

PLUGIN_VST3_DEST="$PAYLOAD_ROOT/Library/Audio/Plug-Ins/VST3"
PLUGIN_AU_DEST="$PAYLOAD_ROOT/Library/Audio/Plug-Ins/Components"
INSTALLER_CONTENT_ROOT="$PAYLOAD_ROOT/Users/Shared/modularsamples/Xolotl Installer Payload"
APP_SUPPORT_TEMPLATE="$INSTALLER_CONTENT_ROOT/Xolotl App Support"
MUSIC_TEMPLATE="$INSTALLER_CONTENT_ROOT/Xolotl Music"

mkdir -p "$PLUGIN_VST3_DEST" "$PLUGIN_AU_DEST" "$APP_SUPPORT_TEMPLATE" "$MUSIC_TEMPLATE" "$SCRIPTS_DIR"
copy_dir_contents "$VST3_BUNDLE" "$PLUGIN_VST3_DEST/${PROJECT_NAME}.vst3"
copy_dir_contents "$AU_BUNDLE" "$PLUGIN_AU_DEST/${PROJECT_NAME}.component"

log "Staging Application Support payload"
copy_dir_contents "$REPO_ROOT/AudioFiles" "$APP_SUPPORT_TEMPLATE/AudioFiles"
copy_dir_contents "$REPO_ROOT/Expansions" "$APP_SUPPORT_TEMPLATE/Expansions"
copy_dir_contents "$REPO_ROOT/UserPresets" "$APP_SUPPORT_TEMPLATE/User Presets"
cat >"$APP_SUPPORT_TEMPLATE/GeneralSettings.xml" <<'EOF'
<?xml version="1.0" encoding="UTF-8"?>

<GLOBAL_SETTINGS DISK_MODE="0" SCALE_FACTOR="1.0" VOICE_AMOUNT_MULTIPLIER="8"
                 MIDI_CHANNELS="1" SAMPLES_FOUND="1" OPEN_GL="0"/>
EOF
: >"$APP_SUPPORT_TEMPLATE/LinkOSX"

log "Staging Music samples payload"
copy_dir_contents "$REPO_ROOT/Samples" "$MUSIC_TEMPLATE/Samples"

cat >"$SCRIPTS_DIR/postinstall" <<'EOF'
#!/bin/bash
set -euo pipefail

console_user="$(stat -f '%Su' /dev/console)"
if [[ -z "$console_user" || "$console_user" == "root" || "$console_user" == "loginwindow" ]]; then
  echo "Unable to resolve logged-in user" >&2
  exit 1
fi

home_dir="$(dscl . -read "/Users/$console_user" NFSHomeDirectory | awk '{print $2}')"
group_name="$(id -gn "$console_user")"
payload_root="/Users/Shared/modularsamples/Xolotl Installer Payload"
app_support_src="$payload_root/Xolotl App Support"
music_src="$payload_root/Xolotl Music"
app_support_dst="$home_dir/Library/Application Support/modularsamples/Xolotl"
music_parent_dst="$home_dir/Music/modularsamples"
music_dst="$music_parent_dst/Xolotl"
link_file="$app_support_dst/LinkOSX"
sample_path="$music_dst/Samples"

mkdir -p "$app_support_dst" "$music_parent_dst"
ditto "$app_support_src" "$app_support_dst"
ditto "$music_src" "$music_dst"
printf '%s' "$sample_path" >"$link_file"
chown -R "$console_user:$group_name" "$app_support_dst" "$music_dst"
rm -rf "$payload_root"

exit 0
EOF
chmod 755 "$SCRIPTS_DIR/postinstall"

UNSIGNED_PKG="$OUTPUT_DIR_ABS/${PROJECT_NAME}-${PROJECT_VERSION}-unsigned.pkg"
SIGNED_PKG="$OUTPUT_DIR_ABS/${PROJECT_NAME}-${PROJECT_VERSION}.pkg"

log "Building flat installer package"
pkgbuild \
  --root "$PAYLOAD_ROOT" \
  --scripts "$SCRIPTS_DIR" \
  --identifier "com.modularsamples.${PROJECT_SLUG}.installer" \
  --version "$PROJECT_VERSION" \
  --install-location "/" \
  "$UNSIGNED_PKG"

log "Signing installer package"
productsign --sign "$INSTALLER_SIGN_IDENTITY" "$UNSIGNED_PKG" "$SIGNED_PKG"
rm -f "$UNSIGNED_PKG"

if [[ "$SKIP_NOTARIZE" -eq 0 ]]; then
  log "Submitting pkg for notarization"
  if [[ -n "$NOTARY_PROFILE" ]]; then
    xcrun notarytool submit "$SIGNED_PKG" --keychain-profile "$NOTARY_PROFILE" --wait
  else
    [[ -n "$APPLE_ID" ]] || fail "APPLE_ID is required for notarization when NOTARY_PROFILE is not set"
    [[ -n "$APPLE_TEAM_ID" ]] || fail "APPLE_TEAM_ID is required for notarization when NOTARY_PROFILE is not set"
    [[ -n "$APPLE_APP_PASSWORD" ]] || fail "APPLE_APP_PASSWORD is required for notarization when NOTARY_PROFILE is not set"
    xcrun notarytool submit \
      "$SIGNED_PKG" \
      --apple-id "$APPLE_ID" \
      --team-id "$APPLE_TEAM_ID" \
      --password "$APPLE_APP_PASSWORD" \
      --wait
  fi

  log "Stapling notarization ticket"
  xcrun stapler staple "$SIGNED_PKG"
fi

log "Installer ready: $SIGNED_PKG"
