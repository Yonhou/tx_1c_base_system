#include <reg51.h>
#include <intrins.h>
#include "led.h"
void led_flow(void)//��������LED
{
    static unsigned char aa=0xFE;
	//�����
	P1=aa;
	aa=_crol_(aa,1);
}