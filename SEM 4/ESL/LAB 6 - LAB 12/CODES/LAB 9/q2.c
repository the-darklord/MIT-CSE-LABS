#include<LPC17xx.h>
#include<stdio.h>
#include "lcd.c"
#define Ref_Vtg 3.300
#define Full_Scale 0xFFF

unsigned int i=0;

void ADC4_DVAL(unsigned char vtg[7],unsigned char dval4[7])
{
	unsigned long int adc_temp4;
	float in_vtg;
	LPC_ADC->ADCR = (1<<4)|(0<<5)|(1<<21)|(1<<24); 
		
		while(!(LPC_ADC->ADDR4 & 0x80000000));
		
		adc_temp4 = LPC_ADC->ADDR4;adc_temp4 >>= 4;
		adc_temp4 &= 0x00000FFF;
		in_vtg = (((float)adc_temp4 * (float)Ref_Vtg))/((float)Full_Scale);
		sprintf(vtg, "ADC4 - %3.2fV", in_vtg);
		sprintf(dval4, "%x", adc_temp4);
		
		lcd_comdata(0x80,0);
		delay_lcd(800);
		lcd_puts(vtg);
		
		for(i=0; i<2000; i++);
		for(i=0;i<200000;i++);
		adc_temp4=0;
		in_vtg=0;
}

void ADC5_DVAL(unsigned char vtg[7],unsigned char dval5[7])
{
	unsigned long int adc_temp5;
	float in_vtg;
	LPC_ADC->ADCR = (0<<4)|(1<<5)|(1<<21)|(1<<24); 
		
		while(!(LPC_ADC->ADDR5 & 0x80000000));
		
		adc_temp5 = LPC_ADC->ADDR5;adc_temp5 >>= 4;
		adc_temp5 &= 0x00000FFF;
		in_vtg = (((float)adc_temp5 * (float)Ref_Vtg))/((float)Full_Scale);
		sprintf(vtg, "ADC5 - %3.2fV", in_vtg);
		sprintf(dval5, "%x", adc_temp5);
		
		lcd_comdata(0xC0,0);
		delay_lcd(800);
		lcd_puts(vtg);
		
		for(i=0; i<2000; i++);
		for(i=0;i<200000;i++);
		adc_temp5=0;
		in_vtg=0;
}

int main(void)
{
	unsigned char vtg[7], dval4[7], dval5[7];
	
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_SC->PCONP |= (1<<15);
	lcd_init();
	
	LPC_PINCON->PINSEL3 |= 0xF0000000;
	LPC_SC->PCONP |= (1<<12);
	
	SystemCoreClockUpdate();
	
	while(1)
	{
		ADC4_DVAL(vtg,dval4);
		ADC5_DVAL(vtg,dval5);
		
		for(i=0;i<7;i++)
			vtg[i] = dval5[i] = 0x00;
		
		for(i=0;i<7;i++)
			vtg[i] = dval4[i] = 0x00;
		
	}
}
