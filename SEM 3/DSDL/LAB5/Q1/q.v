module q(a, b, agtb, aeqb, altb);
input [4:0] a, b;
inout agtb, aeqb, altb;
wire [9:0]s;
assign s[0]=~b[0]&a[0];
assign s[1]=~b[1]&a[1];
assign s[2]=~b[2]&a[2];
assign s[3]=~b[3]&a[3];
assign s[4]=~b[4]&a[4];
assign s[5]=~(a[0]^b[0]);
assign s[6]=~(a[1]^b[1]);
assign s[7]=~(a[2]^b[2]);
assign s[8]=~(a[3]^b[3]);
assign s[9]=~(a[4]^b[4]);
assign agtb=s[0]|(s[5]&s[1])|(s[5]&s[6]&a[2])|(s[5]&s[6]&s[7]&s[3])|(s[5]&s[6]&s[7]&s[8]&s[4]);
assign aeqb=s[5]&s[6]&s[7]&s[8]&s[9];
assign altb=~(agtb|aeqb);
endmodule			
