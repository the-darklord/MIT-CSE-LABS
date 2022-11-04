module q3(x1,x2,x3,x4,x5,f);
input x1,x2,x3,x4,x5;
output f;
assign g=x5&(~x1|x2);
assign f=(x3&x4&g)|(~x3&~x4&g)|(~x3&x4&~g);
endmodule
