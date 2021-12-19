`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/14 15:23:25
// Design Name: 
// Module Name: clk_3div
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


module clk_3div(input clk, output reg clk_3div);

integer count;

initial begin
    count  = 0;
    clk_3div = 0;
end

always @(clk) begin
    if(clk) begin
        if(count < 2) begin
            count = count + 1;
            clk_3div = 1;
        end
        else begin
            count = 0;
            clk_3div = 0;
        end
    end
end

endmodule

