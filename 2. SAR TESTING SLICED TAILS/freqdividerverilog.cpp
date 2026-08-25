// Automatically generated C++ file on Sun Aug 23 17:43:24 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o freqdividerverilog.cpp Vfreqdividerverilog*.cpp verilated.lib kernel32.lib
//
// The intended design of the Verilog interface is such that this
// file should not need editing unless you change the symbol.

#include <verilated.h>
#include "Vfreqdividerverilog.h"

extern "C" __declspec(dllexport) void Destroy(Vfreqdividerverilog *instance)
{
   if(instance)
      delete(instance);
}

extern "C" __declspec(dllexport) void freqdividerverilog(Vfreqdividerverilog **instance, double t, union uData *data)
{
   if(!*instance)
      *instance = new Vfreqdividerverilog;
   (*instance)->clk = data[0].b;

   (*instance)->eval();

   data[1].b = (*instance)->clkout;
}
