`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [3:0]i;
reg En;
wire [15:0]f;
integer j;
fourtosixteen f1(i,f,En);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);
En=1'b1;
for(j=0;j<16;j=j+1)
begin
i=j; #20;
end
$display("Test Complete");
end
endmodule
