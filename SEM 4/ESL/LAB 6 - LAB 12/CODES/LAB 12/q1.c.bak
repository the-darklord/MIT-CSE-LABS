#include <LPC17xx.h>

unsigned long int var1,var2;
unsigned int i=0,j=0,k=0;

void clockwise()
{
	var1=0x8;
	for(i=0;i<=3;i++)
	{
		var1 <<=1;
		LPC_GPIO0->FIOPIN=var1;
		for(k=0;k<3000;k++);
	}
}

void anti_clockwise()
{
	var1=0x100;
	for(i=0;i<=3;i++)
	{
		var1 >>=1;
		LPC_GPIO0->FIOPIN=var1;
		for(k=0;k<3000;k++);
	}
}

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_GPIO0->FIODIR=0xF<<4;
	while(1)
	{
		for(j=0;j<50;j++)
		{
			clockwise();
		}
		for(k=0;k<65000;k++);
		for(j=0;j<50;j++)
		{
			anti_clockwise();
		}
		for(k=0;k<65000;k++);
	}
	
	return 0;
}
