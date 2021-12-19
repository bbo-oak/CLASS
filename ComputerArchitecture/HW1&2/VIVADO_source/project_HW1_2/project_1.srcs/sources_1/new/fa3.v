`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/13 20:37:43
// Design Name: 
// Module Name: fa3
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


module fa3(a, b, cin, cout, sum );

input a,b,cin;
output cout, sum;

wire w1, w2, w3;

ha h1(.A (a), .B (b), .S(w1), .C(w2));
ha h2(.A (w1), .B (cin), .S(sum), .C(w3));

assign cout = w2 | w3;

endmodule
