// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvclocked_comparator.h for the primary calling header

#include "verilated.h"

#include "Vvclocked_comparator_.h"
#include "Vvclocked_comparator__Syms.h"

void Vvclocked_comparator____ctor_var_reset(Vvclocked_comparator_* vlSelf);

Vvclocked_comparator_::Vvclocked_comparator_(Vvclocked_comparator__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vvclocked_comparator____ctor_var_reset(this);
}

void Vvclocked_comparator_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vvclocked_comparator_::~Vvclocked_comparator_() {
}
