module q(i,f,En);
input [2:0]i;
input En;
output f;
wire [7:0]c;
twotofour s0(i[1:0],c[3:0],~i[2]&En);
twotofour s1(i[1:0],c[7:4],i[2]&En);
assign f = c[3]|c[5]|c[6]|c[7];
endmodule

module twotofour(i,f,En);
input [1:0]i;
input En;
output reg [3:0]f;
always @ (i,En)
begin

case(En)
0:f=4'd0;
1:
begin
	case(i)
	0:f=4'd1;
	1:f=4'd2;
	2:f=4'd4;
	3:f=4'd8;
	endcase
end
endcase
end
endmodule
