module mux81(i,s,f,En);
input [7:0]i;
input [2:0]s;
input En;
output reg f;
wire [7:0] c,h;
integer j;
decoder3to8 s0(s,En,c);
always @ (c)
begin
f=1'b0;
for(j=0;j<8;j=j+1)
begin
if(s==j)
begin
f=f|(c[j]&i[j]);
end
end
end
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
