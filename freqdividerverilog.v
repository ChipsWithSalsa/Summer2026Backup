// Automatically generated .v file on Sun Aug 23 17:33:57 2026
//

module freqdividerverilog (input clk, output reg clkout);
// You will probably want to flush out the nature of these port declarations:
   parameter NBITS = 3;
   reg [3:0] cnt = 0;
   initial clkout = 0;
   always @(posedge clk)
      if (cnt == NBITS - 1) begin
         cnt    <= 0;
         clkout <= ~clkout;
      end else
         cnt <= cnt + 1;

endmodule
