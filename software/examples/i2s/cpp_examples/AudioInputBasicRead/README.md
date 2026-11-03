# AudioInputBasicRead

Reads the UE0149's default left I²S slot through
[DevLab_AudioInput](https://github.com/UNIT-Electronics-MX/unit_devlab_audioinput_library).
The library converts the input to mono PCM16 at 48 kHz. The sketch
prints the absolute peak of each 256-sample block at 115200 baud.

## Requirements

- ESP32-S3 board with Arduino-ESP32 3.x
- DevLab_AudioInput installed in the Arduino sketchbook
- UE0149 wired as described in the [I²S example index](../../README.md)

## Run

1. Open [AudioInputBasicRead.ino](AudioInputBasicRead.ino) in Arduino IDE.
2. Select the ESP32-S3 board and upload the sketch.
3. Open Serial Monitor at 115200 baud and make a sound near the microphone.
   The peak values should change with sound level.

The value is a PCM amplitude, not a calibrated sound-pressure level.
If `CH` selects right on the assembled board, use
`I2S_STD_SLOT_RIGHT` in the `beginI2S()` call. Capture with this
exact module has not been independently validated.
