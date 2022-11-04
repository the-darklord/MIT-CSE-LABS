module mult2(x2,y2,p);
input [1:0]x2,y2;
output [3:0]p;
wire [1:0]a,b;
assign b[0]=x2[1]&y2[0];
assign a[0]=x2[0]&y2[1];
assign a[1]=x2[1]&y2[1];
assign b[1]=1'b0;
assign p[0]=x2[0]&y2[0];
adder2 stage0(a,b,1'b0,p[2:1],p[3]);
endmodule

module adder2(x,y,cin,s,cout);
input [1:0]x,y;
input cin;
output [1:0]s;
output cout;
wire c1;
fulladder stage0(x[0],y[0],cin,s[0],c1);
fulladder stage1(x[1],y[1],c1,s[1],cout);
endmodule

module fulladder(x1,y1,Cin,Sum,Cout);
input x1,y1,Cin;
output Sum,Cout;
assign Sum=x1^y1^Cin;
assign Cout = (x1&y1)|(x1&Cin)|(y1&Cin);
endmodule

