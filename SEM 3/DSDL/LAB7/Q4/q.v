module q(b,e);
input [3:0]b;
output [3:0]e;
wire c;
assign c = b[1]^b[0];
fourtoone stage0({1'b1,1'b1,1'b0,1'b0},b[3:2],e[3]);
fourtoone stage1({1'b0,1'b1,1'b1,1'b0},b[3:2],e[2]);
fourtoone stage2({~b[1],b[1],~b[1],b[1]},b[3:2],e[1]);
fourtoone stage3({c,c,c,c},b[3:2],e[0]);

endmodule
module fourtoone(i,s,f);
input [3:0]i;
input [1:0]s;
output f;
reg f;
always @(i,s)
begin
	case(s)
	0:f=i[0];
	1:f=i[1];
	2:f=i[2];
	3:f=i[3];
	endcase
end
endmodule
