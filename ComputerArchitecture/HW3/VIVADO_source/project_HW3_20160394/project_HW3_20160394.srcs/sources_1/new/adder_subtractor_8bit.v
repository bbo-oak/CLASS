`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/29 18:51:30
// Design Name: 
// Module Name: adder_subtractor_8bit
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


module adder_subtractor_8bit(a,b,cout,s);

assign #1 sum = a + b;

input [7:0] a,b;
output cout;
output [7:0] s;

wire [8:0] sum;

assign cout = sum[8];
assign s = sum[7:0];

assign #1 sum = a + b;

endmodule
