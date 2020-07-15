#ifndef _FLASH_H
#define _FLASH_H
#include "stdint.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define FLASH_BASE_ADDR			((volatile uint32_t*)0x00020000)//Second half of flash region in flash 
#define FLASH_BASE_REG      ((volatile uint32_t*) 0x400FD000)
#define Memory(X,Y)			 	(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
typedef enum FLASH_REG
{

FLASH_ADDRESSE_RE= 0x000,
FLASH_DATA_R=0x004,
FLASH_CONTOL_R =0x008,
FLASH_BOOTCFG_R=0x1D0
}FLASH_REG;

void Flash_Enable(void);
int Flash_Erase(int blockCount);
int Flash_Write(const void* data, int wordCount);
void Flash_Read(void* data, int wordCount);

#endif