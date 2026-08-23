// Automatically generated C++ file on Wed Oct 29 11:22:04 2025
//
// Non-overlapping clock generator

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

int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

#undef Out_1
#undef Out_2

#include <cmath>

extern "C" __declspec(dllexport) void nonoverlappingclock(void **opaque, double t, union uData *data)
{
   double &Out_1 = data[0].d; // output
   double &Out_2 = data[1].d; // output

   // Clock parameters
   double freq = 2.0e3;
   double vhigh = 5.0;
   double vlow = 0.0;
   double duty = 0.55;
   double off_time_percent = 0.05;

double period = 1.0 / freq;
double off_time = off_time_percent * period;
double on_time = duty * period;

double position = fmod(t, period);

// Out_1
if (position < on_time)
   Out_1 = vhigh;
else
   Out_1 = vlow;

// Out_2
if (position < (on_time + off_time))
   Out_2 = vlow;                         // dead time
else if (position < (2*on_time + off_time))
   Out_2 = vhigh;
else if (position < (2*on_time + 2*off_time))
   Out_2 = vlow;                         // dead time before next cycle
else
   Out_2 = vlow;
}
