module q(i,f);
input [3:0]i;
output f;
eighttoone stage0(i[0],i[3:1],f);
endmodule

module eighttoone(d,s,f);
input d;
input [2:0]s;
output f;
reg f;
always @(s)
begin
	case(s)
	0:f=0;
	1:f=0;
	2:f=1;
	3:f=1;
	4:f=1;
	5:f=0;
	6:f=1;
	7:f=~d;
	endcase
end
endmodule
