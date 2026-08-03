## **2 Electrical Characteristics**

### **2.1 Currently Documented Values**

| Symbol / parameter | Description | Value | Scope |
|---|---|---:|---|
| VDD | ICS-43434 microphone supply | 1.62 to 3.63 V | Microphone pin |
| ADC output | Digital sample width | 24 bit | Microphone I²S output |
| SNR | Signal-to-noise ratio | 64 dBA typical | Microphone characteristic |
| Frequency response | Stated audio band | 60 Hz to 20 kHz | Local microphone reference |
| Sensitivity tolerance | Unit-to-unit tolerance | ±1 dB | Microphone characteristic |
| VREG | U3 regulated output | 3.3 V nominal | BOM identification |

The allowed voltage at the module's `VIN` pin and the electrical behavior of
`VSYS` have not been verified from a released schematic. Do not substitute the
microphone VDD range or the AP2112K component rating for a module input rating.

### **2.2 Electrical Precautions**

- Connect `GND` between the host and module before applying power or clocks.
- Drive `SCK`, `WS`, and `CH` only within the validated logic domain; the
  module-level input thresholds remain pending.
- Do not drive `SD`; it is an output from the microphone.
- Keep the bottom acoustic port free from debris, flux, adhesive, and enclosure
  pressure.
- Confirm `VIN`, `VSYS`, and JST supply behavior on the schematic or physical
  board before first power-up.
