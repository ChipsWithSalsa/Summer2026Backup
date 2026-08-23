// Automatically generated C++ file on Thu Feb 12 17:08:10 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o vflopnew.cpp Vvflopnew*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vvflopnew.h"

extern "C" __declspec(dllexport) void Destroy(Vvflopnew *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void vflopnew(Vvflopnew **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vvflopnew;
   (*instance)->d = data[0].b;
   (*instance)->clk = data[1].b;

   (*instance)->eval();

   data[2].b = (*instance)->q;
}
