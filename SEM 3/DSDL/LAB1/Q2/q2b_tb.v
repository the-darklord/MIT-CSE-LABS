`timescale 1ns/1ns
`include "q2b.v"

module q2b_tb();
reg a,b,c,d;
wire f,g;

q2b q2b(a,b,c,d,f,g);
initial
begin

$dumpfile("q2b_tb.vcd");
$dumpvars(0,q2b_tb);

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
