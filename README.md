# QSPICE

SAR ADC design and simulation work in QSPICE. Each numbered folder is a
snapshot of a test round and carries its own `README.md` index describing the
blocks in it.

| Folder | Focus |
|---|---|
| `1. SAR TESTING CDAC PMOS` | CDAC with PMOS switching |
| `2. SAR TESTING SLICED TAILS` | Sliced tail current comparator |
| `3. SAR TESTING MIDRAIL DIAGNOSIS & FREQ DIV` | Midrail diagnosis, frequency divider |
| `4. SAR TESTING EVERYTHING` | Full integration round |
| `5. SAR TESTING Advanced BPS` | Advanced bootstrap / R-2R / Charge DAC |
| `Charge DAC 130nm` | Charge DAC at 130nm |
| `SKY130_Testing` | Gm/Id characterization against SKY130 |
| `SKY130nm_symbols` | QSPICE symbols for SKY130 devices |

## SKY130 PDK

The PDK is **not** committed here — it is a verbatim copy of a public upstream
repo and would add ~674 MB. To restore `SKY130_PDK/`, download it from:

<https://github.com/google/skywater-pdk-libs-sky130_fd_pr>

and unpack so the path is `SKY130_PDK/skywater-pdk-libs-sky130_fd_pr-main/`.
The symbols in `SKY130nm_symbols/` and the schematics in `SKY130_Testing/`
expect that layout.

## What's tracked

Schematics (`.qsch`), symbols (`.qsym`), the hand-written C++/Verilog behavioral
models, and the compiled `.dll` blocks those schematics load — so a fresh clone
simulates without recompiling.

Not tracked: waveform dumps (`.qraw`, `.qopraw`), Verilator intermediates
(`V*__Syms.*`, `V*___DepSet___*`), and object files. See `.gitignore`.
