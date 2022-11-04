module q1(A,B,C,D,f);
input A,B,C,D;
output f;
assign g=(A~&(B~&B))~&(C~&(D~&D));
assign f=(g~&g);
endmodule
