`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/29 18:54:44
// Design Name: 
// Module Name: adder_subtractor_4bit
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


module adder_subtractor_4bit(a,b,k,cout,s);

input [3:0] a,b;
input k;
output cout;
output [3:0] s;

wire c1,c2,c3,x0,x1,x2,x3;

xor xor1 (x0,k,b[0]);
fa fa1 (a[0],x0,k,s[0],c1);
xor xor2 (x1,k,b[1]);
fa fa2 (a[1],x1,c1,s[1],c2);
xor xor3 (x2,k,b[2]);
fa fa3 (a[2],x2,c2,s[2],c3);
xor xor4 (x3,k,b[3]);
fa fa4 (a[3],x3,c3,s[3],cout);



endmodule
