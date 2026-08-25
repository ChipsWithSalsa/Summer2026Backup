// Automatically generated .v file on Sun May 17 15:38:28 2026
//

module parallel_comp_controller ( low_trip, sel, high_trip, clk_nmos, clk_pmos, pmos_q, nmos_q, nmos_boost_clk, pmos_boost_clk, final_data ) ;
// You will probably want to flush out the nature of these port declarations:
   input wire low_trip;
   input wire sel;
   input wire high_trip;
   input wire clk_nmos;
   input wire clk_pmos;
   input wire pmos_q;
   input wire nmos_q;
   output wire nmos_boost_clk;
   output wire pmos_boost_clk;
   output wire final_data;

   // Implement the module here
   // 1. The Window Detector
   // XOR is 1 ONLY when sensors disagree (The Midrail Danger Zone)
   wire need_boost = (high_trip ^ low_trip);

   // 2. The Clock Gating (Corrected Polarity)
   // NMOS: Pass analog clock if we NEED boost. Force 0 (OFF) if we don't.
   assign nmos_boost_clk = clk_nmos & need_boost;

   // PMOS: Pass analog clock if we NEED boost. Force 1 (OFF) if we don't.
   assign pmos_boost_clk = clk_pmos | ~need_boost;

   // 3. The 2-to-1 MUX (Corrected Polarity)
   // If sel == 1 (Input is LOW), listen to PMOS. If sel == 0 (Input is HIGH), listen to NMOS.
   assign final_data = sel ? pmos_q : nmos_q;

endmodule
