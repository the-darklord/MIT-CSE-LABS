module decoder4to16(in,En,y);
input [3:0]in;
input En;
output [15:0]y;
wire c1,c2;
assign c1=En&~in[3];
assign c2=En&in[3];
decoder3to8 stage0(in[2:0],c1,y[7:0]);
decoder3to8 stage1(in[2:0],c2,y[15:8]);
endmodule

module decoder3to8(in,En,y);
input [2:0]in;
input En;
output reg [7:0]y;
integer i;
reg [2:0]c=0;
always @ (in,c,En)
begin
for(i=0;i<8;i=i+1)
begin
if(En)
begin
y[i]=(in==i)?1:0;
end
else
begin
y[i]=0;
end
end
end
endmodule
