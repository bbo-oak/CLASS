`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/13 20:45:12
// Design Name: 
// Module Name: ha
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

module ha(A,B,S,C);

input A,B;
output S, C;
reg r1,r2;

assign S = r1;
assign C = r2;

always @(*)
begin
    r1 = A ^ B;
    r2 = A & B;
end 

endmodule
