module threetoeight(i,f,En);
input [2:0]i;
input En;
output [7:0]f;
wire c1,c2;
assign c1=~i[2]&En;
assign c2=i[2]&En;
twotofour stage0(i[1:0],f[3:0],c1);
twotofour stage1(i[1:0],f[7:4],c2);

endmodule

module twotofour(i,f,En);
input [1:0]i;
input En;
output reg [3:0]f;
always @ (i,En)
begin
if(En)
begin
	if(i[1])
	begin
		if(i[0])
			f=4'b1000;
		else
			f=4'b0100;
	end
	else
	begin
		if(i[0])
			f=4'b0010;
		else
			f=4'b0001;
	end
end
else
begin
	f=4'b0000;
end
end
endmodule
