#ifndef _UART_H
#define _UART_H
//#include "TM4C123GH6PM.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "std_types.h"
#define UART_BUFFER_SIZE 	64
#define Memory(X,Y)			 	(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
//#define BAUD_IDIV(B)		 	(int)(16000000/(16*B))
//#define BAUD_FDIV(B) 		 	(int)(((16000000/(16*B)) - BAUD_IDIV(B))*64)

#define RCGC2_REG				 	((volatile uint32_t *)0x400FE108)	//really don't know why we are using this
#define NVIC_EN0         	((volatile uint32_t*)0xE000E100)
#define SYSCTL_RCGCGPIO 		((volatile uint32_t*)0x400FE608)
#define SYSCTL_RCGCGUART		((volatile uint32_t*)0x400FE618)
#define PORT_A_BASE         0x40004000
#define UART_0_BASE         0x4000C000
#define SYSCTL_PRGPIO_R     0x400FEA08
#define SYSCTL_PRUART_R     0x400FEA18
#define PORT_E_BASE         0x40024000
typedef enum Uart{
	UART00 		,	
	UART11 	,		
	UART22 		,
	UART33 			,
	UART44 			,
	UART55		 ,
	UART66	,
	UART77		,
} Uart;
typedef enum{
  UART0_PINA0=0,
	UART0_PINA1=1,
	UART1_PINB0=0,
	UART1_PINB1=1,
	UART2_PIND6=6,
	UART2_PIND7=7,
	UART3_PINC6=6,
	UART3_PINC7=7,
	UART4_PINC4=4,
	UART4_PINC5=5,
	UART5_PINE4=4,
	UART5_PINE5=5,
  UART6_PIND4=4,
  UART6_PIND5=5,
  UART7_PINE0=0,
  UART7_PINE1=1,	
}UART_PINType;
typedef enum UARTRegistersOffset{
	UART_DATA 			= 0x000,
	UART_RS_EC 			= 0x004,
	UART_FLAG 			= 0x018,
	UART_IBRD 			= 0x024,
	UART_FBRD 			= 0x028,
	UART_LCTL			  = 0x02C,
	UART_CTL			  = 0x030,
	UART_IFLS			  = 0x034,
	UART_IM 			  = 0x038,
	UART_RIS			  = 0x03C,
	UART_MIS			  = 0x040,
	UART_IC			    = 0x044,
	UART_DMACTL			= 0x048,
	UART_PP 			= 0xFC0,
	UART_CC 			= 0xFC8,
} UARTRegistersOffset;
typedef enum{
	DATA=0x00,
	DIR = 0x400,
	ODR =0x50C,
	PUR =0x510,
	PDR = 0x514,
	DEN =0x51C,
	LOCK =0x520,
	CR   =0x524,
  AMSEL =0x528,
	PCTL=0x52C,
	AFSEL =0x420,
}GPIO_REG;

typedef enum UART_BAUDRATE{
	UART_BAUD_300 			  = 300,
	UART_BAUD_1200 		  	= 1200,
	UART_BAUD_2400 		  	= 2400,
	UART_BAUD_4800 			  = 4800,
	UART_BAUD_9600 			  = 9600,
	UART_BAUD_19200 			= 19200,
	UART_BAUD_38400 			= 38400,
	UART_BAUD_57600 			= 57600,
	UART_BAUD_74880 			= 74880,
	UART_BAUD_115200			= 115200,
} UART_BAUDRATE;

void UART_Init(Uart uart, UART_BAUDRATE baudrate);
uint8_t UART_readChar(Uart uart);
void UART_sendChar(Uart uart, const char data);

#endif