`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [3:0]i;
wire [2:0]f;
integer j;
encoder4to2 f1(i,f);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);

for(j=0;j<16;j=j+1)
begin
i=j; #20;
end

$display("Test Complete");
end
endmodule
