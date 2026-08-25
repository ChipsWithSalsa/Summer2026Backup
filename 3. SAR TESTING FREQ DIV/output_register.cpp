// Automatically generated C++ file on Tue Jan 27 16:46:38 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o output_register.cpp kernel32.lib


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
#undef OUT
#undef IN0
#undef IN1
#undef IN2

extern "C" __declspec(dllexport) void output_register(void **opaque, double t, union uData *data)
{
   double         IN0 = data[0].b ; // input
   double         IN1 = data[1].b ; // input
   double         IN2 = data[2].b ; // input
   double &OUT = data[3].d; // output

// Implement module evaluation code here:

const double VTH = 2.5; // comparator threshold
   const int resolution = 3; // 3-bit SAR

   int b2 = (IN2) ? 1 : 0;
   int b1 = (IN1) ? 1 : 0;
   int b0 = (IN0) ? 1 : 0;

   OUT = 4*b2 + 2*b1 + 1*b0;



}
