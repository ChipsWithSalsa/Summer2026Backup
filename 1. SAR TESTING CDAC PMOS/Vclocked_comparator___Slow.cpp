// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclocked_comparator.h for the primary calling header

#include "verilated.h"

#include "Vclocked_comparator_.h"
#include "Vclocked_comparator__Syms.h"

void Vclocked_comparator____ctor_var_reset(Vclocked_comparator_* vlSelf);

Vclocked_comparator_::Vclocked_comparator_(Vclocked_comparator__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vclocked_comparator____ctor_var_reset(this);
}

void Vclocked_comparator_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vclocked_comparator_::~Vclocked_comparator_() {
}
