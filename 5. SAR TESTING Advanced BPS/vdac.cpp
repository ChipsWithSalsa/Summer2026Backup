// Automatically generated C++ file on Thu Feb 12 17:25:21 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o vdac.cpp Vvdac*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vvdac.h"

extern "C" __declspec(dllexport) void Destroy(Vvdac *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void vdac(Vvdac **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vvdac;
   (*instance)->in = data[0].d;
   (*instance)->clk = data[1].b;
   (*instance)->fs = data[2].b;

   (*instance)->eval();

   data[3].d = (*instance)->out;
}
