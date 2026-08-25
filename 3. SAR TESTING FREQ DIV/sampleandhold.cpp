#include <cmath>

union uData {
   bool b; char c; unsigned char uc; short s; unsigned short us;
   int i; unsigned int ui; float f; double d; long long int i64;
   unsigned long long int ui64; char *str; unsigned char *bytes;
};

int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

#undef In
#undef Out

struct SH_State {
    double last_sample;
    bool prev_clk;
    bool initialized;
    SH_State() : last_sample(0.0), prev_clk(false), initialized(false) {}
};

extern "C" __declspec(dllexport) void sampleandhold(void **opaque, double t, union uData *data)
{
    double  In   = data[0].d;   // input signal
    double  Clk  = data[1].d;   // clock input
    double &Out  = data[2].d;   // output



    // persistent state
    SH_State *state = (SH_State*) *opaque;
    if (!state) {
        state = new SH_State();
        *opaque = state;
    }

    if (!state->initialized) {
        state->last_sample = In;
        state->prev_clk = (Clk > 3.3/2);
        state->initialized = true;
    }

    // detect rising edge
    bool now_high = (Clk > 3.3/2);
    if ((!state->prev_clk && now_high)||(state->prev_clk && !now_high)) {
        state->last_sample = In;  // sample on edge detection
    }

    Out = state->last_sample;    // hold value
    state->prev_clk = now_high;
}
