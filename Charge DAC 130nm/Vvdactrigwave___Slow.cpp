// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvdactrigwave.h for the primary calling header

#include "verilated.h"

#include "Vvdactrigwave_.h"
#include "Vvdactrigwave__Syms.h"

void Vvdactrigwave____ctor_var_reset(Vvdactrigwave_* vlSelf);

Vvdactrigwave_::Vvdactrigwave_(Vvdactrigwave__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vvdactrigwave____ctor_var_reset(this);
}

void Vvdactrigwave_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vvdactrigwave_::~Vvdactrigwave_() {
}
