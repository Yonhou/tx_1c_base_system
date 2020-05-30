#include <reg51.h>

#include "task.h"

void main()
{
	tsk_init();
    while(1)
	{
	    tsk_schedule();
	}	
}

