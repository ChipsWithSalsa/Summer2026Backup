// Automatically generated C++ file on Thu Nov 13 09:28:28 2025
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD binary_search.cpp kernel32.lib


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
#undef CLK
#undef IN
#undef Fs

extern "C" __declspec(dllexport) void binary_search(void **opaque, double t, union uData *data)
{
   double         CLK     = data[0].d ; // input
   double         IN      = data[1].d ; // input
   double         Fs      = data[2].d ; // input
   unsigned char &OUT     = data[3].uc; // output

// Implement module evaluation code here:

   const int resolution = 8;
   const int hold_time = 3;  //holds for specified number of pulses
   const double vref = 5.0;

   static int last_clk = 0;
   static int last_Fs = 0;
   static int pulse_count = 0;
   static int pulse_count_reg = 0;
   static unsigned char held_value = 0;
   static int comp1=0;
   static int comp2=0;
   static int comp3=0;

   static unsigned char held_reg = 0;

   static bool clk_edge_armed = true;
   static bool Fs_edge_armed = true;
   static bool clk_redge_armed = true;

   bool clk_fedge = false;
   bool Fs_fedge = false;
   bool clk_redge = false;

      // --- CLOCK FALLING EDGE ---
   if (last_clk >= 2.5 && CLK < 2.5)   // actual analog edge
   {
      if (clk_edge_armed)
      {
         clk_fedge = true;          // fire one-shot
         clk_edge_armed = false;    // disarm until clock rises
      }
   }
   else if (CLK >= 2.5)
   {
      // clock has risen → re-arm for next falling edge
      clk_edge_armed = true;
      clk_redge = true;
   }

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

   if (last_clk <= 2.5 && CLK > 2.5)   // rising analog edge
   {
       if (clk_redge_armed)
       {
          clk_redge = true;          // one-shot trigger
          clk_redge_armed = false;   // disarm until falling edge
       }
   }
   else if (CLK < 2.5)
   {
       clk_redge_armed = true;        // re-arm
   }

   int Comp_IN = (IN) ? 1 : 0;

   if (clk_fedge||Fs_fedge)
   {
      pulse_count++;

         if(pulse_count==1)
         {
            held_value = 4;
         }
         else if(pulse_count==2)
         {
            held_value = (comp1<<2)+2;
         }
         else if(pulse_count==3)
         {
            held_value = (comp1<<2)+(comp2<<1)+1;
         }

   }

   else if(clk_redge)
   {
      if(pulse_count==1)
         {
            comp1=Comp_IN;
         }
         else if(pulse_count==2)
         {
            comp2=Comp_IN;
         }
         else if(pulse_count==3)
         {
            comp3=Comp_IN;
            pulse_count = 0;
            pulse_count_reg = 0;
         }

   }


   OUT = held_value;

   last_clk = CLK;

   last_Fs = Fs;

}
