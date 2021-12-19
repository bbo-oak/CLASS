`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/30 22:21:46
// Design Name: 
// Module Name: tb_8bit
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


module tb_8bit();

reg [7:0] A_t,B_t;
wire C_out;
wire [7:0] S_t;

adder_subtractor_8bit a_s_8bit (.a(A_t),.b(B_t),.cout(C_out), .s(S_t));

initial begin
A_t[7:0] = 128;
B_t[7:0] = 200;
#5
A_t[7:0] = 128;
B_t[7:0] = -200;
#5
A_t[7:0] = 157;
B_t[7:0] = 32;
#5
A_t[7:0] = 124;
B_t[7:0] = -24;
end
endmodule

