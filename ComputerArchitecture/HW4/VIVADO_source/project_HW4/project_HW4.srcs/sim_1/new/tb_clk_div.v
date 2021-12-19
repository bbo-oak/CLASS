`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/14 15:36:42
// Design Name: 
// Module Name: tb_clk_div
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


module tb_clk_div();

// Lab 1 testbench
/*
reg clk, rst;
wire clk_2_0394, clk_4_0394, clk_8_0394;

initial begin
    clk <= 1;
    rst <= 0;
    #5
    rst <= 1;
    #10
    rst <= 0;
end

always #5 clk <= ~clk;

divide_by_2 clk_24816(clk, rst, clk_2_0394, clk_4_0394, clk_8_0394);
*/


// Lab 2 testbench
/*
    reg clk;
    wire clk_3_div_0394, clk_4_div_0394;
    
    clk_3div clk_3div(clk, clk_3_div_0394);
    clk_4div2 clk_4div(clk, clk_4_div_0394);
    
    initial clk = 0;
    always #5 clk = ~clk;
*/


reg clk;
parameter n = 4;
wire clk_out_0394;

initial clk = 0;
always #5 clk = ~clk;

clk_Ndiv clk_ndiv(clk,n,clk_out_0394);


endmodule
