`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/29 18:49:59
// Design Name: 
// Module Name: adder_1bit
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


module adder_1bit(a,b,cout,s);

input a,b;
output cout, s;
wire [1:0] sum;

assign cout = sum[1];
assign s = sum[0];

assign #1 sum = a + b;

endmodule
