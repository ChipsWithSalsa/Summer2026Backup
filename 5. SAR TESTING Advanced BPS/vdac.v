// Automatically generated .v file on Thu Feb 12 17:17:44 2026
//

module vdac ( in, clk, fs, out ) ;
    input real in;
    input clk;
    input fs;
    output real out;

    integer resolution = 8;
    real vref = 3.3;

    // Only update the analog output the exact moment the conversion finishes
    always @(posedge fs) begin
        out = vref * in / (resolution - 1);
    end

endmodule
