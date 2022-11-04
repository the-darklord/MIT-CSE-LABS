module reg5(i,out,clock,Resetn);
input [4:0]i;
output [4:0]out;
input clock,Resetn;
dff s0(i[0],clock,Resetn,out[0]);
dff s1(i[1],clock,Resetn,out[1]);
dff s2(i[2],clock,Resetn,out[2]);
dff s3(i[3],clock,Resetn,out[3]);
dff s4(i[4],clock,Resetn,out[4]);
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
