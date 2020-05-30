#include <reg51.h>
#include "beeper.h"
sbit beep=P2^3;
void beeper_request(unsigned char ucBeeperReq)
{
    beep=ucBeeperReq;
}
