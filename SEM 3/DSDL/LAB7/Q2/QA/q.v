module q(i,f);
input [2:0]i;
output f;
reg f;
always @ (i)
begin
case(i[2])
0:f=i[1]&i[0];
1:f=i[1]|i[0];
endcase
end
endmodule
