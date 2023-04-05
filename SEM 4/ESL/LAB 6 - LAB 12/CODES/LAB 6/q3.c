#include <LPC17xx.h>

unsigned int i,j,c=1;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;
	LPC_GPIO2->FIODIR &= 0XFFFFFFFE;
	
	while(1)
	{
		if(!(LPC_GPIO2->FIOPIN&1<<12))
		{
			for(i=0;i<8;i++)
			{
				LPC_GPIO0->FIOPIN = c<<4;
				for(j=0;j<10000;j++);
				c=c<<1;
			}
			c=1;
		}
		else
		{
			LPC_GPIO0->FIOPIN &= 0xFFFFF00F ;
		}
	}
	
	return 0;
}