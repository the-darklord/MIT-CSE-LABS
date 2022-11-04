module q(i,f);
input [2:0]i;
output f;

wire g,h;
twotoone stage0({i[0],1'b0},i[1],g);
twotoone stage1({1'b1,i[0]},i[1],h);
twotoone stage2({h,g},i[2],f);

endmodule

module twotoone(a,s,f);
input [1:0]a;
input s;
output f;
reg f;
always @ (a,s)
begin
case(s)
0:f=a[0];
1:f=a[1];
endcase
end
endmodule
