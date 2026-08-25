// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfreqdividerverilog.h for the primary calling header

#include "verilated.h"

#include "Vfreqdividerverilog_.h"
#include "Vfreqdividerverilog__Syms.h"

void Vfreqdividerverilog____ctor_var_reset(Vfreqdividerverilog_* vlSelf);

Vfreqdividerverilog_::Vfreqdividerverilog_(Vfreqdividerverilog__Syms* symsp, const char* name)
    : VerilatedModule(name)
    , vlSymsp(symsp)
 {
    // Reset structure values
    Vfreqdividerverilog____ctor_var_reset(this);
}

void Vfreqdividerverilog_::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vfreqdividerverilog_::~Vfreqdividerverilog_() {
}
