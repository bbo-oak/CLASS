`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/30 22:35:18
// Design Name: 
// Module Name: adder_8bit
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


module adder_8bit(A,B,C,R);
input [7:0] A,B;
output reg C;
output reg [7:0] R;
wire [8:0] ADD;

assign #1 ADD = A + B;
always @(ADD)
begin
    R = ADD[7:0];
    C = ADD[8];
end

endmodule
