```{=latex}
\clearpage
```

```{=openxml}
<w:p><w:r><w:br w:type="page"/></w:r></w:p>
```

## **4 Connectors and Pinout**

### **4.1 Pinout Diagram** {.section-page}

![](tools/product-reference/assets/ue0149-pinout.png){width=5.0in}

```{=latex}
\clearpage
```

```{=openxml}
<w:p><w:r><w:br w:type="page"/></w:r></w:p>
```

### **4.2 Edge Connections**

| Board label | Direction | Function |
|---|---|---|
| `VSYS` | Power | Module system rail |
| `VIN` | Input | Regulator input |
| `GND` | Power | Common ground |
| `CH` | Input | Left/right I²S channel selection |
| `SCK` | Input | I²S serial bit clock |
| `WS` | Input | I²S word select / left-right clock |
| `SD` | Output | I²S serial audio data |

### **4.3 Six-Position JST-SH Connector**

The V1.0 top artwork labels the connector signals, from the leftmost contact in
the rendered top view, as `GND`, `VSYS`, `CH`, `WS`, `SD`, and `SCK`.
The board pinout shows signal order by physical position.

### **4.4 Solder Options**

The bottom artwork identifies `L/R`, `LED ON`, and `JST VCC` options.
The circuit pulls `CH` low through 10 kΩ and selects the left channel by
default. The assembled solder bridges determine channel selection, LED
operation, and JST supply routing.
