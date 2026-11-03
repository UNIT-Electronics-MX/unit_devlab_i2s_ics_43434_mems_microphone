# LegacySerialPlotter

This older sketch uses the ESP32 I²S driver directly. It reads 32-bit
I²S slots at 16 kHz and prints a shifted average of each buffer as
text at 115200 baud for inspection in Serial Plotter. The output is
not a calibrated audio level or a binary PCM stream.

## Requirements

- ESP32-S3 board with an Arduino-ESP32 core that still provides
  `driver/i2s.h`
- UE0149 wired as described in the [I²S example index](../../README.md)

## Run

1. Open [LegacySerialPlotter.ino](LegacySerialPlotter.ino) in Arduino IDE.
2. Select the ESP32-S3 board and upload the sketch.
3. Open Serial Plotter at 115200 baud and inspect the signal.

The sketch drives GPIO34 low on board `CH` and receives the left
slot. If `CH` is changed to right, set `MIC_CHANNEL` to
`MIC_CHANNEL_RIGHT`. This is a legacy driver example; use
AudioInputBasicRead for the shared library API.
