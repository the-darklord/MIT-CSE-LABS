`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg clock, Resetn;
wire[3:0] Q;
integer i;
auc f1(clock,Resetn, Q);

initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0, q_tb);
clock=0;
forever #10 clock = ~clock;
end

initial
begin
Resetn=0; #10;
Resetn=1; #300;
$display("Test complete");
$finish;
end

endmodule


