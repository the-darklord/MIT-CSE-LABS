module fourtoone(i,s,f);
input [3:0]i;
input [1:0]s;
output f;
wire [1:0] c;
twotoone stage1(i[3:2],s[0],c[1]);
twotoone stage2(i[1:0],s[0],c[0]);
twotoone stage3(c,s[1],f);
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
