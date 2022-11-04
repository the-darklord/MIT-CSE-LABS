module q1s(a,b,c,d,f);
input a,b,c,d;
output f;

and(g,a,b);
or(h,g,c);
not(k,h);
and(j,k,d);
or(i,h,d);
and(f,i,j);

endmodule
