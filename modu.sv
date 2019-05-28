// Simple hello world in SystemVerilog
module modu
    (
        input logic clk,
        output logic pulse
    );

    assign pulse = clk;
endmodule