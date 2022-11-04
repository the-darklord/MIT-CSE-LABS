module tff(T,clock,Resetn,Q);
input T,clock,Resetn;
output reg Q;
always @ (negedge clock or negedge Resetn)
begin
if(!Resetn)
	Q <= 0;
else
	if(T)
		Q <= ~Q;
	else
		Q <= Q;
end
endmodule
