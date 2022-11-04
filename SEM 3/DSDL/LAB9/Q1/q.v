module q(i,f,En);
input [3:0]i;
input En;
output f;
wire [15:0]c;
dec4to16 s0(i,c,En);
assign f = c[1]|c[3]|c[6]|c[7]|c[9]|c[14]|c[15];

endmodule

module dec4to16(i,f,En);
input [3:0]i;
input En;
output reg [15:0]f;
integer j;
always @ (i,En)
begin
if(En)
begin
for(j=0;j<16;j=j+1)
begin
f[j]=(i==j)?1:0;
end
end
end
endmodule
