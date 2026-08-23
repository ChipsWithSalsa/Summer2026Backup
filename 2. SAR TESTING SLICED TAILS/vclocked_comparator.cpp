// Automatically generated C++ file on Thu Feb  5 14:02:55 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o vclocked_comparator.cpp Vvclocked_comparator*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vvclocked_comparator.h"

extern "C" __declspec(dllexport) void Destroy(Vvclocked_comparator *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void vclocked_comparator(Vvclocked_comparator **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vvclocked_comparator;
   (*instance)->clk = data[0].b;
   (*instance)->pos_in = data[1].d;
   (*instance)->neg_in = data[2].d;

   (*instance)->eval();

   data[3].b = (*instance)->out;
}
