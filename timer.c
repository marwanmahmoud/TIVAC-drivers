#include "timer.h"

void SYSTICK_DELAY_1SEC(void)
{
	Memory(SYSTICK,CTRL)=0x00;
	Memory(SYSTICK,RELOAD)=16000000;
	Memory(SYSTICK,CURRENT)=0;
	Memory(SYSTICK,CTRL)|=0x05;
	while((Memory(SYSTICK,CTRL)&0x10000)==0){};
}
void SYSTICK_DELAY_1MSEC(void)
{
	Memory(SYSTICK,CTRL)=0x00;
	Memory(SYSTICK,RELOAD)=16000;
	Memory(SYSTICK,CURRENT)=0;
	Memory(SYSTICK,CTRL)|=0x05;
	while((Memory(SYSTICK,CTRL)&0x10000)==0){};
	
}
void SYSTICK_DELAY_SECS (uint32_t sec)
{
	for(int i=0;i< 3*sec;i++)
	{
		SYSTICK_DELAY_1SEC();
		
	}
}
void SYSTICK_DELAY_MSECS (uint32_t ssec)
{
	for(int i=0;i< 3*ssec;i++)
	{
		SYSTICK_DELAY_1MSEC();
		
	}
}