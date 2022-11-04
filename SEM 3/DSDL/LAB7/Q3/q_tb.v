`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [3:0]b;
wire [3:0]e;
q f1(b,e);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);

b=4'b1000; #20;
b=4'b1001; #20;
b=4'b0010; #20;

$display("Test Complete");
end
endmodule
