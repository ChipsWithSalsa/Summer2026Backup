// Automatically generated .v file on Thu Feb  5 16:09:02 2026
//

module vsar_logic ( in, fs, clk, out ) ;
// You will probably want to flush out the nature of these port declarations:


   parameter resolution = 3;




   input reg in;
   input fs;
   input clk;
   output reg [resolution-1:0] out;

   integer pulse_count = 0;

   always @(posedge fs or negedge fs)
      pulse_count = 0;

   // Implement the module here
   always @(negedge clk)begin

   pulse_count = pulse_count+1;

   case(pulse_count)
      1: begin
         out <= 3'b100;
      end
      2: begin
         out[2] <= in;
         out[1] <= 1;
      end
      3: begin
         out[1] <= in;
         out[0] <= 1;
         //pulse_count = 0;
      end
      //default: out=3'b111;

   endcase

   end

endmodule
