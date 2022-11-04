`timescale 1ns/1ns
`include "q2a.v"

module q2a_tb();
reg A,B,C,D;
wire f;

q2a q2a(A,B,C,D,f);
initial
begin

$dumpfile("q2a_tb.vcd");
$dumpvars(0,q2a_tb);

A=1'b0; B=1'b0; C=1'b0; D=1'b0; #20;
A=1'b0; B=1'b0; C=1'b0; D=1'b1; #20;
A=1'b0; B=1'b0; C=1'b1; D=1'b0; #20;
A=1'b0; B=1'b0; C=1'b1; D=1'b1; #20;
A=1'b0; B=1'b1; C=1'b0; D=1'b0; #20;
A=1'b0; B=1'b1; C=1'b0; D=1'b1; #20;
A=1'b0; B=1'b1; C=1'b1; D=1'b0; #20;
A=1'b0; B=1'b1; C=1'b1; D=1'b1; #20;
A=1'b1; B=1'b0; C=1'b0; D=1'b0; #20;
A=1'b1; B=1'b0; C=1'b0; D=1'b1; #20;
A=1'b1; B=1'b0; C=1'b1; D=1'b0; #20;
A=1'b1; B=1'b0; C=1'b1; D=1'b1; #20;
A=1'b1; B=1'b1; C=1'b0; D=1'b0; #20;
A=1'b1; B=1'b1; C=1'b0; D=1'b1; #20;
A=1'b1; B=1'b1; C=1'b1; D=1'b0; #20;
A=1'b1; B=1'b1; C=1'b1; D=1'b1; #20;

$display("Test Complete");

end

endmodule
