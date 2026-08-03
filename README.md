# DevLab: I2S ICS-43434 MEMS Microphone
<!-- Exception:

The PULSAR development board line does not use the DevLab: prefix.

Format: PULSAR [MCU/Model]

Examples: PULSAR C6, PULSAR H2, PULSAR RP2350

The JUN R3 board also does not use DevLab:

Example: JUN R3 -->

## Introduction

The DevLab I2S ICS-43434 MEMS Microphone is a compact digital-audio module for
voice capture, acoustic sensing, and embedded audio prototypes. Its bottom-port
ICS-43434 microphone integrates signal conditioning, a 24-bit ADC, decimation
and anti-aliasing filters, power management, and an I²S interface.

<div align="center">
  <img src="hardware/resources/unit_top_v_1_0_0_i2s_ics43434_mems_microphone.png" width="450px" alt="DevLab I2S ICS-43434 MEMS Microphone">
  <p><em>DevLab I2S ICS-43434 MEMS Microphone</em></p>
</div>

<div align="center">

### Quick Setup

[<img src="https://img.shields.io/badge/Hardware%20Docs-blue?style=for-the-badge" alt="Hardware Docs">](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/hardware/README.md)
[<img src="https://img.shields.io/badge/Microphone%20Reference-green?style=for-the-badge" alt="Microphone Reference">](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/hardware/resources/external/emmic-ics43434-ds.pdf)
[<img src="https://img.shields.io/badge/Product%20Reference-orange?style=for-the-badge" alt="Product Reference">](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/tree/main/tools/product-reference)
[<img src="https://img.shields.io/badge/I%C2%B2S%20Example-purple?style=for-the-badge" alt="I2S Example">](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/software/examples/i2s/i2s.ino)

</div>

<div align="center">

## Overview

| Feature | Description |
|---|---|
| Microphone | InvenSense ICS-43434 bottom-port MEMS microphone |
| Audio Interface | I²S digital output |
| Sample Width | 24 bit |
| Channel Selection | `CH` input and `L/R` solder selection |
| Microphone Supply | 1.62 V to 3.63 V at the ICS-43434 VDD pin |
| Onboard Regulation | AP2112K fixed 3.3 V LDO |
| Connections | Seven 2.54 mm edge connections and 6-pin JST-SH connector |
| Hardware Revision | V1.0 |
| Manufacturer Part Number | UE0149 |

</div>

## Applications

- **Voice Capture:** Digital audio acquisition for speech and voice interfaces.
- **Acoustic Sensing:** Sound-level and event-detection prototypes.
- **Communication:** Intercom and teleconferencing experiments.
- **Microphone Arrays:** Left/right channel selection for multi-microphone tests.
- **Education:** I²S audio acquisition and embedded-systems learning.

## Resources

- [Hardware Documentation](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/hardware/README.md)
- [Product Reference Sources](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/tree/main/tools/product-reference)
- [EMMIC-ICS43434 Reference](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/hardware/resources/external/emmic-ics43434-ds.pdf)
- [Experimental I²S Example](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/software/examples/i2s/i2s.ino)

## 📝 License

All hardware and documentation in this project are licensed under the **MIT
License**. See the [repository license](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/LICENSE)
for details. Third-party reference files may have separate terms.

<div align="center">
  <sub>Template created by UNIT Electronics</sub>
</div>

> **Note of Development:**
> This hardware module is under active development. File naming, documentation,
> firmware examples, and electrical characteristics may be revised as testing
> progresses.
