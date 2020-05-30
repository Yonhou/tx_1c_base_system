#include <reg51.h>
#include <intrins.h>
sbit light1=P1^0;
void delay1s(unsigned int ms)
{
    unsigned char i,j,k;
	for(i=(ms/10);i>0;i--)
	    for(j=20;j>0;j--)
		    for(k=228;k>0;k--);
}
void main()
{
    unsigned char aa=0xFE;
    while(1)
	{
        //≈‹¬Ìµ∆
	    P1=aa;
		delay1s(200);
		aa=_crol_(aa,1);
	}
	
}

