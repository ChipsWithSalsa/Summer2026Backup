// Automatically generated C++ file on Fri May 22 21:35:25 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o vdactrigwave.cpp Vvdactrigwave*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vvdactrigwave.h"

extern "C" __declspec(dllexport) void Destroy(Vvdactrigwave *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void vdactrigwave(Vvdactrigwave **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vvdactrigwave;
   (*instance)->clk = data[0].b;

   (*instance)->eval();

   data[1].b = (*instance)->out2;
   data[2].b = (*instance)->out2_bar;
   data[3].b = (*instance)->out1;
   data[4].b = (*instance)->out1_bar;
   data[5].b = (*instance)->out0;
   data[6].b = (*instance)->out0_bar;
}
