`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg J,K, clock, Resetn;
wire Q;
jkff f1(J,K, clock, Resetn, Q);

initial
begin
clock=0;
forever #20 clock = ~clock;
end

initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0, q_tb);

Resetn=1; J=0; K=0; #20;
Resetn=0; J=0; K=0; #20;
Resetn=0; J=0; K=1; #20;
Resetn=0; J=1; K=0; #20;
Resetn=0; J=1; K=1; #20;


$display("Test complete");
end
endmodule
