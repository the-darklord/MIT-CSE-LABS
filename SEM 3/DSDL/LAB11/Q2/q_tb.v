`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg set,clock, Resetn;
wire[4:0] Q;
integer i;
jc f1(clock,set,Resetn, Q);

initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0, q_tb);
clock=0;
forever #20 clock = ~clock;
end

initial
begin
Resetn=0; set=1; #40;
repeat ( 2 )
begin
Resetn=1; set=0; #200;
end
#20;
$display("Test complete");
$finish;
end

endmodule

