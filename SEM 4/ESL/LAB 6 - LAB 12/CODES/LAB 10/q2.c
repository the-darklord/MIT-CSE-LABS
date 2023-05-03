#include <LPC17xx.h>

void delay(unsigned int ms)
{
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = 2;
	LPC_TIM0->TCR = 0x02;
	LPC_TIM0->TCR = 0x01;
	while(LPC_TIM0->TC < ms);
	LPC_TIM0->TCR = 0x00;
}

int main(void)
{
	int i=0;
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL1 |= (2<<20);
	while(1)
	{
		for(i=0;i<1023;i++)
			LPC_DAC->DACR=i<<6;
		LPC_DAC->DACR=0<<6;
	}
}
