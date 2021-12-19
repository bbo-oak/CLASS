`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/30 17:12:16
// Design Name: 
// Module Name: tb_4bit
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


module tb_4bit();

reg [7:0] A_t,B_t;
reg [1:0] S;
wire C_out,AGB,ALB,AEB;
wire [7:0] R;

seletor_8bit S8 (.a(A_t), .b(B_t), .sel(S), .cout(C_out), .r(R), .aGb(AGB), .aEb(AEB), .aLb(ALB));

initial begin
A_t[7:0] = 15;
B_t[7:0] = 15;
S[1:0] = 0;
#5
A_t[7:0] = 15;
B_t[7:0] = 15;
S[1:0] = 1;
#5
A_t[7:0] = 15;
B_t[7:0] = 15;
S[1:0] = 2;
#5
A_t[7:0] = 15;
B_t[7:0] = 15;
S[1:0] = 3;
end

/*reg [3:0] A_t,B_t;
reg C_in;
wire C_out;
wire [3:0] S_t;

adder_subtractor_4bit a_s_4bit (.a(A_t), .b(B_t), .k(C_in), .cout(C_out), .s(S_t));

initial begin
A_t[3:0] = 15;
B_t[3:0] = 15;
C_in = 0;
#5
A_t[3:0] = 0;
B_t[3:0] = 15;
C_in = 1;
#5
A_t[3:0] = 4;
B_t[3:0] = 11;
C_in = 0;
#5
A_t[3:0] = 7;
B_t[3:0] = 12;
C_in = 1;
end
*/

endmodule
