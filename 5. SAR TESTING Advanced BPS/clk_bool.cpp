// Automatically generated C++ file on Tue Jan 27 14:28:36 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o clk_bool.cpp kernel32.lib


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
#undef IN
#undef OUT

extern "C" __declspec(dllexport) void clk_bool(void **opaque, double t, union uData *data)
{
   double IN  = data[0].d; // input
   bool  &OUT = data[1].b; // output

// Implement module evaluation code here:

   static int last_clk = 0;

      // --- CLOCK FALLING EDGE ---
   if (last_clk >= 2.5 && IN < 2.5)   // actual analog edge
   {
      OUT = 0;
   }
   else if (last_clk <= 2.5 && IN > 2.5)
   {
      OUT = 1;
   }

   last_clk = IN;

}
