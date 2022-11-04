`timescale 1ns/1ns
`include "q.v"
module q_tb();
reg [2:0]i;
reg En;
wire [7:0]f;
threetoeight f1(i,f,En);
initial
begin
$dumpfile("q_tb.vcd");
$dumpvars(0,q_tb);
En=1'b1;
i=3'd0; #20;
i=3'd1; #20;
i=3'd2; #20;
i=3'd3; #20;
i=3'd4; #20;
i=3'd5; #20;
i=3'd6; #20;
i=3'd7; #20;
$display("Test Complete");
end
endmodule
