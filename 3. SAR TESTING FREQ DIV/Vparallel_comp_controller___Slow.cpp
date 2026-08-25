// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vparallel_comp_controller.h for the primary calling header

#include "verilated.h"

#include "Vparallel_comp_controller_.h"
#include "Vparallel_comp_controller__Syms.h"

void Vparallel_comp_controller____ctor_var_reset(Vparallel_comp_controller_* vlSelf);

Vparallel_comp_controller_::Vparallel_comp_controller_(Vparallel_comp_controller__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vparallel_comp_controller____ctor_var_reset(this);
}

void Vparallel_comp_controller_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vparallel_comp_controller_::~Vparallel_comp_controller_() {
}
