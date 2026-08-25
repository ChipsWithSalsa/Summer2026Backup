// Automatically generated C++ file on Wed Oct  1 20:13:46 2025
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD clockckt.cpp kernel32.lib


union uData
{
   bool b;
   char c;
   unsigned char uc;
   short s;
   unsigned short us;
   int i;
   unsigned int ui;
   float f;
   double d;
   long long int i64;
   unsigned long long int ui64;
   char *str;
   unsigned char *bytes;
};

// int DllMain() must exist and return 1 for a process to load the .DLL
// See https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain for more information.
int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

// #undef pin names lest they collide with names in any header file(s) you might include.
#undef In
#undef Out

#include <cmath>

extern "C" __declspec(dllexport) void clockckt(void **opaque, double t, union uData *data)
{
   double &Out = data[0].d; // output

// Implement module evaluation code here:

    double freq = 2e3;
    double duty_cycle = 0.5;
    double vhigh = 5.0;
    double vlow = 0.0;

    double period = 1.0 / freq;

    double start_delay = 0.25e-3;
    if (t < start_delay) {
        Out = vlow;               // hold LOW until delay expires
        return;
    }

    double position = fmod(t - start_delay, period);

    if (position < duty_cycle * period)
        Out = vhigh;
    else
        Out = vlow;



}
