// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvsar_logic.h"
#include "Vvsar_logic__Syms.h"

//============================================================
// Constructors

Vvsar_logic::Vvsar_logic(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vvsar_logic__Syms(_vcontextp__, _vcname__, this))
    , fs(vlSymsp->TOP.fs)
    , clk(vlSymsp->TOP.clk)
    , in(vlSymsp->TOP.in)
    , out(vlSymsp->TOP.out)
    , rootp(&(vlSymsp->TOP))
{
}

//Vvsar_logic::Vvsar_logic(const char* _vcname__)
//    : Vvsar_logic(nullptr, _vcname__)
//{
//}

Vvsar_logic::Vvsar_logic(const char* _vcname__)
   : vlSymsp(new Vvsar_logic__Syms(nullptr, _vcname__, this))
   , fs(vlSymsp->TOP.fs)
   , clk(vlSymsp->TOP.clk)
   , in(vlSymsp->TOP.in)
   , out(vlSymsp->TOP.out)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vvsar_logic::~Vvsar_logic() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vvsar_logic____eval_initial(Vvsar_logic_* vlSelf);
void Vvsar_logic____eval_settle(Vvsar_logic_* vlSelf);
void Vvsar_logic____eval(Vvsar_logic_* vlSelf);
#ifdef VL_DEBUG
void Vvsar_logic____eval_debug_assertions(Vvsar_logic_* vlSelf);
#endif  // VL_DEBUG
void Vvsar_logic____final(Vvsar_logic_* vlSelf);

static void _eval_initial_loop(Vvsar_logic__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vvsar_logic____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vvsar_logic____eval_settle(&(vlSymsp->TOP));
        Vvsar_logic____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vvsar_logic::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvsar_logic::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvsar_logic____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vvsar_logic____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vvsar_logic::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vvsar_logic::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vvsar_logic::final() {
    Vvsar_logic____final(&(vlSymsp->TOP));
}
