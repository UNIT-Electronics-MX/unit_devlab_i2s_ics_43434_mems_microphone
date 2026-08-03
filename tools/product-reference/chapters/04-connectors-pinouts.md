## **4 Connectors and Pinout**

### **4.1 Edge Connections**

| Board label | Direction | Function |
|---|---|---|
| `VSYS` | Power | Module system rail |
| `VIN` | Input | Module supply input; allowed range pending |
| `GND` | Power | Common ground |
| `CH` | Input | Left/right I²S channel selection |
| `SCK` | Input | I²S serial bit clock |
| `WS` | Input | I²S word select / left-right clock |
| `SD` | Output | I²S serial audio data |

### **4.2 Six-Position JST-SH Connector**

The V1.0 top artwork labels the connector signals, from the leftmost contact in
the rendered top view, as `GND`, `VSYS`, `CH`, `WS`, `SD`, and `SCK`. Verify
orientation on the physical board before making a cable; the present document
does not assign connector pin numbers.

### **4.3 Solder Options**

The bottom artwork identifies `L/R`, `LED ON`, and `JST VCC` options. Their
default copper states and exact circuit connections are pending schematic
verification.
