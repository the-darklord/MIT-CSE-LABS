module sixteentoone(i,s,f);
input [15:0]i;
input [3:0]s;
output f;
wire [1:0]c;
eighttoone e0(i[7:0],s[2:0],c[0]);
eighttoone e1(i[15:8],s[2:0],c[1]);
twotoone t1(c,s[3],f);
endmodule

module eighttoone(i,s,f);
input [7:0]i;
input [2:0]s;
output f;
reg f;
always @(i,s)
begin
	case(s)
	0:f=i[0];
	1:f=i[1];
	2:f=i[2];
	3:f=i[3];
	4:f=i[4];
	5:f=i[5];
	6:f=i[6];
	7:f=i[7];
	endcase
end
endmodule

module twotoone(i,s,f);
input [1:0]i;
input s;
output f;
reg f;
always @(i,s)
begin
if(s)
f=i[1];
else
f=i[0];
end
endmodule