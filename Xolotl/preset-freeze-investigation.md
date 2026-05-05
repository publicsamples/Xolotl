# Xolotl Preset Freeze Investigation Log

## Objective
Identify the root cause of intermittent freeze/hang when loading presets in standalone and plugin builds.

## Environment Snapshot
- Project: `Xolotl`
- Machine: Rick laptop (macOS, Apple Silicon assumed)
- HISE: recent dev builds in use (exact commit/hash should be logged per run)
- Date baseline: 2026-05-05

## How To Log A Test Run
For each run, add one row in the table below.

Required fields:
- Date/time
- Build target (`HISE preview`, `Standalone`, `AU in Logic`)
- HISE commit/hash
- Scripts enabled/disabled
- DSP network enabled/disabled
- Preset load method (`Floating Tile browser` / custom menu)
- Test pattern (eg rapid random, fixed list)
- Result (`No freeze`, `Freeze`)
- Time to freeze / approx preset count
- Last preset shown when freeze occurred
- Evidence file paths (logs, stack samples)

## Test Matrix (Current)
| ID | Date | Target | Script State | DSP Network | Preset Load Path | Result | Notes |
|---|---|---|---|---|---|---|---|
| T01 | 2026-05-05 | Standalone | Normal active scripts | ON | Floating Tile | Freeze | Freeze after ~15-20 preset loads (reported). |
| T02 | 2026-05-05 | HISE preview | Normal active scripts | ON | Preset switching in HISE | Mixed | Sometimes freeze, sometimes not reproducible for ~1 min. |
| T03 | 2026-05-05 | AU (Logic) | Normal active scripts | ON | Host preset loading | Freeze | Freeze after a few presets (reported). |
| T04 | 2026-05-05 | Standalone | `UISTUFF` timer diagnostics applied | ON | Floating Tile | Freeze | Freeze reproduced on preset `organ` after diagnostic changes. |
| T05 | 2026-05-05 | Standalone/AU | `UISTUFF` and `Presets` disabled for test build | ON | Floating Tile | Freeze | Still freezes; moved from `TableEditor.cpp` to lock assert in `MiscToolClasses.h:1219`. |
| T06 | 2026-05-05 | Standalone/AU | `UISTUFF` and `Presets` disabled | OFF | Floating Tile | Inconclusive | Not required once thread-lock root cause confirmed. |
| T07 | 2026-05-05 | Debug standalone | `saveInPreset=false` for ScriptSliderPack/ScriptTable IDs | ON | Floating Tile | No freeze (3+ min rapid switching) | Strongly confirms complex data restore concurrency issue. |

## Known Evidence Files
- `/Users/rick/Library/Application Support/HISE/Logs/Debuglog(78).txt`
- `/Users/rick/Library/Application Support/HISE/Logs/Debuglog(79).txt`
- `/tmp/xolotl-standalone-hang-31890.txt`
- `/tmp/xolotl-standalone-hang-48394.txt`

## Confirmed Root Cause
Freeze is tied to restoring complex preset UI data (`ScriptSliderPack` / `ScriptTable`) while UI components are rebuilding on message thread.

Key stack evidence:
- Sample loading thread:
  - `UserPresetHandler::loadUserPresetInternal`
  - `Content::restoreAllControlsFromPreset`
  - `ComplexDataScriptComponent::restoreFromValueTree`
  - `SliderPackData::fromBase64` -> `swapBuffer`
  - assert in `SimpleReadWriteLock::ScopedWriteLock` (`MiscToolClasses.h:1219`)
- Message thread at same time:
  - `SliderPack::timerCallback`
  - `SliderPack::rebuildSliders`

Interpretation:
- Two writer paths contend for `SliderPack` data lock during preset restore, causing assertion and downstream freeze behavior.

## Changes Already Attempted
- Guarded sample dropdown/index paths for invalid values.
- Added delayed/tokenized sample load logic in `Samples.js`.
- Added sample-map load validation/scheduling logic and duplicate suppression.
- Temporarily disabled sample-map loading from `WAVELABEL1` callback (diagnostic).
- Temporarily disabled waveform repaint timers in `UISTUFF.js` (diagnostic).
- Added restore-lock/queue mechanics in active scripts (note: `Presets.js` queue does not affect Floating Tile loading path).
- Disabled preset save/restore for known `ScriptSliderPack` / `ScriptTable` component IDs in `Controls.js` (diagnostic workaround), which removed freeze in rapid switching test.

## Current Workaround (Stable)
- In [`Scripts/Controls.js`](/Users/rick/Documents/GitHub/Xolotl/Xolotl/Scripts/Controls.js), set `saveInPreset=false` for:
  - `SliderPack1..5`
  - `ScriptSliderPack1..3`
  - `pitch-sp4..7`
  - `ModSp1`, `ModSp2`, `ModSp3`
  - `ModTable1`, `ModTable2`

This prevents restoring complex UI buffer blobs from presets and avoids the lock contention.

## Remaining Product Work
1. Decide permanent behavior for modulation shape persistence (custom safe serialization path or keep excluded from presets).
2. File HISE bug report with stack traces and minimal repro.
