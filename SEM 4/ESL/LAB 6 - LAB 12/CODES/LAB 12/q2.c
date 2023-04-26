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
		for(k=0;k<1000;k++);
	}
}

void anti_clockwise()
{
	var1=0x100;
	for(i=0;i<=3;i++)
	{
		var1 >>=1;
		LPC_GPIO0->FIOPIN=var1;
		for(k=0;k<1000;k++);
	}
}

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_GPIO0->FIODIR=0xF<<4;
	LPC_GPIO2->FIODIR &=0xFFFFEFFF;
	while(1)
	{
		if(!(LPC_GPIO2->FIOPIN&1<<12))
		{
			for(j=0;j<50;j++)
			{
				clockwise();
			}
			for(k=0;k<6500;k++);
		}
		else
		{
			for(j=0;j<50;j++)
			{
				anti_clockwise();
			}
			for(k=0;k<6500;k++);
		}
	}
	
	return 0;
}
