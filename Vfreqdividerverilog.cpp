// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfreqdividerverilog_x1.h"
#include "Vfreqdividerverilog_x1__Syms.h"

//============================================================
// Constructors

Vfreqdividerverilog_x1::Vfreqdividerverilog_x1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vfreqdividerverilog_x1__Syms(_vcontextp__, _vcname__, this))
    , clk(vlSymsp->TOP.clk)
    , clkout(vlSymsp->TOP.clkout)
    , rootp(&(vlSymsp->TOP))
{
}

//Vfreqdividerverilog_x1::Vfreqdividerverilog_x1(const char* _vcname__)
//    : Vfreqdividerverilog_x1(nullptr, _vcname__)
//{
//}

Vfreqdividerverilog_x1::Vfreqdividerverilog_x1(const char* _vcname__)
   : vlSymsp(new Vfreqdividerverilog_x1__Syms(nullptr, _vcname__, this))
   , clk(vlSymsp->TOP.clk)
   , clkout(vlSymsp->TOP.clkout)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vfreqdividerverilog_x1::~Vfreqdividerverilog_x1() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vfreqdividerverilog_x1____eval_initial(Vfreqdividerverilog_x1_* vlSelf);
void Vfreqdividerverilog_x1____eval_settle(Vfreqdividerverilog_x1_* vlSelf);
void Vfreqdividerverilog_x1____eval(Vfreqdividerverilog_x1_* vlSelf);
#ifdef VL_DEBUG
void Vfreqdividerverilog_x1____eval_debug_assertions(Vfreqdividerverilog_x1_* vlSelf);
#endif  // VL_DEBUG
void Vfreqdividerverilog_x1____final(Vfreqdividerverilog_x1_* vlSelf);

static void _eval_initial_loop(Vfreqdividerverilog_x1__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vfreqdividerverilog_x1____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vfreqdividerverilog_x1____eval_settle(&(vlSymsp->TOP));
        Vfreqdividerverilog_x1____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vfreqdividerverilog_x1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfreqdividerverilog_x1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfreqdividerverilog_x1____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vfreqdividerverilog_x1____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vfreqdividerverilog_x1::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vfreqdividerverilog_x1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vfreqdividerverilog_x1::final() {
    Vfreqdividerverilog_x1____final(&(vlSymsp->TOP));
}
