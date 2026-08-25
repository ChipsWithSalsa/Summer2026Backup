// Automatically generated C++ file on Thu Nov 13 11:14:23 2025
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD output_reg.cpp kernel32.lib

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
int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

// #undef pin names lest they collide with names in any header file(s) you might include.
#undef IN
#undef CLK
#undef OUT

extern "C" __declspec(dllexport) void output_reg(void **opaque, double t, union uData *data)
{
   double         IN1  = data[0].d  ; // input
   double         IN2  = data[0].d  ; // input
   double         IN3  = data[0].d  ; // input
   double         Fs = data[1].d  ; // input
   double        &OUT = data[2].d; // output

   const double VTH = 2.5; // comparator threshold
   const int resolution = 3; // 3-bit SAR

   int MSB = (IN1 > VTH) ? 1 : 0;
   int SSB = (IN2 > VTH) ? 1 : 0;
   int LSB = (IN3 > VTH) ? 1 : 0;

   static long long int held_value = 0;

   // --- FS FALLING EDGE ---
   if (last_Fs >= 2.5 && Fs < 2.5)
   {
      if (Fs_edge_armed)
      {
         Fs_fedge = true;
         Fs_edge_armed = false;
      }
   }
   else if (Fs >= 2.5)
   {
      Fs_edge_armed = true;
   }



}
