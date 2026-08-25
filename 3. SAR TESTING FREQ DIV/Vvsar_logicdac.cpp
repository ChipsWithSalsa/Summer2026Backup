// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvsar_logicdac.h"
#include "Vvsar_logicdac__Syms.h"

//============================================================
// Constructors

Vvsar_logicdac::Vvsar_logicdac(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vvsar_logicdac__Syms(_vcontextp__, _vcname__, this))
    , fs(vlSymsp->TOP.fs)
    , clk(vlSymsp->TOP.clk)
    , in(vlSymsp->TOP.in)
    , out2(vlSymsp->TOP.out2)
    , out2_bar(vlSymsp->TOP.out2_bar)
    , out1(vlSymsp->TOP.out1)
    , out1_bar(vlSymsp->TOP.out1_bar)
    , out0(vlSymsp->TOP.out0)
    , out0_bar(vlSymsp->TOP.out0_bar)
    , rootp(&(vlSymsp->TOP))
{
}

//Vvsar_logicdac::Vvsar_logicdac(const char* _vcname__)
//    : Vvsar_logicdac(nullptr, _vcname__)
//{
//}

Vvsar_logicdac::Vvsar_logicdac(const char* _vcname__)
   : vlSymsp(new Vvsar_logicdac__Syms(nullptr, _vcname__, this))
   , fs(vlSymsp->TOP.fs)
   , clk(vlSymsp->TOP.clk)
   , in(vlSymsp->TOP.in)
   , out2(vlSymsp->TOP.out2)
   , out2_bar(vlSymsp->TOP.out2_bar)
   , out1(vlSymsp->TOP.out1)
   , out1_bar(vlSymsp->TOP.out1_bar)
   , out0(vlSymsp->TOP.out0)
   , out0_bar(vlSymsp->TOP.out0_bar)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vvsar_logicdac::~Vvsar_logicdac() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vvsar_logicdac____eval_initial(Vvsar_logicdac_* vlSelf);
void Vvsar_logicdac____eval_settle(Vvsar_logicdac_* vlSelf);
void Vvsar_logicdac____eval(Vvsar_logicdac_* vlSelf);
#ifdef VL_DEBUG
void Vvsar_logicdac____eval_debug_assertions(Vvsar_logicdac_* vlSelf);
#endif  // VL_DEBUG
void Vvsar_logicdac____final(Vvsar_logicdac_* vlSelf);

static void _eval_initial_loop(Vvsar_logicdac__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vvsar_logicdac____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vvsar_logicdac____eval_settle(&(vlSymsp->TOP));
        Vvsar_logicdac____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vvsar_logicdac::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvsar_logicdac::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvsar_logicdac____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vvsar_logicdac____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vvsar_logicdac::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vvsar_logicdac::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vvsar_logicdac::final() {
    Vvsar_logicdac____final(&(vlSymsp->TOP));
}
