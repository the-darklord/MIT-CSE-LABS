`timescale 1ns/1ns
`include "ad1.v"
//Name of the Verilog file
module ad1_tb();
reg a, b, c;
//Input
wire f1;
//Output
ad1 ad1(a, b, c, f1); //Instantiation of the module
initial
begin
$dumpfile("ad1_tb.vcd");
$dumpvars(0, ad1_tb);
a=1'b0; b=1'b0; c=1'b0;
#20;
a=1'b0; b=1'b0; c=1'b1;
#20;
a=1'b0; b=1'b1; c=1'b0;
#20;
a=1'b0; b=1'b1; c=1'b1;
#20;
a=1'b1; b=1'b0; c=1'b0;
#20;
a=1'b1; b=1'b0; c=1'b1;
#20;
a=1'b1; b=1'b1; c=1'b0;
#20;
a=1'b1; b=1'b1; c=1'b1;
#20;
$display("Test complete");
end
endmodule
