`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/29 20:05:03
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

module fa(a, b, cin, sum,cout );

input a,b,cin;
output cout, sum;

wire w1, w2, w3;

ha h1(.A (a), .B (b), .S(w1), .C(w2));
ha h2(.A (w1), .B (cin), .S(sum), .C(w3));

assign cout = w2 | w3;

endmodule
