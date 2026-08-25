module vsar_logicdac (
    input reg in,
    input wire fs,
    input wire clk,
    output wire out2,
    output wire out2_bar,
    output wire out1,
    output wire out1_bar,
    output wire out0,
    output wire out0_bar
);
    parameter resolution = 3;
    reg [resolution-1:0] out;
    integer pulse_count = 0;

    assign out2 = out[2];
    assign out1 = out[1];
    assign out0 = out[0];
    assign out2_bar = ~out[2];
    assign out1_bar = ~out[1];
    assign out0_bar = ~out[0];

    always @(posedge fs or negedge fs)
        pulse_count = 0;

    always @(negedge clk) begin
        pulse_count = pulse_count + 1;
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
            end
        endcase
    end

endmodule
