## **9 Appendix**

### **9.1 Technical Basis**

This product reference follows the V1.0 board artwork for visible signal
labels, the UE0149 schematic for circuit connections, and manufacturer
datasheet DS-000069 revision 1.2 for ICS-43434 characteristics.

### **9.2 Document Scope**

- Section 2 lists the ICS-43434 sensor characteristics and the module's
  nominal regulated voltage.
- Sections 3 and 4 describe the signal path, power circuit, and board connections.
- Section 5 shows an ESP32-S3 capture example using the DevLab_AudioInput library.
- Section 6 shows the board views and dimension drawing.
- Section 9.4 presents the complete UE0149 board schematic.

### **9.3 Document Control**

| Field | Value |
|---|---|
| Product | DevLab: I2S ICS-43434 MEMS Microphone |
| Manufacturer part number | UE0149 |
| Hardware artwork covered | V1.0 |
| Product-reference revision | 0.1.0 |
| Publication date | 2026-08-03 |
| Firmware example | ESP32-S3 I²S capture in Section 5 |

```{=latex}
\clearpage
```

```{=openxml}
<w:p><w:r><w:br w:type="page"/></w:r></w:p>
```

### **9.4 Board Schematic** {.section-page}

The UE0149 schematic shows the microphone, power supply, connector,
channel selection, and indicator circuits.

![UE0149 I²S ICS-43434 board schematic.](tools/product-reference/assets/ue0149-schematic.png){width=6.4in}
