#ifndef _I2C_
#define _I2C_
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define SYS_RCGCI2C    ((volatile uint32_t*)0x400FE620)
#define SYSCTL_RCGCGPIO 		((volatile uint32_t*)0x400FE608)
#define RCGC2_REG_GPIO			    ((volatile uint32_t *)0x400FE108)	
#define	PORTA_BASE 									  0x40004000
//Data offset not equal 0x000 as data sheet         
#define GPIO_LOCK_OFFEST							0x520
#define GPIO_CR_OFFSET								0x524
#define GPIO_AFSEL_OFFEST							0x420
#define GPIO_PCTL_OFFSET							0x52C
#define GPIO_AMSEL_OFFEST							0x528
#define GPIO_DEN_OFFEST 							0x51C
#define GPIO_DIR_OFFSET             	0x400
#define GPIO_PUR_OFFSET								0x510
#define GPIO_ODR_OFFSET               0x50C
#define GPIO_PDR_OFFSET								0x514
#define GPIO_IM_OFFSET               	0x410
#define GPIO_IS_OFFSET              	0x404
#define GPIO_RIS_OFFSET               0x414
#define UNLOCK				              	0x4C4F434B
#define I2C_Module0_BASE              0x40020000
#define System_Clock_Freq             50000000
#define Memory(X,Y)			 	(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
 

typedef enum {
I2C_Module_0,
I2C_Module_1,
I2C_Module_2,
I2C_Module_3,
}I2C_Module;

typedef enum {
Standared_Mode =100000,
Fast_Mode = 400000,
Fast_Pulse_Mode=1000000,
Hight_Speed_Mode = 3300000,
}I2C_Mode;
typedef enum {
I2CMSA = 0x000,
I2CMCS = 0x004, 
I2CMDR = 0x008, 
I2CMTPR =0x00C ,
I2CMIMR =0x010,
I2CMRIS=0x014,
I2CMMIS = 0x018 , 


I2CMICR = 0x01C, 
I2CMCR =0x020 ,
I2CMCLKOCNT =0x024 ,
I2CMBMON = 0x02C ,
I2CMCR2 = 0x038,

I2CSOAR =0x800 ,
I2CSCSR = 0x804 ,
I2CSDR =0x808 ,
I2CSIMR =0x80C,
I2CSRIS =0x810,
I2CSMIS=0x814  ,
I2CSICR =0x818,
I2CSOAR2=0x81C,
I2CSACKCTL =0x820,

I2CPP =0xFC0,
I2CPC =0xFC4 
}I2C_REG;
typedef enum{
	I2C_PINB2=2,
	I2C_PINB3=3,
	I2C_PINB4=4,
	I2C_PINB5=5,
	I2C_PINA6=6,
	I2C_PINA7=7,
	I2C_PIND0=0,
	I2C_PIND1=1
}I2C_PinType;
void I2C_Master_init (I2C_Module Module ,I2C_Mode);
void Set_Slave_Address (I2C_Module Module , uint8_t Address);
void I2C_Write_Byte (I2C_Module Module,  uint8_t data);

#endif