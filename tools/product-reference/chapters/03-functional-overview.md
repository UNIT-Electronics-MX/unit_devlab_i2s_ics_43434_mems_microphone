## **3 Functional Overview**

### **3.1 Audio Signal Path**

The ICS-43434 senses pressure at its bottom acoustic port, conditions the MEMS
signal, converts it to digital audio, and places 24-bit samples on `SD`. A host
controller supplies `SCK` and `WS`; no master clock line is exposed by the module.

### **3.2 Channel Selection**

`CH` selects the I²S time slot used by the microphone. A low level selects the
left channel and a high level selects the right channel. Two modules can share
the clock and data timing when their channel selections and data connection are
implemented according to the ICS-43434 application requirements.

### **3.3 Power Section**

The manufacturing BOM identifies an AP2112K-3.3TRG1 regulator, Schottky diode,
decoupling capacitors, orange indicator LED, and associated resistors. The
exact `VIN`/`VSYS` power path and solder-option defaults remain pending until a
released module schematic is available.

![](hardware/resources/unit_btm_v_1_0_0_i2s_ics43434_mems_microphone.png){width=5.4in}
