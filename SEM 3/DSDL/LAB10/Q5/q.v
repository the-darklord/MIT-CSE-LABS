module reg5(i,out,clock,Resetn);
input i;
output out;
input clock,Resetn;
wire [4:0]c;
dff s0(i,clock,Resetn,c[0]);
dff s1(c[0],clock,Resetn,c[1]);
dff s2(c[1],clock,Resetn,c[2]);
dff s3(c[2],clock,Resetn,c[3]);
dff s4(c[3],clock,Resetn,c[4]);
dff s5(c[4],clock,Resetn,out);
endmodule

module dff(D,clock,Resetn,Q);
input D,clock,Resetn;
output reg Q;
always @ (posedge clock)
begin
if(!Resetn)
	Q <= 0;
else
	Q <= D;
end
endmodule
