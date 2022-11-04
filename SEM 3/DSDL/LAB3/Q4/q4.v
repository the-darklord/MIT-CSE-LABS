module q4(A,B,C,D,f);
input A,B,C,D;
output f;
assign f=~(~(~(A|A)|~(C|C))|~(D|D));
endmodule
