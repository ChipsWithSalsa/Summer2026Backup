// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvsar_logic.h for the primary calling header

#include "verilated.h"

#include "Vvsar_logic_.h"
#include "Vvsar_logic__Syms.h"

void Vvsar_logic____ctor_var_reset(Vvsar_logic_* vlSelf);

Vvsar_logic_::Vvsar_logic_(Vvsar_logic__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vvsar_logic____ctor_var_reset(this);
}

void Vvsar_logic_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vvsar_logic_::~Vvsar_logic_() {
}
