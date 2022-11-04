module q(i,f,g,h,En);
input [3:0]i;
input En;
output f,g,h;
wire [15:0]c;
fourtosixteen s0(i,c,En);
assign f = c[11]|c[10]|c[7]|c[3]|c[14]|c[6];
assign g = c[14]|c[10]|c[2]|c[3];
assign h = c[1]|c[0]|c[14]|c[15]|c[7]|c[3];

endmodule

module fourtosixteen(i,f,En);
input [3:0]i;
input En;
output [15:0]f;
wire [3:0]c;
twotofour stage0(i[3:2],c[3:0],En);
twotofour stage1(i[1:0],f[3:0],c[0]);
twotofour stage2(i[1:0],f[7:4],c[1]);
twotofour stage3(i[1:0],f[11:8],c[2]);
twotofour stage4(i[1:0],f[15:12],c[3]);
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
