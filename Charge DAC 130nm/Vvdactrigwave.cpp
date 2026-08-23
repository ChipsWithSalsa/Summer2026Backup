// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvdactrigwave.h"
#include "Vvdactrigwave__Syms.h"

//============================================================
// Constructors

Vvdactrigwave::Vvdactrigwave(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vvdactrigwave__Syms(_vcontextp__, _vcname__, this))
    , clk(vlSymsp->TOP.clk)
    , out2(vlSymsp->TOP.out2)
    , out2_bar(vlSymsp->TOP.out2_bar)
    , out1(vlSymsp->TOP.out1)
    , out1_bar(vlSymsp->TOP.out1_bar)
    , out0(vlSymsp->TOP.out0)
    , out0_bar(vlSymsp->TOP.out0_bar)
    , rootp(&(vlSymsp->TOP))
{
}

//Vvdactrigwave::Vvdactrigwave(const char* _vcname__)
//    : Vvdactrigwave(nullptr, _vcname__)
//{
//}

Vvdactrigwave::Vvdactrigwave(const char* _vcname__)
   : vlSymsp(new Vvdactrigwave__Syms(nullptr, _vcname__, this))
   , clk(vlSymsp->TOP.clk)
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

Vvdactrigwave::~Vvdactrigwave() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vvdactrigwave____eval_initial(Vvdactrigwave_* vlSelf);
void Vvdactrigwave____eval_settle(Vvdactrigwave_* vlSelf);
void Vvdactrigwave____eval(Vvdactrigwave_* vlSelf);
#ifdef VL_DEBUG
void Vvdactrigwave____eval_debug_assertions(Vvdactrigwave_* vlSelf);
#endif  // VL_DEBUG
void Vvdactrigwave____final(Vvdactrigwave_* vlSelf);

static void _eval_initial_loop(Vvdactrigwave__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vvdactrigwave____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vvdactrigwave____eval_settle(&(vlSymsp->TOP));
        Vvdactrigwave____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vvdactrigwave::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvdactrigwave::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvdactrigwave____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vvdactrigwave____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vvdactrigwave::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vvdactrigwave::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vvdactrigwave::final() {
    Vvdactrigwave____final(&(vlSymsp->TOP));
}
