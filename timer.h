#ifndef _timer_H
#define _timer_H
#include "stdint.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define Memory(X,Y)			 	(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
#define SYSTICK  0xE000E000
typedef enum systick_reg{
	CTRL = 0x010,
	RELOAD =0x014,
	CURRENT =0x018,
}systick_reg;
void SYSTICK_DELAY_SECS (uint32_t sec);
void SYSTICK_DELAY_1SEC(void);
void SYSTICK_DELAY_MSECS (uint32_t sec);
void SYSTICK_DELAY_1MSEC(void);
#endif