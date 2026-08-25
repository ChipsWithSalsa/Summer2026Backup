// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvclocked_comparator.h"
#include "Vvclocked_comparator__Syms.h"

//============================================================
// Constructors

Vvclocked_comparator::Vvclocked_comparator(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vvclocked_comparator__Syms(_vcontextp__, _vcname__, this))
    , clk(vlSymsp->TOP.clk)
    , out(vlSymsp->TOP.out)
    , pos_in(vlSymsp->TOP.pos_in)
    , neg_in(vlSymsp->TOP.neg_in)
    , rootp(&(vlSymsp->TOP))
{
}

//Vvclocked_comparator::Vvclocked_comparator(const char* _vcname__)
//    : Vvclocked_comparator(nullptr, _vcname__)
//{
//}

Vvclocked_comparator::Vvclocked_comparator(const char* _vcname__)
   : vlSymsp(new Vvclocked_comparator__Syms(nullptr, _vcname__, this))
   , clk(vlSymsp->TOP.clk)
   , out(vlSymsp->TOP.out)
   , pos_in(vlSymsp->TOP.pos_in)
   , neg_in(vlSymsp->TOP.neg_in)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vvclocked_comparator::~Vvclocked_comparator() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vvclocked_comparator____eval_initial(Vvclocked_comparator_* vlSelf);
void Vvclocked_comparator____eval_settle(Vvclocked_comparator_* vlSelf);
void Vvclocked_comparator____eval(Vvclocked_comparator_* vlSelf);
#ifdef VL_DEBUG
void Vvclocked_comparator____eval_debug_assertions(Vvclocked_comparator_* vlSelf);
#endif  // VL_DEBUG
void Vvclocked_comparator____final(Vvclocked_comparator_* vlSelf);

static void _eval_initial_loop(Vvclocked_comparator__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vvclocked_comparator____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vvclocked_comparator____eval_settle(&(vlSymsp->TOP));
        Vvclocked_comparator____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vvclocked_comparator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvclocked_comparator::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvclocked_comparator____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vvclocked_comparator____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vvclocked_comparator::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vvclocked_comparator::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vvclocked_comparator::final() {
    Vvclocked_comparator____final(&(vlSymsp->TOP));
}
