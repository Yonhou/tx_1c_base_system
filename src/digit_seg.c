#include <reg51.h>
sbit dula=P2^6;//U1Ëø´æÆ÷Ëø´æ¶Ë
sbit wela=P2^7;//U2Ëø´æÆ÷Ëø´æ¶Ë
unsigned char code table[]={0x3f/*0*/,0x06/*1*/,0x5b/*2*/,0x4f/*3*/,0x66/*4*/,0x6d/*5*/,0x7d/*6*/,0x07/*7*/,\
                            0x7f/*8*/,0x6f/*9*/,0x77/*A*/,0x7c/*b*/,0x39/*C*/,0x5e/*d*/,0x79/*E*/,0x71/*F*/,\
							0xBF/*0.*/,0x86/*1.*/,0xdb/*2.*/,0xcf/*3.*/,0xe6/*4.*/,0xed/*5.*/,0xfd/*6.*/,0x87/*7.*/,\
							0xff/*8.*/,0xef/*9.*/};
unsigned char code ucWeTable[]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};//,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
typedef struct{
    unsigned char ucWe;
	unsigned char ucValue;
}stDigitSegSts;
stDigitSegSts ucDigitSegStsVal[]={{0xFF,0x00},{0xFF,0x00},{0xFF,0x00},{0xFF,0x00},{0xFF,0x00},{0xFF,0x00}};//Ä¬ÈÏ¹Ø±ÕËùÓÐÊýÂë¹Ü

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
    //ÊýÂë¹Ü
	P0=0x00;
	dula=1;
	P0=ucDigitSegStsVal[index].ucValue;
	dula=0;
	P0=0xFF;
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
		ucDigitSegStsVal[ucChannel].ucWe=ucWeTable[ucChannel];
	}
}
