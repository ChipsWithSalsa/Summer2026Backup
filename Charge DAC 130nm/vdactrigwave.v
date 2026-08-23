// Debugged, race-condition-free verification module
module vdactrigwave (
    input wire clk,         // Connect directly to your phi_2 clock net
    output wire out2,
    output wire out2_bar,
    output wire out1,
    output wire out1_bar,
    output wire out0,
    output wire out0_bar
);
    parameter resolution = 3;
    reg [resolution-1:0] out;

    // Internal simulation state tracking registers
    reg [3:0] clk_count;    // Startup delay counter
    reg [2:0] state;        // 0: Triangle, 1: Hold, 2: Major Code, 3: Full-Scale
    reg [4:0] state_counter;// Controls step count duration within states
    reg dir;                // 0 = Sweeping UP, 1 = Sweeping DOWN
    reg triangle_done;      // Flag to signal clean exit of state 0

    // Static continuous assignments
    assign out2 = out[2];
    assign out1 = out[1];
    assign out0 = out[0];
    assign out2_bar = ~out[2];
    assign out1_bar = ~out[1];
    assign out0_bar = ~out[0];

    initial begin
        clk_count     = 4'd0;
        state         = 3'd0;
        state_counter = 5'd0;
        dir           = 1'b0;
        out           = 3'b000;
        triangle_done = 1'b0;
    end

    always @(negedge clk) begin

        // 1. Hard Startup Delay
        if (clk_count < 4'd3) begin
            clk_count     <= clk_count + 4'd1;
            out           <= 3'b000;
            state         <= 3'd0;
            state_counter <= 5'd0;
            dir           <= 1'b0;
            triangle_done <= 1'b0;
        end

        // 2. Main State Machine
        else begin
            case (state)

                // STATE 0: Safe Triangle Sweep
                3'd0: begin
                    if (triangle_done) begin
                        state         <= 3'd1;
                        state_counter <= 5'd0;
                        out           <= 3'b000;
                        triangle_done <= 1'b0;
                    end else begin
                        if (dir == 1'b0) begin
                            if (out == 3'b111) begin
                                dir <= 1'b1;
                                out <= 3'b110;
                            end else begin
                                out <= out + 3'd1;
                            end
                        end else begin
                            if (out == 3'b000) begin
                                dir           <= 1'b0;
                                triangle_done <= 1'b1; // Signal completion safely at the bottom
                            end else begin
                                out <= out - 3'd1;
                            end
                        end
                    end
                end

                // STATE 1: Hold at 000
                3'd1: begin
                    out           <= 3'b000;
                    state_counter <= state_counter + 5'd1;
                    if (state_counter >= 5'd4) begin
                        state         <= 3'd2;
                        state_counter <= 5'd0;
                    end
                end

                // STATE 2: Major Code Transition (011 <-> 100)
                3'd2: begin
                    state_counter <= state_counter + 5'd1;
                    out           <= (state_counter[0] == 1'b0) ? 3'b011 : 3'b100;

                    if (state_counter >= 5'd12) begin
                        state         <= 3'd3;
                        state_counter <= 5'd0;
                    end
                end

                // STATE 3: Full-Scale Rail-to-Rail Snaps (000 <-> 111)
                3'd3: begin
                    state_counter <= state_counter + 5'd1;
                    out           <= (state_counter[0] == 1'b0) ? 3'b000 : 3'b111;

                    if (state_counter >= 5'd12) begin
                        state         <= 3'd0;
                        state_counter <= 5'd0;
                        dir           <= 1'b0;
                        triangle_done <= 1'b0;
                    end
                end

                default: state <= 3'd0;
            endcase
        end
    end
endmodule
