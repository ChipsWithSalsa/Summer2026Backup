// Automatically generated C++ file on Thu Feb  5 17:33:16 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o vsar_logic.cpp Vvsar_logic*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vvsar_logic.h"

extern "C" __declspec(dllexport) void Destroy(Vvsar_logic *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void vsar_logic(Vvsar_logic **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vvsar_logic;
   (*instance)->in = data[0].b;
   (*instance)->fs = data[1].b;
   (*instance)->clk = data[2].b;

   (*instance)->eval();

   data[3].uc = (*instance)->out;
}
