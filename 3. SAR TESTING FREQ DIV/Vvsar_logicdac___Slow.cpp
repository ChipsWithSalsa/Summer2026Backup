// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvsar_logicdac.h for the primary calling header

#include "verilated.h"

#include "Vvsar_logicdac_.h"
#include "Vvsar_logicdac__Syms.h"

void Vvsar_logicdac____ctor_var_reset(Vvsar_logicdac_* vlSelf);

Vvsar_logicdac_::Vvsar_logicdac_(Vvsar_logicdac__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vvsar_logicdac____ctor_var_reset(this);
}

void Vvsar_logicdac_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vvsar_logicdac_::~Vvsar_logicdac_() {
}
