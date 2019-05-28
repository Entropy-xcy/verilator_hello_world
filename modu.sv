// Simple hello world in SystemVerilog
module modu
    (
        input logic rst,
        input logic clk,
        output logic pulse
    );

    reg [7:0] counter;

    always@(posedge clk)
    begin
        if(rst)
            counter <= 0;
        else
            counter <= counter + 1;
    end

    always_comb
    begin
        pulse = counter[2] && counter[1];
    end

endmodule