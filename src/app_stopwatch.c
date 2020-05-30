#include "digit_seg.h"
#include "key.h"
#include "beeper.h"
#include "lcd.h"
#include "app_stopwatch.h"

unsigned char time[]="It's time now:";
void app_stopwatch_main(void)
{
    static unsigned char hrs=0,mins=0,secs=0;
	secs++;
	beeper_request(1);//关闭蜂鸣器
	if(secs==60)
	{
	    secs=0;
		mins++;
		if(mins==60)
		{
		    beeper_request(0);//整点报时，哈哈
		    mins=0;
			hrs++;
			if(hrs==24)
			{
			    hrs=0;
			}
		}
	}
	if(key_get_sts()!=0)
	{
	    hrs=0;
		mins=0;
		secs=0;
	}
#if !(defined(LCD_EN))
	digital_seg_switch(0,hrs/10);
	digital_seg_switch(1,((hrs%10)+16));
	digital_seg_switch(2,mins/10);
    digital_seg_switch(3,((mins%10)+16));
	digital_seg_switch(4,secs/10);
	digital_seg_switch(5,secs%10);
#else
	lcd_show(1,time,14);
#endif
}
