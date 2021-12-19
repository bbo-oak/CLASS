`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/13 19:51:43
// Design Name: 
// Module Name: fa2
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


module fa2(a, b, cin, cout, sum);

input a,b,cin;
output reg cout, sum;
wire[2:0] a_b_cin;

assign #1 a_b_cin = {a,b,cin};

always @(a_b_cin)
begin
    case(a_b_cin)
        3'b000:begin
        cout = 0;
        sum = 0;
        end
        
        3'b001:begin
        cout = 0;
        sum = 1;
        end
        
        3'b010:begin
        cout = 0;
        sum = 1;
        end
        
        3'b011:begin
        cout = 1;
        sum = 0;
        end
        
        3'b100:begin
        cout = 0;
        sum = 1;
        end
        
        3'b101:begin
        cout = 1;
        sum = 0;
        end
        
        3'b110:begin
        cout = 1;
        sum = 0;
        end
        
        3'b111:begin
        cout = 1;
        sum = 1;
        end
        
        3'b000:begin
        cout = 0;
        sum = 0;
        end
    endcase
end    

endmodule
