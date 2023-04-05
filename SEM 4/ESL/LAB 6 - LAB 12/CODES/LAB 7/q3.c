#include <LPC17xx.h>

unsigned char array[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int seg_select[4]={0<<23,1<<23,2<<23,3<<23};
unsigned int dig[4]={0,0,0,0};
unsigned int i;

void delay(unsigned int r)
{
	unsigned int t;
	for(t=1;t<=r;t++);
}

void bcd_down()
{
	for(dig[3]=9;dig[3]>=0;dig[3]--)
		{
			for(dig[2]=9;dig[2]>=0;dig[2]--)
		{
			for(dig[1]=9;dig[1]>=0;dig[1]--)
		{
			for(dig[0]=9;dig[0]>=0;dig[0]--)
		{
			for(i=0;i<4;i++)
			{
				LPC_GPIO1->FIOPIN=seg_select[i];
				LPC_GPIO0->FIOPIN=array[dig[i]]<<4;
				delay(100000);
			}
			delay(10000);
			LPC_GPIO0->FIOCLR |= 0xFF0;
		}
		}
		}
		}
}

void bcd_up()
{
	for(dig[3]=0;dig[3]<=9;dig[3]++)
		{
			for(dig[2]=0;dig[2]<=9;dig[2]++)
		{
			for(dig[1]=0;dig[1]<=9;dig[1]++)
		{
			for(dig[0]=0;dig[0]<=9;dig[0]++)
		{
			for(i=0;i<4;i++)
			{
				LPC_GPIO1->FIOPIN=seg_select[i];
				LPC_GPIO0->FIOPIN=array[dig[i]]<<4;
				delay(100000);
			}
			delay(10000);
			LPC_GPIO0->FIOCLR |= 0xFF0;
		}
		}
		}
		}
}

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO0->FIODIR |=0xFF0; 
	LPC_GPIO1->FIODIR |= 0x07800000;
	LPC_GPIO0->FIODIR &= 0xFFFF7FFF;
	while(1)
	{
		if(LPC_GPIO0->FIOPIN&1<<15)
		{
			bcd_down();
			delay(100000);
		}
		else
		{
			bcd_up();
			delay(100000);
		}
	}
	return 0;
}