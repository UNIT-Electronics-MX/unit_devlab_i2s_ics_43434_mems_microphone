## **3 Functional Overview**

### **3.1 Functional Block Diagram** {.section-page}

![UE0149 I²S ICS-43434 microphone module block diagram.](hardware/resources/external/i2s_ics_43434_mems_microphone.png){width=6.3in}

The diagram summarizes the microphone signal path, channel control, and
board power section. The host drives `SCK` and `WS` toward the
microphone; `SD` carries audio from the microphone to the host.
Section 2 specifies the sensor supply range.

### **3.2 Signal Path**

Sound enters the ICS-43434 through its bottom acoustic port. The MEMS
signal passes through conditioning, an ADC, decimation and anti-aliasing
filters, then leaves as signed 24-bit, two's-complement I²S data on
`SD`. The host supplies `SCK` (bit clock) and `WS` (word select);
the sensor is an I²S slave and needs no separate master-clock pin.
The [manufacturer datasheet](hardware/resources/external/DS-000069-ICS-43434-v1.2.pdf),
DS-000069 revision 1.2, describes this path in “Theory of Operation.”

### **3.3 I²S Frame and Channel**

Each stereo frame contains exactly 64 `SCK` cycles: 32 per channel.
The sensor transmits 24 valid bits, most significant bit first, starting
one bit-clock after the `WS` transition. A host normally receives
32-bit slots and converts the signed sample to its application format.
Board `CH` reaches the microphone `LR` input: low selects the left
slot after the falling `WS` edge, and high selects the right slot after
the rising edge. The host firmware receives the selected slot.

The microphone tri-states `SD` after its 24th bit. A stereo pair shares
`SCK`, `WS`, and `SD` when one microphone selects left and the other right.
For that arrangement, the datasheet specifies a pull-down on the shared
`SD` line (100 kΩ is sufficient). The UE0149 circuit includes a 10 kΩ
pull-down on `CH`, so the default channel is **left**. The assembled
solder option determines the effective selection.

### **3.4 Sample-Rate Modes**

The sensor selects its power state from `WS` frequency (the sample rate):

| Sensor mode | `WS` frequency | Typical sensor current | Typical SNR |
|---|---:|---:|---:|
| Standby/sleep | Below 3.125 kHz | 12 µA | No data output |
| Low power | 6.25–18.75 kHz | 230 µA | 64 dBA |
| High performance | 23–51.6 kHz | 490 µA | 65 dBA |

The table lists **sensor** characteristics from DS-000069. Rates between
the listed ranges lie outside the specified operating modes. A 48 kHz, 64-clock frame
uses a 3.072 MHz bit clock and falls in high-performance mode. The
microphone takes up to 20 ms to reach settled output after power-up
or wake-up. In standby, the host holds both `SCK` and `WS` low.

### **3.5 Power and Board Circuit**

The circuit routes `VIN` through an AP2112K-3.3V regulator
and a Schottky diode toward `VSYS`, which powers the microphone VDD
pin. A 100 nF capacitor decouples the microphone, and the board has an
orange power LED. The ICS-43434 VDD operating range of 1.65–3.63 V
applies at the sensor pin; the module supply path determines the voltage
at that pin. The host holds I²S clocks low while the sensor is unpowered.

![](hardware/resources/unit_btm_v_1_1_0_ue0149_devlab_i2s_ics_43434_mems_microphone_3d.png){width=5.4in}
