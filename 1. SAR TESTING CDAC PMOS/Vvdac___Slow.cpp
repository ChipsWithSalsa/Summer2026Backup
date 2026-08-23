// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvdac.h for the primary calling header

#include "verilated.h"

#include "Vvdac_.h"
#include "Vvdac__Syms.h"

void Vvdac____ctor_var_reset(Vvdac_* vlSelf);

Vvdac_::Vvdac_(Vvdac__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vvdac____ctor_var_reset(this);
}

void Vvdac_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vvdac_::~Vvdac_() {
}
