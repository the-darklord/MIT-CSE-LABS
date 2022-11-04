module q(i,f);
input [3:0]i;
output f;
fourtoone stage0(i[1:0],i[3:2],f);
endmodule

module fourtoone(d,s,f);
input [1:0]d;
input [1:0]s;
output f;
reg f;
always @(s)
begin
	case(s)
	0:f=(~d[0]|d[1]);
	1:f=d[0];
	2:f=0;
	3:f=0;
	endcase
end
endmodule
