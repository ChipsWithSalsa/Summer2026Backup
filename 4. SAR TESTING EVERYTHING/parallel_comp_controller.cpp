// Automatically generated C++ file on Sun May 17 21:08:17 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o parallel_comp_controller.cpp Vparallel_comp_controller*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vparallel_comp_controller.h"

extern "C" __declspec(dllexport) void Destroy(Vparallel_comp_controller *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void parallel_comp_controller(Vparallel_comp_controller **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vparallel_comp_controller;
   (*instance)->low_trip = data[0].b;
   (*instance)->sel = data[1].b;
   (*instance)->high_trip = data[2].b;
   (*instance)->clk_nmos = data[3].b;
   (*instance)->clk_pmos = data[4].b;
   (*instance)->pmos_q = data[5].b;
   (*instance)->nmos_q = data[6].b;

   (*instance)->eval();

   data[7].b = (*instance)->nmos_boost_clk;
   data[8].b = (*instance)->pmos_boost_clk;
   data[9].b = (*instance)->final_data;
}
