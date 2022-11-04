module ad2(a,b,c,f2);
input a,b,c;
output f2;

assign f2=(a|~b|c)&(a|b|~c)&(~a|b|~c);

endmodule
