// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvflopnew.h for the primary calling header

#include "verilated.h"

#include "Vvflopnew_.h"
#include "Vvflopnew__Syms.h"

void Vvflopnew____ctor_var_reset(Vvflopnew_* vlSelf);

Vvflopnew_::Vvflopnew_(Vvflopnew__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vvflopnew____ctor_var_reset(this);
}

void Vvflopnew_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vvflopnew_::~Vvflopnew_() {
}
