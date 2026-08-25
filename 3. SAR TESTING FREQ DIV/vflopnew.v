// Automatically generated .v file on Thu Feb 12 17:07:36 2026
//

module vflopnew ( d, clk, q ) ;
// You will probably want to flush out the nature of these port declarations:
   input reg d;
   input clk;
   output reg q;

   // Implement the module here
   always @(posedge clk)
      q<=d;


endmodule
