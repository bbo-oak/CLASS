`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/13 18:27:11
// Design Name: 
// Module Name: tb_fa
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


module tb_fa();

reg A, B, Cin;
wire S, Cout;
fa f1 (.a (A), .b (B), .cin(Cin), .sum(S), .cout(Cout));
fa2 f2 (.a (A), .b (B), .cin(Cin), .sum(S), .cout(Cout));
fa3 f3 (.a (A), .b (B), .cin(Cin), .sum(S), .cout(Cout));

initial begin
A = 0;
B = 0;
Cin = 0;
#5
A = 0;
B = 0;
Cin = 1;
#5
A = 0;
B = 1;
Cin = 0;
#5
A = 0;
B = 1;
Cin = 1;
#5
A = 1;
B = 0;
Cin = 0;
#5
A = 1;
B = 0;
Cin = 1;
#5
A = 1;
B = 1;
Cin = 0;
#5
A = 1;
B = 1;
Cin = 1;
end

endmodule
