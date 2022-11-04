`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [15:0]i;
wire [4:0]f;
integer j;
encoder16to4 f1(i,f);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);

for(j=0;j<16;j=j+1)
begin
i=0;
i[j]=1; #20;
end

$display("Test Complete");
end
endmodule
