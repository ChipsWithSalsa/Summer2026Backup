// Automatically generated .v file on Thu Feb  5 13:44:08 2026
//

module vclocked_comparator ( clk, pos_in, neg_in, out ) ;
// You will probably want to flush out the nature of these port declarations:
   input clk;
   input real pos_in;
   input real neg_in;
   output reg out;

   // Implement the module here

always @(posedge clk)begin
   if(pos_in>neg_in)
      out<=1;
   else
      out<=0;
end

endmodule
