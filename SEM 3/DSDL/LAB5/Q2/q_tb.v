`timescale 1ns/1ns
`include "q.v"
module q_tb();
parameter n=4;
reg [n-1:0]g;
wire [n-1:0]b;

q q(g,b);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);
g=4'b1010; #20;
g=4'b1111; #20;
$display("Test Complete ");
end
endmodule
