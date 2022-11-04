module halfadder(x,y,sum,cout);
input x,y;
output sum,cout;
assign sum=x^y;
assign cout=x&y;
endmodule

module fulladder(x1,y1,Cin,Sum,Cout);
input x1,y1,Cin;
output Sum,Cout;
assign Sum=x1^y1^Cin;
assign Cout = (x1&y1)|(x1&Cin)|(y1&Cin);
endmodule

module decomposedfulladder(x2,y2,CIn,Sum1,Cout1);
input x2,y2,CIn;
output Sum1,Cout1;
halfadder stage0(x2,y2,s1,c1);
halfadder stage1(s1,CIn,Sum1,c2);
assign Cout1 = c1|c2;
endmodule
