#include <reg51.h>
#include "lcd.h"

sbit lcd_en=P3^4;
sbit lcd_rs=P3^5;
sbit lcd_dula=P2^6;
sbit lcd_wela=P2^7;

void delay()
{
    unsigned char i,j;
	for(i=5;i>0;i--)
	    for(j=110;j>0;j--);
}

void lcd_wr_cmd(unsigned char cmd)
{
    lcd_rs=0;
	P0=cmd;
	delay();
	lcd_en=1;
	delay();
	lcd_en=0;
}

void lcd_wr_data(unsigned char dat)
{
    lcd_rs=1;
	P0=dat;
	delay();
	lcd_en=1;
	delay();
	lcd_en=0;
}

void lcd_init(void)
{
    lcd_dula=0;
	lcd_wela=0;
	lcd_en=0;
	lcd_wr_cmd(0x38);
	lcd_wr_cmd(0x0c);
	lcd_wr_cmd(0x06);
	lcd_wr_cmd(0x01);
	
}

void lcd_show(unsigned char line,unsigned char text[],unsigned char ucLength)
{
    unsigned char index=0;
	if(line==1)
	{
	    lcd_wr_cmd(0x80);
	}
	else
	{
	    lcd_wr_cmd(0x80+0x40);
	}
    for(index=0;index<ucLength;index++)
	{
	    lcd_wr_data(text[index]);
	}
}
