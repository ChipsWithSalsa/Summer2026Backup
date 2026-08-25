// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfreqdividerverilog.h"
#include "Vfreqdividerverilog__Syms.h"

//============================================================
// Constructors

Vfreqdividerverilog::Vfreqdividerverilog(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vfreqdividerverilog__Syms(_vcontextp__, _vcname__, this))
    , clk(vlSymsp->TOP.clk)
    , clkout(vlSymsp->TOP.clkout)
    , rootp(&(vlSymsp->TOP))
{
}

//Vfreqdividerverilog::Vfreqdividerverilog(const char* _vcname__)
//    : Vfreqdividerverilog(nullptr, _vcname__)
//{
//}

Vfreqdividerverilog::Vfreqdividerverilog(const char* _vcname__)
   : vlSymsp(new Vfreqdividerverilog__Syms(nullptr, _vcname__, this))
   , clk(vlSymsp->TOP.clk)
   , clkout(vlSymsp->TOP.clkout)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vfreqdividerverilog::~Vfreqdividerverilog() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vfreqdividerverilog____eval_initial(Vfreqdividerverilog_* vlSelf);
void Vfreqdividerverilog____eval_settle(Vfreqdividerverilog_* vlSelf);
void Vfreqdividerverilog____eval(Vfreqdividerverilog_* vlSelf);
#ifdef VL_DEBUG
void Vfreqdividerverilog____eval_debug_assertions(Vfreqdividerverilog_* vlSelf);
#endif  // VL_DEBUG
void Vfreqdividerverilog____final(Vfreqdividerverilog_* vlSelf);

static void _eval_initial_loop(Vfreqdividerverilog__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vfreqdividerverilog____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vfreqdividerverilog____eval_settle(&(vlSymsp->TOP));
        Vfreqdividerverilog____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vfreqdividerverilog::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfreqdividerverilog::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfreqdividerverilog____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vfreqdividerverilog____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vfreqdividerverilog::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vfreqdividerverilog::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vfreqdividerverilog::final() {
    Vfreqdividerverilog____final(&(vlSymsp->TOP));
}
