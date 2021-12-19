`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/30 22:35:37
// Design Name: 
// Module Name: subtractor_8bit
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


module subtractor_8bit(A,B,C,R);
    
input [7:0] A,B;
output reg C;
output reg [7:0] R;
wire [8:0] SUB;

assign #1 SUB = A - B;
always @(SUB)
begin
    R = SUB[7:0];
    C = SUB[8];
end

endmodule
