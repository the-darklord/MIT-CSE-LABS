`timescale 1ns/1ns
`include "ad2.v"
//Name of the Verilog file
module ad2_tb();
reg a, b, c;
//Input
wire f2;
//Output
ad2 ad2(a, b, c, f2); //Instantiation of the module
initial
begin
$dumpfile("ad2_tb.vcd");
$dumpvars(0, ad2_tb);
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
