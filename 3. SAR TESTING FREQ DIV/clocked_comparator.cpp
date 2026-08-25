// Clocked Comparator for 5V logic
// Triggered on rising edge of clock

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

#undef Out
#undef Neg_In
#undef Pos_In
#undef Clk

extern "C" __declspec(dllexport) void clocked_comparator(void **opaque, double t, union uData *data)
{
    double Neg_In = data[0].d;  // inverting input
    double Pos_In = data[1].d;  // non-inverting input
    double Clk  = data[2].d;  // clock input
    double &Out   = data[3].d;  // output

    const double V_threshold = 2.5; // half of 5V
    static double prev_clk1 = 0.0;
    static double latch_value = 0.0;

    bool clk_high = (Clk > V_threshold);
    bool clk_rising = (clk_high && (prev_clk1 <= V_threshold));

    if (clk_high) {
        // Only sample inputs on rising edge
        if (clk_rising) {
            if (Pos_In > Neg_In)
                latch_value = 5.0; // HIGH
            else
                latch_value = 0.0; // LOW
        }
    } else {
        // When clock is low, output should go LOW
        latch_value = 0.0;
    }

    Out = latch_value;

    prev_clk1 = Clk;
}
