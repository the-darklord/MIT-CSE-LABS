module q(b,e);
input [3:0]b;
output [3:0]e;

eighttoone stage0({1'b1,1'b1,b[0],1'b0,1'b0},b[3:1],e[3]);
eighttoone stage1({b[0],1'b0,~b[0],1'b1,b[0]},b[3:1],e[2]);
eighttoone stage2({~b[0],b[0],~b[0],b[0],~b[0]},b[3:1],e[1]);
eighttoone stage3({~b[0],~b[0],~b[0],~b[0],~b[0]},b[3:1],e[0]);

endmodule
module eighttoone(i,s,f);
input [4:0]i;
input [2:0]s;
output f;
reg f;
always @(i,s)
begin
	casez(s)
	0:f=i[0];
	1:f=i[1];
	2:f=i[2];
	3:f=i[3];
	4:f=i[4];
	5:f=1'bz;
	6:f=1'bz;
	7:f=1'bz;
	endcase
end
endmodule
