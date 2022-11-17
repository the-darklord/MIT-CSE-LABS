module auc(clock,Resetn,Q);
input clock,Resetn;
output [3:0]Q;
dff s0(~Q[0],clock,Resetn,Q[0]);
dff s1(~Q[1],~Q[0],Resetn,Q[1]);
dff s2(~Q[2],~Q[1],Resetn,Q[2]);
dff s3(~Q[3],~Q[2],Resetn,Q[3]);
endmodule

module dff(D,clock,Resetn,Q);
input D,clock,Resetn;
output reg Q;
always @ (posedge clock or negedge Resetn)
begin
if(!Resetn)
	Q <= 0;
else
	Q <= D;
end
endmodule

