`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/30 22:32:25
// Design Name: 
// Module Name: selector_8bit
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


module selector_8bit(a,b,sel,cout,r,aGb,aEb,aLb);

input [7:0] a,b;
input [1:0] sel;

reg [7:0] r1,r2,r3;
reg c1,c2;

output reg cout,aGb,aEb,aLb;
output reg [7:0] r;

adder_8bit add8(.A(a), .B(b), .C(c1), .R(r1));
subtractor_8bit sub8(.A(a), .B(b), .C(c2), .R(r2));
bitwise_xor xor8(.A(a), .B(b), .R(r3));
comparator cmp8(.A(a), .B(b), .AGB(aGb), .AEB(aEb), .ALB(aLb));

always @(sel)
begin
    case(sel)
        2'b00:begin
        r = r1;
        cout = c1;
        aGb = 0;
        aEb = 0;
        aLb = 0;
        end
        
        2'b01:begin
        r = r2;
        cout = c2;
        aGb = 0;
        aEb = 0;
        aLb = 0;
        end
        
        2'b10:begin
        r = r3;
        cout = 0;
        aGb = 0;
        aEb = 0;
        aLb = 0;
        end
        
        2'b11:begin
        cout = 0;
        r = 0;
        end
    endcase
end

endmodule

