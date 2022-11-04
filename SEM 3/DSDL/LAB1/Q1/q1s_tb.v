`timescale 1ns/1ns
`include "q1s.v"

module q1s_tb();
reg a,b,c,d;
wire f;

q1s q1s(a,b,c,d,f);
initial
begin

$dumpfile("q1s_tb.vcd");
$dumpvars(0,q1s_tb);

a=1'b0; b=1'b0; c=1'b0; d=1'b0; #20;
a=1'b0; b=1'b0; c=1'b0; d=1'b1; #20;
a=1'b0; b=1'b0; c=1'b1; d=1'b0; #20;
a=1'b0; b=1'b0; c=1'b1; d=1'b1; #20;
a=1'b0; b=1'b1; c=1'b0; d=1'b0; #20;
a=1'b0; b=1'b1; c=1'b0; d=1'b1; #20;
a=1'b0; b=1'b1; c=1'b1; d=1'b0; #20;
a=1'b0; b=1'b1; c=1'b1; d=1'b1; #20;
a=1'b1; b=1'b0; c=1'b0; d=1'b0; #20;
a=1'b1; b=1'b0; c=1'b0; d=1'b1; #20;
a=1'b1; b=1'b0; c=1'b1; d=1'b0; #20;
a=1'b1; b=1'b0; c=1'b1; d=1'b1; #20;
a=1'b1; b=1'b1; c=1'b0; d=1'b0; #20;
a=1'b1; b=1'b1; c=1'b0; d=1'b1; #20;
a=1'b1; b=1'b1; c=1'b1; d=1'b0; #20;
a=1'b1; b=1'b1; c=1'b1; d=1'b1; #20;

$display("Test Complete");

end

endmodule
