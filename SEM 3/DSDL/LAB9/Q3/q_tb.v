`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [2:0]i;
reg En;
wire f;
integer j;
q f1(i,f,En);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);
En=1'b1;
for(j=0;j<8;j=j+1)
begin
i=j; #20;
end
$display("Test Complete");
end
endmodule
