module encoder16to4(i,f);
input [15:0]i;
output reg [4:0]f;
integer j;
always @ (i)
begin
	for(j=0;j<16;j=j+1)
	begin
		if(i[j])
			f=j;
	end
end
endmodule
