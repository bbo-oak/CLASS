`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/30 22:36:12
// Design Name: 
// Module Name: comparator
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


module comparator(A,B,AGB,AEB,ALB);

input [7:0] A,B;
output reg AGB,AEB,ALB;
wire [7:0] num1,num2;

assign #1 num1 = A;
assign #1 num2 = B;

always @(A or B)
begin
    if(num1 > num2)begin
        AGB = 1;
        AEB = 0;
        ALB = 0;
        end
    else if(num1 == num2)begin
        AGB = 0;
        AEB = 1;
        ALB = 0;
        end
    else if(num1 < num2)begin
        AGB = 0;
        AEB = 0;
        ALB = 1;
        end
end
endmodule
