## **2 Electrical Characteristics**

### **2.1 Electrical Values**

| Symbol / parameter | Description | Value | Scope |
|---|---|---:|---|
| VDD | ICS-43434 microphone supply | 1.65 to 3.63 V | Microphone pin, DS-000069 rev. 1.2 |
| ADC output | Digital sample width | 24 bit | Microphone I²S output |
| SNR | Signal-to-noise ratio | 65 dBA high-performance; 64 dBA low-power, typical | Microphone characteristic |
| Frequency response | Stated audio band | 60 Hz to 20 kHz | EMMIC-ICS43434 reference |
| Sensitivity tolerance | Unit-to-unit tolerance | ±1 dB | Microphone characteristic |
| VREG | AP2112K-3.3 regulated output | 3.3 V nominal | Module regulator |

The sensor VDD range applies at the microphone supply pin. The module
routes `VIN` through its regulator and Schottky diode to `VSYS`, which
supplies the microphone. The sensor VDD range does not specify a module
`VIN` input range.

### **2.2 Electrical Precautions**

- The host and module share a common ground during operation.
- The host drives `SCK`, `WS`, and `CH` within the powered microphone's
  logic domain.
- The microphone drives `SD` toward the host.
- The bottom acoustic port remains clear of debris, flux, adhesive, and
  enclosure pressure.
- The board schematic shows the `VIN` to `VSYS` supply path and the JST
  power connection.
