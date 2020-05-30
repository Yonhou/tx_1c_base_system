#include <reg51.h>

#include "task.h"
/*
void delay1s(unsigned int ms)
{
    unsigned char i,j,k;
	for(i=(ms/10);i>0;i--)
	    for(j=20;j>0;j--)
		    for(k=228;k>0;k--);
}*/

void main()
{
    //static unsigned int taskCycle=0;
	tsk_init();
    while(1)
	{
		/*tsk_cyclic_10ms();
		if(taskCycle%10==0)
		{
      		tsk_cyclic_100ms();
		}
		if(taskCycle%100==0)
		{
		    tsk_cyclic_1s();
		}
		taskCycle++;
		if(taskCycle==100)
		{
		    taskCycle=0;
		}
		delay1s(10);*/
	}	
}

