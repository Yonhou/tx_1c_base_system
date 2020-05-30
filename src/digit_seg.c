#include <reg51.h>
sbit dula=P2^6;//U1Ëø´æÆ÷Ëø´æ¶Ë
sbit wela=P2^7;//U2Ëø´æÆ÷Ëø´æ¶Ë
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};


void digital_segment_init(void)
{
	wela=1;
	//P0=aa;
	P0=0xC0;
	wela=0;

	//dula=1;
	//P0=0x7F;
	//dula=0;
}
void digital_segment(void)
{
    static unsigned char index=0;
    //ÊýÂë¹Ü
	dula=1;
	P0=table[index];
	dula=0;
	index++;
	if(index>15)
	{
	    index=0;
	}
}