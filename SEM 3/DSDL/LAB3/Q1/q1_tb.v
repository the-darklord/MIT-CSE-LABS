`timescale 1ns/1ns
`include "q1.v"
module q1_tb();
reg A,B,C,D;
wire f;
q1 q1(A,B,C,D,f);
initial
begin
$dumpfile("q1_tb.vcd");
$dumpvars(0,q1_tb);

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
