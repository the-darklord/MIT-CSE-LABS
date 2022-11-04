`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg T, clock, Resetn;
wire Q;
tff f1(T, clock, Resetn, Q);

initial
begin
clock=0;
forever #20 clock = ~clock;
end

initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0, q_tb);

T <= 0; Resetn <=0; #20;
T <= 0; Resetn <=1; #20;
T <= 1; Resetn <=0; #20;
T <= 1; Resetn <=0; #20;
T <= 1; Resetn <=1; #20;

$display("Test complete");
end
endmodule
