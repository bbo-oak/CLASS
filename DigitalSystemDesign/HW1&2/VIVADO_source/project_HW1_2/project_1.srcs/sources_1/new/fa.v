`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/13 18:19:33
// Design Name: 
// Module Name: fa
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


module fa(a, b, cin, cout, sum);

input a;
input b;
input cin;
output cout, sum;

assign #1 cout = (b & cin) | (a & cin) | (a & b);
assign #1 sum = a ^b ^ cin;


endmodule
