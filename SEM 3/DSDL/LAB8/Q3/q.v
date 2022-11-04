module fourtosixteen(i,f,En);
input [3:0]i;
input En;
output [15:0]f;
wire [3:0]c;
twotofour stage0(i[3:2],c[3:0],En);
twotofour stage1(i[1:0],f[3:0],~c[0]);
twotofour stage2(i[1:0],f[7:4],~c[1]);
twotofour stage3(i[1:0],f[11:8],~c[2]);
twotofour stage4(i[1:0],f[15:12],~c[3]);
endmodule

module twotofour(i,f,En);
input [1:0]i;
input En;
output reg [3:0]f;
always @ (i,En)
begin

case(En)
0:f=4'b1111;
1:
begin
	case(i)
	0:f=4'b1110;
	1:f=4'b1101;
	2:f=4'b1011;
	3:f=4'b0111;
	endcase
end
endcase
end
endmodule
