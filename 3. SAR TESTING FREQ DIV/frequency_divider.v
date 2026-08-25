// Automatically generated .v file on Thu Feb  5 08:33:58 2026
//
module frequency_divider ( in, out ) ;
   input  real in;
   output real out;

   parameter real vhigh      = 5.0;
   parameter real vlow       = 0.0;
   parameter real freq_in    = 2e3;
   parameter real divide_by  = 6.0;
   parameter real duty_cycle = 0.5;

   assign out = (in > ((1.0/freq_in) * divide_by * duty_cycle)) ? vlow : vhigh;

endmodule
