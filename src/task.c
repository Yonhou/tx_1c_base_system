#include "led.h"
#include "digit_seg.h"
#include "task.h"

void tsk_cyclic_10ms(void)
{}

void tsk_cyclic_100ms(void)
{
}
void tsk_cyclic_1s(void)
{
    led_flow();
	digital_segment();
}
void tsk_init(void)
{
	digital_segment_init();
}
