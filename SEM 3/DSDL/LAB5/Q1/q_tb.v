`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [4:0] a, b;
wire agtb, aeqb, altb;
q q(a, b, agtb, aeqb, altb);
initial begin
	$dumpfile("q_tb.vcd");
	$dumpvars(0, q_tb);
	
	a=5'b00000; b=5'b00001;
	#20;
	
	a=5'b00001; b=5'b00001;
	#20;
	
	a=5'b00001; b=5'b00000;
	#20;
	
	$display("Test Complete");
end 
endmodule
	 
