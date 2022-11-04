module sixteentoone(i,s,f);
input [15:0]i;
input [3:0]s;
output f;
wire [3:0]c;
fourtoone f0(i[3:0],s[1:0],c[0]);
fourtoone f1(i[7:4],s[1:0],c[1]);
fourtoone f2(i[11:8],s[1:0],c[2]);
fourtoone f3(i[15:12],s[1:0],c[3]);
fourtoone f4(c[3:0],s[3:2],f);
endmodule

module fourtoone(i,s,f);
input [3:0]i;
input [1:0]s;
output f;
reg f;
always @(i,s)
begin
f = s[1]?(s[0]?i[3]:i[2]):(s[0]?i[1]:i[0]);
end
endmodule

