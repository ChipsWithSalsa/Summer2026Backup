// Automatically generated .v file on Thu Feb 12 17:17:44 2026
//

module vdac ( in, clk, fs, out ) ;
    input real in;
    input clk;
    input fs;
    output real out;

    integer pulse_count = 0;
    integer resolution = 8;
    real vref = 3.3;

    // Only update the analog output the exact moment the conversion finishes
    always @(negedge clk) begin
        pulse_count = pulse_count + 1;
        if(pulse_count==2) begin
           out = vref*in/(resolution-1);
        end
    end
    always @(posedge fs or negedge fs)
       pulse_count=0;

endmodule
