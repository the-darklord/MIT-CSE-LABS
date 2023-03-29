#include <LPC17xx.h>

unsigned int i,j;
unsigned long LED;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0xFFFFEFFF;
	
	while(1)
	{
		for(LED=0;LED<256;LED++)
		{
			LPC_GPIO0->FIOPIN=LED<<4;
			for(j=0;j<10000;j++);
		}
	}
	
	return 0;
}