# DevLab I²S ICS-43434 Hardware

This directory contains the available hardware resources for the **DevLab: I2S
ICS-43434 MEMS Microphone**. Its manufacturing part number is **UE0149**. The
board views show hardware revision V1.0.

> This is an initial hardware reference. A released schematic, dimensional
> drawing, pinout artwork, and complete module-level electrical validation have
> not yet been added. Values marked as pending must not be inferred from the
> regulator or individual component ratings.

## Board Views

<div align="center">
  <img src="resources/unit_top_v_1_0_0_i2s_ics43434_mems_microphone.png" width="720px" alt="ICS-43434 module top view">
  <p><em>Top view</em></p>
  <img src="resources/unit_btm_v_1_0_0_i2s_ics43434_mems_microphone.png" width="720px" alt="ICS-43434 module bottom view">
  <p><em>Bottom view</em></p>
</div>

## Connector and Pin Layout

The seven edge connections and the six signal contacts of the JST-SH connector
are identified by the released V1.0 board artwork. `VIN` is available only on
the edge connection; the connector exposes `VSYS`, `GND`, `CH`, `WS`, `SD`, and
`SCK`.

The BOM separately lists a four-conductor QWIIC-style harness. Because J1 is a
six-position connector, cable inclusion and compatibility remain pending and
must not be assumed from that BOM line alone.

| Signal | Direction | Description | Electrical status |
|---|---|---|---|
| `VIN` | Input | Module input supply before onboard regulation | Allowed module range pending |
| `VSYS` | Power | Module system rail; routed to the JST supply contact | Value/range pending schematic verification |
| `GND` | Power | Common reference | 0 V |
| `CH` | Input | ICS-43434 left/right channel selection | Low selects left; high selects right |
| `SCK` | Input | I²S serial bit clock from the host | Microphone digital input |
| `WS` | Input | I²S word select from the host | Low = left word, high = right word |
| `SD` | Output | I²S serial data to the host | 24-bit audio data |

The bottom-side `L/R` solder selection controls the channel assignment. The
board also includes `LED ON` and `JST VCC` solder options; their exact default
states and circuit behavior remain pending schematic confirmation.

## Essential Electrical Characteristics

### ICS-43434 microphone

| Parameter | Value | Source / scope |
|---|---:|---|
| Microphone VDD | 1.62 V to 3.63 V | EMMIC-ICS43434 reference |
| Digital output | 24 bit | ICS-43434 I²S interface |
| Signal-to-noise ratio | 64 dBA typical | Microphone characteristic |
| Frequency response | 60 Hz to 20 kHz | Range stated by the EMMIC-ICS43434 reference |
| Sensitivity tolerance | ±1 dB | Microphone characteristic |

These microphone values are not the same as the permitted voltage at the
module's `VIN` pin. `VIN` and `VSYS` limits will be published after the
schematic and board measurements are available.

### BOM-confirmed module components

| Reference | Component | Relevant identification |
|---|---|---|
| MK1 | Digital MEMS microphone | ICS-43434, bottom port, I²S output |
| U3 | Fixed LDO regulator | AP2112K-3.3TRG1, 3.3 V |
| J1 | 6-position connector | JST SM06B-SRSS-TB, SH series, 1.0 mm pitch |
| U$1 | Edge/header connection | 1 × 7, 2.54 mm pitch |
| D2 | Schottky diode | NSR0320MW2T1G |
| D1 | Indicator LED | Orange, 0402 |
| C8, C9 | Ceramic capacitors | 1 µF, 6.3 V, X5R, 0402 |
| C6 | Ceramic capacitor | 100 nF, 0402 |
| C1 | Ceramic capacitor | 200 pF, C0G, 50 V, 0402 |
| R1 | Resistor | 4.7 kΩ, 0402 |
| R2, R3 | Resistors | 10 kΩ, 0402 |
| R5 | Resistor / link | 0 Ω, 0402 |

Component maximum ratings do not establish the allowable operating range of
the assembled module. The maintained manufacturing BOM remains the controlling
source for procurement details.

## Functional Overview

The host supplies the I²S clocks on `SCK` and `WS`. The ICS-43434 converts the
acoustic signal and transmits 24-bit samples on `SD` in the time slot selected
by `CH`. The onboard AP2112K provides a 3.3 V rail for the microphone circuit.

Keep the bottom acoustic port unobstructed and avoid debris, adhesive, flux,
or enclosure pressure over the sound opening. Confirm common ground before
applying clocks or power.

## Development Status

- The example under `software/examples/i2s/` is experimental and not yet part
  of the validated product reference.
- Host GPIO numbers are application-specific; they are not module pin numbers.
- Module-level `VIN`/`VSYS` ratings, clock limits, current consumption,
  dimensions, schematic, and validated setup procedure remain pending.

## References

- [EMMIC-ICS43434 reference](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/hardware/resources/external/emmic-ics43434-ds.pdf)
- [Manufacturing BOM](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/hardware/resources/UNIT-0149%20Devlab_%20I2S%20ICS-43434%20MEMS%20Microphone-20260803T153602Z-1-001/UNIT-0149%20Devlab_%20I2S%20ICS-43434%20MEMS%20Microphone/Fabricaci%C3%B3n%20/BOM/UE0149%20-BOM-%20I2S%20ICS-43434%20-%20P.xlsx)
