`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [7:0]i;
reg [2:0]s;
reg En;
wire f;
integer j;
mux81 f1(i,s,f,En);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);
En=1'b1; i=8'd1;
for(j=0;j<8;j=j+1)
begin
s=j; #20;
end
En=1'b1; i=8'd2;
for(j=0;j<8;j=j+1)
begin
s=j; #20;
end
$display("Test Complete");
end
endmodule
