#include <reg51.h>
#include "led.h"
#include "digit_seg.h"
#include "task.h"

#define ISR_INTERVAL 918 //918-1ms,1836-2ms,4589-5ms,9179-10ms,45893-50ms

unsigned int taskCycle=0;

void tsk_cyclic_10ms(void)
{
    
}

void tsk_cyclic_100ms(void)
{
}
void tsk_cyclic_1s(void)
{
    led_flow();
}
void tsk_init(void)
{
	digital_segment_init();
	digital_seg_switch(0,3);
	digital_seg_switch(2,10);

	//��ʼ����ʱ��o�ж�
	TMOD=0x01;
	TH0=(65536-ISR_INTERVAL)/256;//����Ƶ��Ϊ11.014357Mhz����������Ϊ12/11014357=1.089487112139183us,��1ms��Ҫ1000/1.089=918
	TL0=(65536-ISR_INTERVAL)%256;
	EA=1;
	ET0=1;
	TR0=1;
}

void isr_T0() interrupt 1
{
    TH0=(65536-ISR_INTERVAL)/256;
	TL0=(65536-ISR_INTERVAL)%256;
	digital_seg_cyclic();
	if(taskCycle%10==0)
	{
	    tsk_cyclic_10ms();
	}
	if(taskCycle%100==0)
	{
	    tsk_cyclic_100ms();
	}
	if(taskCycle%1000==0)
	{
	    tsk_cyclic_1s();
	}
	taskCycle++;
	if(taskCycle==1000)
	{
	    taskCycle=0;
	}
}
