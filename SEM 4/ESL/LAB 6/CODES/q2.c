#include <LPC17xx.h>

unsigned int i,j;

void delay(unsigned int r)
{
	unsigned int t;
	for(t=0;t<r;t++);
	return ;
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;
	LPC_GPIO2->FIODIR &= 0xFFFFEFFF;
	
	while(1)
	{
		if(LPC_GPIO2->FIOPIN&1<<12)
		{
			for(i=0;i<256;i++)
			{
				LPC_GPIO0->FIOPIN=i<<4;
				delay(100000);
			}
		}
		else
		{
			for(j=255;j>0;j--)
			{
				LPC_GPIO0->FIOPIN=j<<4;
				delay(100000);
			}
		}
	}
	
	return 0;
}