module q2s(a,b,c,d,f,g);
input a,b,c,d;
output f,g;

nand(h,a,b);
nor(g,b,c,d);
xor(f,h,c,d);

endmodule
