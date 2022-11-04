`timescale 1ns/1ns
`include "qb.v"
module qb_tb();
reg x,y;
wire sum,cout;
halfadder ha(x,y,sum,cout);
initial
begin
$dumpfile("qb_tb.vcd");
$dumpvars(0,qb_tb);

x=1'b0; y=1'b0; #20;
x=1'b0; y=1'b1; #20;
x=1'b1; y=1'b0; #20;
x=1'b1; y=1'b1; #20; 

$display("Test Complete");
end

reg x1,y1,Cin;
wire Sum,Cout;
fulladder fa(x1,y1,Cin,Sum,Cout);
initial
begin
$dumpfile("qb_tb.vcd");
$dumpvars(0,qb_tb);

x1=1'b0; y1=1'b0; Cin=1'b0; #20;
x1=1'b0; y1=1'b0; Cin=1'b1; #20;
x1=1'b0; y1=1'b1; Cin=1'b0; #20;
x1=1'b0; y1=1'b1; Cin=1'b1; #20;
x1=1'b1; y1=1'b0; Cin=1'b0; #20;
x1=1'b1; y1=1'b0; Cin=1'b1; #20;
x1=1'b1; y1=1'b1; Cin=1'b0; #20;
x1=1'b1; y1=1'b1; Cin=1'b1; #20;

$display("Test Complete");
end

reg x2,y2,CIn;
wire Sum1,Cout1;
decomposedfulladder dfa(x2,y2,CIn,Sum1,Cout1);
initial
begin
$dumpfile("qb_tb.vcd");
$dumpvars(0,qb_tb);

x2=1'b0; y2=1'b0; CIn=1'b0; #20;
x2=1'b0; y2=1'b0; CIn=1'b1; #20;
x2=1'b0; y2=1'b1; CIn=1'b0; #20;
x2=1'b0; y2=1'b1; CIn=1'b1; #20;
x2=1'b1; y2=1'b0; CIn=1'b0; #20;
x2=1'b1; y2=1'b0; CIn=1'b1; #20;
x2=1'b1; y2=1'b1; CIn=1'b0; #20;
x2=1'b1; y2=1'b1; CIn=1'b1; #20;

$display("Test Complete");
end
endmodule
