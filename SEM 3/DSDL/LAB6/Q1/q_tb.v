`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [3:0]i;
reg [1:0]s;
wire f;

fourtoone f1(i,s,f);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);

i=4'd5;
s=2'd0; #20;
s=2'd1; #20;
s=2'd2; #20;
s=2'd3; #20;

i=4'd6;
s=2'd0; #20;
s=2'd1; #20;
s=2'd2; #20;
s=2'd3; #20;

$display("Test Complete");
end
endmodule
