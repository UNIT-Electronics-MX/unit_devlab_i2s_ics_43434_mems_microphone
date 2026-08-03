# DevLab: I2S ICS-43434 MEMS Microphone

This compact DevLab microphone module is built around the ICS-43434
bottom-port MEMS microphone. The sensor integrates signal conditioning, a
24-bit ADC, decimation and anti-aliasing filters, and a standard I²S digital
audio interface.

> **Development status:** Hardware documentation is being assembled and the
> available firmware example is still under test. Verify the module supply and
> host GPIO assignment before connecting hardware. The current repository
> sources identify this board as an ICS-43434 I²S module; they do not describe
> an ICS-41350 PDM module.

<div align="center">
  <img src="hardware/resources/unit_top_v_1_0_0_i2s_ics43434_mems_microphone.png" width="600px" alt="ICS-43434 I2S MEMS microphone module, top view">
  <p><em>DevLab I²S ICS-43434 module, hardware V1.0</em></p>
</div>

## Overview

| Feature | Description |
|---|---|
| Product | DevLab: I2S ICS-43434 MEMS Microphone |
| Manufacturer part number | UE0149 |
| Hardware revision shown | V1.0 |
| Microphone | TDK InvenSense ICS-43434 |
| Audio interface | I²S, 24-bit digital output |
| Channel selection | CH input / L-R solder selection |
| Microphone supply | 1.62 V to 3.63 V at the ICS-43434 VDD pin |
| Onboard regulation | AP2112K fixed 3.3 V LDO |
| Connections | Seven castellated through-holes and 6-pin JST-SH connector |

The microphone reference supplied with this repository lists a typical signal
to-noise ratio of 64 dBA, a 60 Hz to 20 kHz frequency response, and a
sensitivity tolerance of ±1 dB. These values describe the microphone, not a
completed acoustic characterization of the DevLab module.

## Signals

| Board label | Direction | Function |
|---|---|---|
| `VIN` | Power input | Module input supply; final allowed range is pending schematic verification |
| `VSYS` | Power | Module system rail |
| `GND` | Power | Ground reference |
| `CH` | Input | I²S left/right channel selection |
| `SCK` | Input | I²S serial bit clock |
| `WS` | Input | I²S word select / left-right clock |
| `SD` | Output | I²S serial audio data |

`SCK`, `WS`, and `CH` are driven by the host. `SD` is driven by the microphone.
Do not treat this interface as PDM.

## Applications

- Voice capture and recognition prototypes
- Intercom and teleconferencing systems
- Acoustic sensing and security projects
- Stereo or multi-microphone experiments using channel selection
- Educational I²S audio acquisition

## Documentation and Resources

- [Hardware notes and connector reference](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/hardware/README.md)
- [Product-reference source](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/tree/main/tools/product-reference)
- [EMMIC-ICS43434 reference](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/hardware/resources/external/emmic-ics43434-ds.pdf)
- [Experimental software directory](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/tree/main/software)

## License

See the [repository license](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/LICENSE). Hardware, software, and third-party reference files may
have separate terms; consult each source before redistribution.

<div align="center">
  <sub>UNIT Electronics · DevLab series</sub>
</div>
