`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/14 15:32:48
// Design Name: 
// Module Name: clk_4div2
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module clk_4div2(input clk, output reg clk_4div);

    integer count;
    initial begin
        count = 0; clk_4div = 0;
    end
    always @(clk) begin
        if(clk) begin
            if(count < 3) begin
                count = count + 1;
                clk_4div = 1;
            end
            else begin
                count = 0;
                clk_4div = 0;
            end
        end
    end

endmodule
