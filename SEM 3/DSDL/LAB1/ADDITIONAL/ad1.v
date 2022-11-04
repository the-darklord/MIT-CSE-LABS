module ad1(a,b,c,f1);
input a,b,c;
output f1;
assign f1=(a&~(c))|(b&c)|(~(b)&~(c));
endmodule
