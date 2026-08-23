module vsar_logicdac (
    input wire in,
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
    reg [2:0] pulse_count;

    assign out2 = out[2];
    assign out1 = out[1];
    assign out0 = out[0];
    assign out2_bar = ~out[2];
    assign out1_bar = ~out[1];
    assign out0_bar = ~out[0];

    always @(negedge clk) begin
        if (fs == 1'b1) begin
            // TRACKING PHASE: T&H is closed.
            // Hold CDAC steady at GND (000) so we don't inject charge noise.
            pulse_count <= 3'd0;
            out <= 3'b000;
        end else begin
            // CONVERSION PHASE: T&H is open. Run the bit trials.
            pulse_count <= pulse_count + 3'd1;

            case(pulse_count)
                3'd0: begin
                    // Cycle 1: Put MSB test voltage on the CDAC
                    out <= 3'b100;
                end
                3'd1: begin
                    // Cycle 2: Save the MSB result, put Bit 1 test voltage
                    out[2] <= in;
                    out[1] <= 1'b1;
                end
                3'd2: begin
                    // Cycle 3: Save Bit 1 result, put LSB test voltage
                    out[1] <= in;
                    out[0] <= 1'b1;
                end
                3'd3: begin
                    // Cycle 4: SAVE THE LSB!
                    out[0] <= in;
                end
                default: begin
                    // Cycle 5+: Safely hold the completed word
                    out <= out;
                end
            endcase
        end
    end

endmodule
