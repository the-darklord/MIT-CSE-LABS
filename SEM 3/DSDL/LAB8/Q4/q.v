module encoder4to2(i,f);
input [3:0]i;
output reg [2:0]f;
always @ (i)
begin
casex(i)
	4'b0000:f=3'bxx0;
	4'b0001:f=3'b001;
	4'b001x:f=3'b011;
	4'b01xx:f=3'b101;
	4'b1xxx:f=3'b111;
endcase
end
endmodule
