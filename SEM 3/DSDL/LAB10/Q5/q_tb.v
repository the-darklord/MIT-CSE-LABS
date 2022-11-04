`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg clock, Resetn;
reg i;
wire out;
reg5 f1(i,out,clock,Resetn);
always #20 clock = ~clock;
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0, q_tb);
clock=0;
Resetn=1;
i = 1'b1; #40;
i = 1'd0; #40; 
i = 1'd0; #40;
i = 1'b0; #40;
i = 1'd1; #40; 
i = 1'd1; #40;
i = 1'b1; #40;
i = 1'd0; #40; 
i = 1'd0; #40;
$display("Test complete");
end
endmodule
