void clear_ports()
{
	LPC_GPIO0->FIOCLR =0xF<<23;
	LPC_GPIO0->FIOCLR =1<<27;
	LPC_GPIO0->FIOCLR =1<<28;
}

void delay_lcd(unsigned int r)
{
	unsigned int t;
	for(t=0;t<r;t++);
}

void write(int temp2,int type)
{
	clear_ports();
	LPC_GPIO0->FIOPIN=temp2;
	if(!type)
	{
		LPC_GPIO0->FIOCLR = 1<<27;
	}
	else
	{
		LPC_GPIO0->FIOSET = 1<<27;
	}
	LPC_GPIO0->FIOSET = 1<<28;
	delay_lcd(25);
	LPC_GPIO0->FIOCLR = 1<<28;
	return;
}

void lcd_comdata(int temp1,int type)
{
	int temp2 = temp1&0xF0;
	temp2 <<= 19;
	write(temp2,type);
	temp2=temp1&0x0F;
	temp2 <<= 23;
	write(temp2,type);
	delay_lcd(1000);
	return ;
}

void lcd_init()
{
	LPC_GPIO0->FIODIR |= 0xF<<23|1<<27|1<<28;
	clear_ports();
	delay_lcd(3200);
	
	lcd_comdata(0x33,0);
	delay_lcd(30000);
	
	lcd_comdata(0x32,0);
	delay_lcd(30000);
	
	lcd_comdata(0x28, 0);
	delay_lcd(30000);
	
	lcd_comdata(0x0c, 0);
	delay_lcd(800);

	lcd_comdata(0x06, 0);
	delay_lcd(800);

	lcd_comdata(0x01, 0);
	delay_lcd(10000);
	
	return;
}

void lcd_puts(unsigned char* str)
{
	unsigned int temp3,i=0;
	while(str[i])
	{
		temp3=str[i];
		lcd_comdata(temp3,1);
		i++;
		if(i==16)
		{
			lcd_comdata(0xC0,0);
		}
	}
	return;
}