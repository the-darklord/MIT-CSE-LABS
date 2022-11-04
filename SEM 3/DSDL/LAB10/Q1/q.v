module dff(D,clock,Resetn,Q);
input D,clock,Resetn;
output reg Q;
always @ (posedge clock or posedge Resetn)
begin
if(Resetn)
	Q <= 0;
else
	Q <= D;
end
endmodule
