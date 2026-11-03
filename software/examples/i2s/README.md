# I²S Examples — UE0149

These Arduino C++ examples target an ESP32-S3. Connect board `SCK`
to host GPIO36, `WS` to GPIO37, `SD` to GPIO35, and `GND` to
GND. Confirm these GPIOs are available on the selected development
board. Verify the module's `VIN`/`VSYS` supply path and logic
voltage against the schematic or a measured board before applying
power.

The UE0149 schematic shows `CH` pulled low, selecting the **left**
I²S time slot. Both local examples select the left receiver slot.
If the assembled board selects right, change the host slot as well.

| Sketch | Dependency | Serial output |
|---|---|---|
| [AudioInputBasicRead](cpp_examples/AudioInputBasicRead/README.md) | [DevLab_AudioInput](https://github.com/UNIT-Electronics-MX/unit_devlab_audioinput_library), Arduino-ESP32 3.x | Peak values at 115200 baud |
| [LegacySerialPlotter](cpp_examples/LegacySerialPlotter/README.md) | Older Arduino-ESP32 I²S driver | Shifted sample average at 115200 baud |

The library reports ESP32-S3 hardware testing. Operation with this
exact UE0149 module still needs physical validation. See
[Board Operation](../../../tools/product-reference/chapters/05-board-operation.md)
for the full wiring table and checks.
