// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfrequency_divider.h"
#include "Vfrequency_divider__Syms.h"

//============================================================
// Constructors

Vfrequency_divider::Vfrequency_divider(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vfrequency_divider__Syms(_vcontextp__, _vcname__, this))
    , in(vlSymsp->TOP.in)
    , out(vlSymsp->TOP.out)
    , rootp(&(vlSymsp->TOP))
{
}

//Vfrequency_divider::Vfrequency_divider(const char* _vcname__)
//    : Vfrequency_divider(nullptr, _vcname__)
//{
//}

Vfrequency_divider::Vfrequency_divider(const char* _vcname__)
   : vlSymsp(new Vfrequency_divider__Syms(nullptr, _vcname__, this))
   , in(vlSymsp->TOP.in)
   , out(vlSymsp->TOP.out)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vfrequency_divider::~Vfrequency_divider() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vfrequency_divider____eval_initial(Vfrequency_divider_* vlSelf);
void Vfrequency_divider____eval_settle(Vfrequency_divider_* vlSelf);
void Vfrequency_divider____eval(Vfrequency_divider_* vlSelf);
#ifdef VL_DEBUG
void Vfrequency_divider____eval_debug_assertions(Vfrequency_divider_* vlSelf);
#endif  // VL_DEBUG
void Vfrequency_divider____final(Vfrequency_divider_* vlSelf);

static void _eval_initial_loop(Vfrequency_divider__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vfrequency_divider____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vfrequency_divider____eval_settle(&(vlSymsp->TOP));
        Vfrequency_divider____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vfrequency_divider::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfrequency_divider::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfrequency_divider____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vfrequency_divider____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vfrequency_divider::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vfrequency_divider::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vfrequency_divider::final() {
    Vfrequency_divider____final(&(vlSymsp->TOP));
}
