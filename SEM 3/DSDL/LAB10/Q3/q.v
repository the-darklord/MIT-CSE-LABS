module jkff(J,K,clock,Resetn,Q);
input J,K,clock,Resetn;
output reg Q;
wire [1:0] c;
assign c[0]=K;
assign c[1]=J;
always @ (posedge clock)
begin

if(Resetn)
	Q <= 0;
else
	begin
		case(c)
		0:Q<=Q;
		1:Q<=0;
		2:Q<=1;
		3:Q<=~Q;
		endcase
	end

end
endmodule
