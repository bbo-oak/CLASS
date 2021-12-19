`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/15 16:51:31
// Design Name: 
// Module Name: divide_by_2
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


module divide_by_2(
input clk, input reset, 
output reg clk_2, clk_4, clk_8);
reg [2:0] count;

always @(posedge clk) begin
    if(reset) begin
        count <= 4'b0;
        clk_2 <= 1'b0;
        clk_4 <= 1'b0;
        clk_8 <= 1'b0;
    end
    else begin
        count = count + 1;
        
        clk_2 <= ~clk_2;
        
        if(count[0]) begin
            clk_4 <= ~clk_4;
        end
        else if(count[1]) begin
            clk_8 <= ~clk_8;
        end
    end
end

endmodule
