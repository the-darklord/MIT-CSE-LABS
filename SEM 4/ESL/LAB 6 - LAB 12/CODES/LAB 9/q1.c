#include<LPC17xx.h>
#include<stdio.h>
#include "lcd.c"
#define Ref_Vtg 3.300
#define Full_Scale 0xFFF
int main(void)
{
	unsigned long adc_temp;
	unsigned int i;
	float in_vtg;
	unsigned char vtg[7], dval[7];
	unsigned char Msg3[11] = {"ANALOG IP:"};
	unsigned char Msg4[12] = {"ADC OUTPUT:"};
	
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_SC->PCONP |= (1<<15);
	lcd_init();
	
	LPC_PINCON->PINSEL3 |= 0xC0000000;
	LPC_SC->PCONP |= (1<<12);
	
	SystemCoreClockUpdate();
	
	lcd_comdata(0x80, 0);
	delay_lcd(800);
	lcd_puts(&Msg3[0]);
	
	lcd_comdata(0xC0, 0);
	delay_lcd(800);
	lcd_puts(&Msg4[0]);
	
	while(1)
	{
		LPC_ADC->ADCR = (1<<5)|(1<<21)|(1<<24); 
		
		while(!(LPC_ADC->ADDR5 & 0x80000000));
		
		adc_temp = LPC_ADC->ADDR5;adc_temp >>= 4;
		adc_temp &= 0x00000FFF;
		in_vtg = (((float)adc_temp * (float)Ref_Vtg))/((float)Full_Scale);
		sprintf(vtg, "%3.2fV", in_vtg);
		sprintf(dval, "%x", adc_temp);
		
		for(i=0; i<2000; i++);
		
		lcd_comdata(0x8B, 0);
		delay_lcd(800);
		lcd_puts(&vtg[0]);
		
		lcd_comdata(0xCC, 0);
		delay_lcd(800);
		lcd_puts(&dval[0]);
		
		for(i=0;i<200000;i++);
		for(i=0;i<7;i++)
		vtg[i] = dval[i] = 0x00;
		adc_temp = 0;
		in_vtg = 0;
	}
}
