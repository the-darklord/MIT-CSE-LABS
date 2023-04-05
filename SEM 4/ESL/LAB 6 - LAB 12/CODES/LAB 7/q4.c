#include <LPC17xx.h>

unsigned char array[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned int seg_select[4]={0<<23,1<<23,2<<23,3<<23};
int dig[4]={0,0,0,0};
unsigned int i;

void delay(unsigned int r)
{
	unsigned int t;
	for(t=1;t<=r;t++);
}

void hex_down()
{
	for(dig[3]=15;dig[3]>=0;dig[3]--)
		{
			for(dig[2]=15;dig[2]>=0;dig[2]--)
		{
			for(dig[1]=15;dig[1]>=0;dig[1]--)
		{
			for(dig[0]=15;dig[0]>=0;dig[0]--)
		{
			for(i=0;i<4;i++)
			{
				LPC_GPIO1->FIOPIN=seg_select[i];
				LPC_GPIO0->FIOPIN=array[i]<<4;
				delay(1000);
			}
			delay(1000);
			LPC_GPIO0->FIOCLR |= 0xFF0;
		}
		}
		}
		}
}

void hex_up()
{
	for(dig[3]=0;dig[3]<=15;dig[3]++)
		{
			for(dig[2]=0;dig[2]<=15;dig[2]++)
		{
			for(dig[1]=0;dig[1]<=15;dig[1]++)
		{
			for(dig[0]=0;dig[0]<=15;dig[0]++)
		{
			for(i=0;i<4;i++)
			{
				LPC_GPIO1->FIOPIN=seg_select[i];
				LPC_GPIO0->FIOPIN=array[dig[i]]<<4;
				delay(1000);
			}
			delay(1000);
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
	LPC_GPIO2->FIODIR &= 0xFFFFFFFE;
	while(1)
	{
		if(LPC_GPIO2->FIOPIN&1)
		{
			hex_down();
			delay(1000);
		}
		else
		{
			hex_up();
			delay(1000);
		}
	}
	return 0;
}