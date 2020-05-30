#include <reg51.h>
sbit dula=P2^6;//U1�����������
sbit wela=P2^7;//U2�����������
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char code ucWeTable[]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};//,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
typedef struct{
    unsigned char ucWe;
	unsigned char ucValue;
}stDigitSegSts;
stDigitSegSts ucDigitSegStsVal[]={{0xFF,0x00},{0xFF,0x00},{0xFF,0x00},{0xFF,0x00},{0xFF,0x00},{0xFF,0x00}};//Ĭ�Ϲر����������

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
    //�����
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
