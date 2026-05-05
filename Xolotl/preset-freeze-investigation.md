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
| T05 | 2026-05-05 | Standalone/AU | `UISTUFF` and `Presets` disabled for test build | ON | Floating Tile | Pending | Build/test in progress. |
| T06 | 2026-05-05 | Standalone/AU | `UISTUFF` and `Presets` disabled | OFF | Floating Tile | Pending | Isolation run requested by user. |

## Known Evidence Files
- `/Users/rick/Library/Application Support/HISE/Logs/Debuglog(78).txt`
- `/Users/rick/Library/Application Support/HISE/Logs/Debuglog(79).txt`
- `/tmp/xolotl-standalone-hang-31890.txt`
- `/tmp/xolotl-standalone-hang-48394.txt`

## Hypotheses (Ranked, current)
1. Callback re-entrancy / ordering race during preset restore (UI state + sample/sample-map load overlap).
2. Message-thread paint/repaint stall under bursty restore conditions.
3. Sample loading contention/path validity edge cases during rapid state changes.
4. Scriptnode network interaction amplifying one of the above (to be isolated by DSP OFF run).

## Changes Already Attempted
- Guarded sample dropdown/index paths for invalid values.
- Added delayed/tokenized sample load logic in `Samples.js`.
- Added sample-map load validation/scheduling logic and duplicate suppression.
- Temporarily disabled sample-map loading from `WAVELABEL1` callback (diagnostic).
- Temporarily disabled waveform repaint timers in `UISTUFF.js` (diagnostic).
- Added restore-lock/queue mechanics in active scripts (note: `Presets.js` queue does not affect Floating Tile loading path).

## Next Decision Gates
1. Compare freeze behavior with DSP network `ON` vs `OFF` using same preset switching method.
2. If freeze persists with DSP `OFF`, prioritize preset/UI/script callback path.
3. If freeze disappears with DSP `OFF`, inspect scriptnode network interactions and sample integration points.
4. Capture one fresh hang sample in Xcode for each branch (`DSP ON` freeze and `DSP OFF` freeze if any).

