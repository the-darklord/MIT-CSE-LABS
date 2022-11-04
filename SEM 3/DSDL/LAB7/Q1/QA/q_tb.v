`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [3:0]i;
wire f;
q f1(i,f);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);

i=4'b1110; #20;
i=4'b1010; #20;
i=4'b0010; #20;

$display("Test Complete");
end
endmodule
