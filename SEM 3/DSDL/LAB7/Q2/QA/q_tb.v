`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [2:0]i;
wire f;
q f1(i,f);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);

i=3'b110; #20;
i=3'b010; #20;
i=3'b101; #20;

$display("Test Complete");
end
endmodule
