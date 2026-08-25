// Automatically generated C++ file on Wed May 13 04:10:42 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o vsar_logicdac.cpp Vvsar_logicdac*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vvsar_logicdac.h"

extern "C" __declspec(dllexport) void Destroy(Vvsar_logicdac *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void vsar_logicdac(Vvsar_logicdac **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vvsar_logicdac;
   (*instance)->in = data[0].b;
   (*instance)->fs = data[1].b;
   (*instance)->clk = data[2].b;

   (*instance)->eval();

   data[3].b = (*instance)->out2;
   data[4].b = (*instance)->out2_bar;
   data[5].b = (*instance)->out1;
   data[6].b = (*instance)->out1_bar;
   data[7].b = (*instance)->out0;
   data[8].b = (*instance)->out0_bar;
}
