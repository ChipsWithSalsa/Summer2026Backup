// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vparallel_comp_controller.h"
#include "Vparallel_comp_controller__Syms.h"

//============================================================
// Constructors

Vparallel_comp_controller::Vparallel_comp_controller(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp(new Vparallel_comp_controller__Syms(_vcontextp__, _vcname__, this))
    , low_trip(vlSymsp->TOP.low_trip)
    , sel(vlSymsp->TOP.sel)
    , high_trip(vlSymsp->TOP.high_trip)
    , clk_nmos(vlSymsp->TOP.clk_nmos)
    , clk_pmos(vlSymsp->TOP.clk_pmos)
    , pmos_q(vlSymsp->TOP.pmos_q)
    , nmos_q(vlSymsp->TOP.nmos_q)
    , nmos_boost_clk(vlSymsp->TOP.nmos_boost_clk)
    , pmos_boost_clk(vlSymsp->TOP.pmos_boost_clk)
    , final_data(vlSymsp->TOP.final_data)
    , rootp(&(vlSymsp->TOP))
{
}

//Vparallel_comp_controller::Vparallel_comp_controller(const char* _vcname__)
//    : Vparallel_comp_controller(nullptr, _vcname__)
//{
//}

Vparallel_comp_controller::Vparallel_comp_controller(const char* _vcname__)
   : vlSymsp(new Vparallel_comp_controller__Syms(nullptr, _vcname__, this))
   , low_trip(vlSymsp->TOP.low_trip)
   , sel(vlSymsp->TOP.sel)
   , high_trip(vlSymsp->TOP.high_trip)
   , clk_nmos(vlSymsp->TOP.clk_nmos)
   , clk_pmos(vlSymsp->TOP.clk_pmos)
   , pmos_q(vlSymsp->TOP.pmos_q)
   , nmos_q(vlSymsp->TOP.nmos_q)
   , nmos_boost_clk(vlSymsp->TOP.nmos_boost_clk)
   , pmos_boost_clk(vlSymsp->TOP.pmos_boost_clk)
   , final_data(vlSymsp->TOP.final_data)
   , rootp(&(vlSymsp->TOP))
{
}

//============================================================
// Destructor

Vparallel_comp_controller::~Vparallel_comp_controller() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vparallel_comp_controller____eval_initial(Vparallel_comp_controller_* vlSelf);
void Vparallel_comp_controller____eval_settle(Vparallel_comp_controller_* vlSelf);
void Vparallel_comp_controller____eval(Vparallel_comp_controller_* vlSelf);
#ifdef VL_DEBUG
void Vparallel_comp_controller____eval_debug_assertions(Vparallel_comp_controller_* vlSelf);
#endif  // VL_DEBUG
void Vparallel_comp_controller____final(Vparallel_comp_controller_* vlSelf);

static void _eval_initial_loop(Vparallel_comp_controller__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vparallel_comp_controller____eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vparallel_comp_controller____eval_settle(&(vlSymsp->TOP));
        Vparallel_comp_controller____eval(&(vlSymsp->TOP));
    } while (0);
}

void Vparallel_comp_controller::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vparallel_comp_controller::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vparallel_comp_controller____eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vparallel_comp_controller____eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vparallel_comp_controller::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vparallel_comp_controller::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vparallel_comp_controller::final() {
    Vparallel_comp_controller____final(&(vlSymsp->TOP));
}
