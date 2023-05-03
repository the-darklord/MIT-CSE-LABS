#include <LPC17xx.h>
void initPWM(void);
void updatePulseWidth(unsigned int pulseWidth);
void delayMS(unsigned int milliseconds);
int main(void)
{
	int pulseWidths[] = {0, 3000, 6000, 9000, 12000, 15000, 18000, 21000, 24000,27000};
	const int numPulseWidths = 10;
	int count=1;
	int dir=0;
	initPWM();
	while(1)
	{
		updatePulseWidth(pulseWidths[count]);
		delayMS(10000);
		if(count == (numPulseWidths-1) || count == 0)
		{
			dir = !dir;
		}
		if(dir)
			count--;
		else
			count++;
	}
}
void initPWM(void)
{
	LPC_PINCON->PINSEL3 |= 0x8000;
	LPC_PWM1->PCR = 0x1000;
	LPC_PWM1->PR = 0;
	LPC_PWM1->MR0 = 30000;
	LPC_PWM1->MCR = (1<<1);
	LPC_PWM1->LER = 0xff;
	LPC_PWM1->TCR = 0x00000002;
	LPC_PWM1->TCR = 0x00000009;
}
void updatePulseWidth(unsigned int pulseWidth)
{
	LPC_PWM1->MR4 = pulseWidth;
	LPC_PWM1->LER = 0xff;
}
void delayMS(unsigned int milliseconds)
{
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = 2;
	LPC_TIM0->TCR = 0x02;
	LPC_TIM0->TCR = 0x01;
	while(LPC_TIM0->TC < milliseconds); 
	LPC_TIM0->TCR = 0x00;
}
