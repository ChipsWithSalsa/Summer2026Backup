# Index

**R-2R DAC**
- R-2R DAC commonly known as the resistive ladder DAC. Implemented Using a Resistors and a Voltage Dependent Voltage Source as an Ideal OP Amp  

**Switched Capacitor Resistor**
- A Switched Capacitor is given a specific amount of time to charge, then discharge. (Almost like a bycycle pump) By altering this frequency you can model a packet of charge that is equivilant to the trickle of charge from a resistor. This circuit has a resistance of (period)/capacitance, other archtectures exists: Parallel (This circuit!), Series, Series-Parallel, and Bi-lateral. 
- The average current should be similar to the resistor equivalent, add or minus parasytics, Ron.

**Charge DAC**
- Charge DAC utiizes Binary Weighted Array, this means that each successive bit from 1 has a capacitor 2 to the nth power. A Binary Weighted Resistor Array exists but this switch capacitor design allievates many problems that resistors have.
- NOTE: Only Phi 2 outputs the correct information!!!

# Updates

**Charge DAC**
- Using a Gm amplifier also revealed that the quantization was incorrect for the Charge DAC. Adding a Dummy Capacitor allows this DAC to be end-point exclusive like the R-2R
- 4-bit DAC is currently utilizing the Nonoverlapping clk made by Eammon. Works well, need to parentize.
- Additionally Recent ADC uses a 3bit DAC... not sure whats going to happen with that but i could scale down too. 
- New subcircuit ClockVoltageBooster, It boosts the 3.3V CLK to a 5V CLK. It has same delay as PHI_#_D

**R-2R DAC**
- Added in an OPamp instead of a VDVS for testing. R-2R requires an OP amp and not a GM amp as it has a resistive load.  Charge DAC actually benefits from the GM amp's High Output Impedence.


