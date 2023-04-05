#include <LPC17xx.h>

unsigned char array[4]={0x06,0x5B,0x4F,0x66};
unsigned int dig_select[4]={0<<23,1<<23,2<<23,3<<23};
unsigned int dig[4]={0,1,2,3};
unsigned int dig_count=0x00;

void delay(unsigned int r)
{
	unsigned int t;
	for(t=1;t<=r;t++);
}

void display()
{
	LPC_GPIO1->FIOPIN=dig_select[dig_count];
	LPC_GPIO0->FIOPIN=array[dig[dig_count]];
	delay(1000);
}

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL3 &= 0xFFC03FFF; 
	LPC_GPIO1->FIODIR |= 0x07800000; 
	while(1)
	{
		delay(100000);
		display();
		dig_count+=1;
		if(dig_count==0x04)
		{
			dig_count=0x00;
		}
	}
	return 0;
}