// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfrequency_divider.h for the primary calling header

#include "verilated.h"

#include "Vfrequency_divider_.h"
#include "Vfrequency_divider__Syms.h"

void Vfrequency_divider____ctor_var_reset(Vfrequency_divider_* vlSelf);

Vfrequency_divider_::Vfrequency_divider_(Vfrequency_divider__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vfrequency_divider____ctor_var_reset(this);
}

void Vfrequency_divider_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vfrequency_divider_::~Vfrequency_divider_() {
}
