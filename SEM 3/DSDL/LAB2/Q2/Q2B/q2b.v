module q2b(A,B,C,D,f);
input A,B,C,D;
output f;
assign f=(~A|B|~C)&(~A|C|~D)&(~B|C|D)&(A|~B|~C);
endmodule
