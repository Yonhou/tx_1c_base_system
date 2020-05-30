#include <reg51.h>
#include "led.h"
#include "digit_seg.h"
#include "app_stopwatch.h"
#include "task.h"

#define ISR_T0_INTERVAL 918 //918-1ms,1836-2ms,4589-5ms,9179-10ms,45893-50ms
#define ISR_T1_INTERVAL 45893 //918-1ms,1836-2ms,4589-5ms,9179-10ms,45893-50ms

unsigned char taskCycle_10ms=0;
unsigned char taskCycle_100ms=0;
unsigned int taskCycle_1s=0;

void tsk_cyclic_10ms(void)
{
    
}

void tsk_cyclic_100ms(void)
{
    //digital_seg_cyclic();
}
void tsk_cyclic_1s(void)
{
    led_flow();
	app_stopwatch_main();
	//digital_seg_cyclic();
}
void tsk_init(void)
{
	digital_segment_init();


	//初始化计时器o中断
	TMOD=0x11;
	//T0
	TH0=(65536-ISR_T0_INTERVAL)/256;//晶振频率为11.014357Mhz，机器周期为12/11014357=1.089487112139183us,计1ms需要1000/1.089=918
	TL0=(65536-ISR_T0_INTERVAL)%256;
    //T1
	TH1=(65536-ISR_T1_INTERVAL)/256;//晶振频率为11.014357Mhz，机器周期为12/11014357=1.089487112139183us,计1ms需要1000/1.089=918
	TL1=(65536-ISR_T1_INTERVAL)%256;
	EA=1;
	ET0=1;
	ET1=1;
	TR0=1;
	TR1=1;
}
void tsk_schedule(void)
{
    if(taskCycle_10ms==10)
	{
	    taskCycle_10ms=0;
	    tsk_cyclic_10ms();
	}
	if(taskCycle_100ms==2)
	{
	    taskCycle_100ms=0;
	    tsk_cyclic_100ms();
	}
	if(taskCycle_1s==20)
	{
	    taskCycle_1s=0;
	    tsk_cyclic_1s();
	}
}
void isr_T0() interrupt 1
{
    TH0=(65536-ISR_T0_INTERVAL)/256;
	TL0=(65536-ISR_T0_INTERVAL)%256;
	digital_seg_cyclic();//Try to avoid shedule task in 1ms interrupt.
	
	taskCycle_10ms++;
}

void isr_T1() interrupt 3
{
    TH1=(65536-ISR_T1_INTERVAL)/256;
	TL1=(65536-ISR_T1_INTERVAL)%256;
	//digital_seg_cyclic();//Try to avoid shedule task in 1ms interrupt.
	
	taskCycle_100ms++;
	taskCycle_1s++;
}
