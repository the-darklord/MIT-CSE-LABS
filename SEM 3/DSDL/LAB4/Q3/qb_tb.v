`timescale 1ns/1ns
`include "qb.v"
module qb_tb();
reg [1:0]x2,y2;
wire [3:0]p;

mult2 m2(x2,y2,p);

initial
begin
$dumpfile("qb_tb.vcd");
$dumpvars(0, qb_tb);

x2=2'b01; y2=2'b11; #20;
x2=2'b00; y2=2'b10; #20;

$display("Test complete");
end
endmodule
