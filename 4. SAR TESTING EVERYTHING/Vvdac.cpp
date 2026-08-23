// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvdac.h"
#include "Vvdac__Syms.h"

//============================================================
// Constructors

Vvdac::Vvdac(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vvdac__Syms(_vcontextp__, _vcname__, this))
    , fs(vlSymsp->TOP.fs)
    , clk(vlSymsp->TOP.clk)
    , in(vlSymsp->TOP.in)
    , out(vlSymsp->TOP.out)
    , rootp(&(vlSymsp->TOP))
{
}

//Vvdac::Vvdac(const char* _vcname__)
//    : Vvdac(nullptr, _vcname__)
//{
//}

Vvdac::Vvdac(const char* _vcname__)
   : vlSymsp(new Vvdac__Syms(nullptr, _vcname__, this))
   , fs(vlSymsp->TOP.fs)
   , clk(vlSymsp->TOP.clk)
   , in(vlSymsp->TOP.in)
   , out(vlSymsp->TOP.out)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vvdac::~Vvdac() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vvdac____eval_initial(Vvdac_* vlSelf);
void Vvdac____eval_settle(Vvdac_* vlSelf);
void Vvdac____eval(Vvdac_* vlSelf);
#ifdef VL_DEBUG
void Vvdac____eval_debug_assertions(Vvdac_* vlSelf);
#endif  // VL_DEBUG
void Vvdac____final(Vvdac_* vlSelf);

static void _eval_initial_loop(Vvdac__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vvdac____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vvdac____eval_settle(&(vlSymsp->TOP));
        Vvdac____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vvdac::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvdac::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvdac____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vvdac____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vvdac::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vvdac::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vvdac::final() {
    Vvdac____final(&(vlSymsp->TOP));
}
