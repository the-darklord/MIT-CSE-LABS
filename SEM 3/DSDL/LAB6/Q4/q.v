module fourtoone(i,s,f);
input [3:0]i;
input [1:0]s;
output f;

function twotoone;
input [1:0]a;
input s;
case(s)
0:twotoone = a[0];
1:twotoone = a[1];
endcase
endfunction

wire c1,c2;
assign c1 = twotoone(i[1:0],s[0]);
assign c2 = twotoone(i[3:2],s[0]);
assign f = twotoone({c2,c1},s[1]);

endmodule
