// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvflopnew.h"
#include "Vvflopnew__Syms.h"

//============================================================
// Constructors

Vvflopnew::Vvflopnew(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vvflopnew__Syms(_vcontextp__, _vcname__, this))
    , clk(vlSymsp->TOP.clk)
    , d(vlSymsp->TOP.d)
    , q(vlSymsp->TOP.q)
    , rootp(&(vlSymsp->TOP))
{
}

//Vvflopnew::Vvflopnew(const char* _vcname__)
//    : Vvflopnew(nullptr, _vcname__)
//{
//}

Vvflopnew::Vvflopnew(const char* _vcname__)
   : vlSymsp(new Vvflopnew__Syms(nullptr, _vcname__, this))
   , clk(vlSymsp->TOP.clk)
   , d(vlSymsp->TOP.d)
   , q(vlSymsp->TOP.q)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vvflopnew::~Vvflopnew() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vvflopnew____eval_initial(Vvflopnew_* vlSelf);
void Vvflopnew____eval_settle(Vvflopnew_* vlSelf);
void Vvflopnew____eval(Vvflopnew_* vlSelf);
#ifdef VL_DEBUG
void Vvflopnew____eval_debug_assertions(Vvflopnew_* vlSelf);
#endif  // VL_DEBUG
void Vvflopnew____final(Vvflopnew_* vlSelf);

static void _eval_initial_loop(Vvflopnew__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vvflopnew____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vvflopnew____eval_settle(&(vlSymsp->TOP));
        Vvflopnew____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vvflopnew::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvflopnew::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvflopnew____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vvflopnew____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vvflopnew::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vvflopnew::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vvflopnew::final() {
    Vvflopnew____final(&(vlSymsp->TOP));
}
