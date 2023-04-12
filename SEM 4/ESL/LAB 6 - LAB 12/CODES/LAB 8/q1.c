#include <LPC17xx.h>
#include "lcd.c"

unsigned char Msg1[16]={"SAIMIHIRNATH"};
unsigned char Msg2[16]={"SHREYASH"};

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	lcd_init();
	lcd_comdata(0x80,0);
	delay_lcd(800);
	lcd_puts(Msg1);
	lcd_comdata(0xC0,0);
	delay_lcd(800);
	lcd_puts(Msg2);
	return 0;
}