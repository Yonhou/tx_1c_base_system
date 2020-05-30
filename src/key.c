#include <reg51.h>
#include "key.h"
sbit key_s2=P3^4;
sbit key_s3=P3^5;
sbit key_s4=P3^6;
sbit key_s5=P3^7;
unsigned char ucKeyPressSts=0x00;
unsigned char ucKeyDebounceCnt=0x00;
void key_main(void)
{
    if(key_s2==0)
	{
	    ucKeyDebounceCnt|=((ucKeyDebounceCnt&0x03)+1);
		if((ucKeyDebounceCnt&0x03)==0x03)
		{
		    ucKeyPressSts|=0x01;
		    ucKeyDebounceCnt&=0xFC;
		}
	}
	else
	{
	    ucKeyPressSts&=0xFC;
	    ucKeyDebounceCnt&=0xFC;
	}
}

unsigned char key_get_sts(void)
{
    return ucKeyPressSts;
}
