`timescale 1ns/1ns
`include "q.v"

module q_tb();
reg [3:0]in;
reg En;
wire [15:0]y;
integer i;
decoder4to16 d0(in,En,y);

initial
begin

$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);

En=1'b1;
for(i=0;i<16;i=i+1)
begin
in=i; #20;
end
$display("Test Complete");

end
endmodule
