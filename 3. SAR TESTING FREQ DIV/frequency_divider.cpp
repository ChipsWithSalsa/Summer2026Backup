// Automatically generated C++ file on Wed Feb 18 19:09:03 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o frequency_divider.cpp Vfrequency_divider*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vfrequency_divider.h"

extern "C" __declspec(dllexport) void Destroy(Vfrequency_divider *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void frequency_divider(Vfrequency_divider **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vfrequency_divider;
   (*instance)->in = data[0].d;

   (*instance)->eval();

   data[1].d = (*instance)->out;
}
