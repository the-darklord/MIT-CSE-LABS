		AREA RESET,DATA,READONLY
		EXPORT __Vectors
__Vectors
		DCD 0x10001000
		DCD Reset_Handler
		ALIGN
		AREA mycode,CODE,READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R0,=SRC
		LDR R1,=DST
		MOV R2,#10
UP		LDR R3,[R0],#4
		STR R3,[R1],#4
		SUBS R2,R2,#1
		BNE UP
STOP	
		B STOP
SRC DCD 1,2,3,4,5,6,7,8,9,10
		AREA mydata,DATA,READWRITE
DST DCD 0
		END