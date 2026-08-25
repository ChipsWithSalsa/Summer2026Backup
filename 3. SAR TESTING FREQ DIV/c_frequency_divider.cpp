// Automatically generated C++ file on Wed Feb 18 19:58:43 2026
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD -o c_frequency_divider.cpp kernel32.lib


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

#include <cmath>

// 1. Create a memory structure to hold our state
struct DividerState {
    bool last_clk;
    int edge_count;
    double current_out;
};

int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

#undef OUT
#undef IN

extern "C" __declspec(dllexport) void c_frequency_divider(void **opaque, double t, union uData *data)
{
    double  IN  = data[0].d; // Input clock from your Ring Oscillator
    double &OUT = data[1].d; // Divided output clock

    // 2. Initialize memory on the very first time step of the simulation
    if (*opaque == nullptr) {
        DividerState* state = new DividerState;
        state->last_clk = false;
        state->edge_count = 0;
        state->current_out = 0.0;
        *opaque = (void*)state;
    }

    // Cast the opaque pointer back to our structure so we can use it
    DividerState* state = (DividerState*)(*opaque);

    // Define our logic threshold (1.65V is exactly half of 3.3V)
    bool current_clk = (IN > 1.65);

    // 3. Rising Edge Detector
    if (current_clk == true && state->last_clk == false) {
        state->edge_count++;

        // 4. Toggle Logic (Divide by 6 means we toggle the output every 3 rising edges)
        if (state->edge_count >= 3) {
            if (state->current_out > 1.65) {
                state->current_out = 0.0; // Toggle LOW
            } else {
                state->current_out = 3.3; // Toggle HIGH
            }
            state->edge_count = 0; // Reset the counter
        }
    }

    // 5. Save the current clock state so we can compare it on the next time step
    state->last_clk = (IN > 1.65);

    // Output the voltage
    OUT = state->current_out;
}
