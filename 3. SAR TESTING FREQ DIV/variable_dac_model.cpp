// Automatically generated C++ file on Thu Oct 16 15:32:27 2025
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD variable_dac_model.cpp kernel32.lib


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
#undef IN1
#undef IN0
#undef OUT
#undef CLK

extern "C" __declspec(dllexport) void variable_dac_model(void **opaque, double t, union uData *data)
{
   double        CLK = data[0].d ; // input
   unsigned char IN = data[1].uc; // input
   double       &OUT = data[2].d ; // output

// Implement module evaluation code here:


   const int resolution = 8;
   const int hold_time = 3;  //holds for specified number of pulses
   const double vref = 5.0;

   static int last_clk = 0;
   static int pulse_count = 0;
   static double held_value = 0;

   static bool clk_edge_armed = true;
   static bool clk_redge_armed = true;

   bool clk_fedge = false;
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

   if (clk_fedge)
   {
      pulse_count++;

         if(pulse_count==3)
         {
            int digital_value = static_cast<int>(IN);
            held_value = vref * (static_cast<double>(digital_value) / (resolution - 1));
            pulse_count =0;
         }

   }

   OUT = held_value;

   last_clk = CLK;

}
