## **5 Board Operation**

This example uses the
[DevLab_AudioInput library](https://github.com/UNIT-Electronics-MX/unit_devlab_audioinput_library)
to capture the ICS-43434's I²S output as signed 16-bit mono PCM on an
ESP32-S3. The library supports ESP32-S3 hardware capture and compiles
for RP2040/RP2350.

### **5.1 Wiring and First Power-Up**

The connection uses a clear acoustic port, a common ground, and a supply
that follows the module power circuit. The board revision and solder
options determine the effective channel selection. The sensor VDD range
describes the microphone pin rather than the module `VIN` input.

| UE0149 signal | Example ESP32-S3 pin | Direction |
|---|---|---|
| `SCK` | GPIO36 | Host I²S bit clock output |
| `WS` | GPIO37 | Host I²S word-select output |
| `SD` | GPIO35 | Host I²S data input |
| `CH` | Board default low | Left time slot |
| `GND` | GND | Common ground |
| `VIN` or `VSYS` | Supply matching the board power circuit | Board power |

The UE0149 circuit pulls `CH` low and selects the left slot by default.
If the assembled board selects right, the sketch uses
`I2S_STD_SLOT_RIGHT`. The GPIO numbers identify host pins. The host board
determines which GPIOs are available for the example.

```{=latex}
\clearpage
```

```{=openxml}
<w:p><w:r><w:br w:type="page"/></w:r></w:p>
```

### **5.2 Arduino Library Example**

The example requires the library in the Arduino sketchbook and an ESP32-S3
with Arduino-ESP32 3.x. The complete
[AudioInputBasicRead sketch](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/software/examples/i2s/cpp_examples/AudioInputBasicRead/AudioInputBasicRead.ino)
reports the absolute peak of each PCM16 block at 115200 baud:

```cpp
#include <DevLab_AudioInput.h>
DevLab_AudioInput microphone;
int16_t samples[256];

void setup() {
  Serial.begin(115200);
  if (!microphone.beginI2S(GPIO_NUM_36, GPIO_NUM_37, GPIO_NUM_35,
                           48000, I2S_STD_SLOT_LEFT)) {
    Serial.println("I2S initialization failed");
    while (true) delay(1000);
  }
  delay(25);
}

void loop() {
  size_t count = microphone.read(samples, 256);
  if (count == 0) return;
  int32_t peak = 0;
  for (size_t i = 0; i < count; ++i) {
    int32_t value = samples[i];
    if (value < 0) value = -value;
    if (value > peak) peak = value;
  }
  Serial.println(peak);
}
```

The Serial Monitor displays the peak at 115200 baud. The peak changes with
sound level and represents digital PCM amplitude. At 48 kHz, a logic
analyzer shows a 3.072 MHz `SCK` and 64 bit clocks per `WS` frame.

### **5.3 Other Capture Examples and Checks**

The library's `examples/I2S` folder also provides `SerialPlotter`,
`SerialStream`, and `ComputerAudio`. Its stock examples drive their
selection pin high and receive the right slot. The UE0149 default selects
the left slot, so the application sets `CH` high or receives the left
slot. The existing
[LegacySerialPlotter sketch](https://github.com/UNIT-Electronics-MX/unit_devlab_i2s_ics_43434_mems_microphone/blob/main/software/examples/i2s/cpp_examples/LegacySerialPlotter/LegacySerialPlotter.ino)
uses the older ESP32 I²S driver directly. It selects the board's
drawn left slot and is retained as an experimental legacy sketch.

If initialization fails, the host configuration checks the Arduino core
version and GPIO availability. If samples remain near zero, the signal
check covers module power, `SCK`, `WS`, `SD`, and the selected slot
relative to `CH`. If output clips or is noisy, the check covers the
conversion shift, supply, wiring, and acoustic port.
