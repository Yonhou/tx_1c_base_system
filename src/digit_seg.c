#include <reg51.h>
sbit dula=P2^6;//U1锁存器锁存端
sbit wela=P2^7;//U2锁存器锁存端
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
typedef struct{
    unsigned char ucWe;
	unsigned char ucValue;
}stDigitSegSts;
stDigitSegSts ucDigitSegStsVal[]={{0xFE,0x00},{0xFD,0x00},{0xFB,0x00},{0xF7,0x00},{0xEF,0x00},{0xDF,0x00}};//默认关闭所有数码管

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
void digital_seg_cyclic(void)
{
    static unsigned char index=0;
    //数码管
	dula=1;
	P0=ucDigitSegStsVal[index].ucValue;
	dula=0;
    wela=1;
	P0=ucDigitSegStsVal[index].ucWe;
	wela=0;

	index++;
	if(index==(sizeof(ucDigitSegStsVal)/sizeof(stDigitSegSts)))
	{
	    index=0;
	}
}
void digital_seg_switch(unsigned char ucChannel,unsigned char unValue)
{
    if((unValue<=sizeof(table))&&(ucChannel<(sizeof(ucDigitSegStsVal)/sizeof(stDigitSegSts))))
	{
	    ucDigitSegStsVal[ucChannel].ucValue = table[unValue];
	}
}
