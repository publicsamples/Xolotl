# Xolotl

Xolotl is an open source "harmonic" synthesiser built with [HISE](https://github.com/christophhart/HISE).  Plugins are available for Mac OS , Windows and Linux.
  
![Xolot](https://raw.githubusercontent.com/publicsamples/Xolotl/main/Xolotl.png)

## 2 Harmonic, sample based oscillators

Each "oscillator" consists of 16 independently pitched samples. By default the pitch increments through the harmonic series, but can be un-quantised using the step knob. 

## Flexible 16 Stage Sample and Hold

32 oscillators need at least 16 sample and hold effects, right? maybe not under normal circumstances, but this one's a bit different. Depending on how it’s configured, it  can act as an effect, sound generator or modulator.

## 16 Stage Multimode Filter

A bunch of filters with independent control of the cutoff. There's a ton of sonic potential here. Comb filtering, phaser effects and some very tasty interaction between the S&H section.

## Finally..

At the end of the signal chain is simple ADSR envelope and pan spread control.

## Modulation

Xolotl has 2 looping envelopes, 2 polyphonic modulators, a single free running modulator, A S&H LFO, a tracking generator.

## Installation

1. Clone this repository
2. Open with [HISE](https://github.com/christophhart/HISE)
3. Download the [sample content](https://github.com/publicsamples/Xolotl/releases)
4. Copy the sample folder to Xolotl/Xolotl/Samples
5. Open the project in HISE
6. From the export menu, select "Export Sample as Archive", the click OK and wait for the process to complete
7. From the export menu, select "Export as Instrument (VSTi/AUi)"
8. Cancel the validate sample references dialogue
9. Select the export Format and click okay

If everything worked, you should have a plugin file in the binaries folder. Copy this to your usual plugin folder and follow the instructions on screen when loading the plugin. 

Pre-built versions of the plugins are available for Mac, Windows & Linux for a small fee. To find out more visit: 

https://modularsamples.gumroad.com/l/rhnqwh

