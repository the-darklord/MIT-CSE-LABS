module q2a(A,B,C,D,f);
input A,B,C,D;
output f;
assign f=(~B|D)&(B|C);
endmodule
