module q(g,b);
input [3:0]g;
output [3:0]b;
assign b[0] = g[0];
assign b[1] = g[1]^g[0];
assign b[2] = (~g[2]&g[0])|(g[1]&~g[2])|(~g[1]&~g[0]&g[2]);
assign b[3] = (g[3]&g[2])|(g[3]&~g[1]&~g[0]);
endmodule
