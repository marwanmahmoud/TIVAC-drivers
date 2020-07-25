#include "Uart.h"
UART_PINType TX,RX;
uint8_t port;
void setPin(Uart UART)
{
	switch(UART) 
	{
		case UART00 :
			RX = UART0_PINA0;
			TX = UART0_PINA1;
		  port=0;
			break;
		case UART11 :
			RX = UART1_PINB0;
			TX = UART1_PINB1;
		port=1;
			break;
		case UART22 :
			RX = UART2_PIND6;
			TX = UART2_PIND7;
		port=3;
			break;
		case UART33 :
			RX = UART3_PINC6;
			TX = UART3_PINC7;
		port=2;
			break;
		case UART44 :
			RX = UART4_PINC4;
			TX = UART4_PINC5;
		port=2;
			break;
		case UART55 :
			RX = UART5_PINE4;
			TX = UART5_PINE5;
		port=4;
			break;
		case UART66 :
			RX = UART6_PIND4;
			TX = UART6_PIND5;
		port=3;
			break;
		case UART77 :
			RX = UART7_PINE0;
			TX = UART7_PINE1;
		port=4;
			break;
	}
}
void UART_Init(Uart uart, UART_BAUDRATE baudrate)
{
	setPin(uart);
	uint16_t CLCK_DIV =(uint16_t)(50000000/(16*baudrate));
	float32 FRAC_DIV  = ((float32)(50000000/(16*baudrate)) - CLCK_DIV);
	(*SYSCTL_RCGCGUART)|=(1<<uart);
	uint16_t x=0;
	x++;
//	while(!(SYSCTL_PRUART_R & (1<<uart)));
	(*SYSCTL_RCGCGPIO)|=(1<<port);
	x++;
	//while(!(SYSCTL_PRGPIO_R & (1<<port)));
	Memory(UART_0_BASE+(uart*0x1000),UART_CTL)&=~(1<<0);
	if(port == 4 )
	{
		Memory(PORT_E_BASE,DEN)|=((1<<RX)|(1<<TX));
		Memory(PORT_E_BASE,AFSEL)|=((1<<RX)|(1<<TX));
		Memory(PORT_E_BASE,AMSEL)&=~((1<<RX)|(1<<TX));
		Memory(PORT_E_BASE,PCTL)|=(1<<(TX*4))|(1<<(RX*4));
		
	}
	else
	{
		Memory(PORT_A_BASE+(port*0x1000),DEN)|=((1<<RX)|(1<<TX));
		Memory(PORT_A_BASE+(port*0x1000),AFSEL)|=((1<<RX)|(1<<TX));
		Memory(PORT_A_BASE+(port*0x1000),AMSEL)&=~((1<<RX)|(1<<TX));
		Memory(PORT_A_BASE+(port*0x1000),PCTL)|=(1<<(TX*4))|(1<<(RX*4));
	}
	
	Memory(UART_0_BASE+(uart*0x1000),UART_IBRD )=CLCK_DIV;
  Memory(UART_0_BASE+(uart*0x1000),UART_FBRD )=(uint16)((FRAC_DIV*64)+0.5);
	Memory(UART_0_BASE+(uart*0x1000),UART_CC)=0;
	Memory(UART_0_BASE+(uart*0x1000),UART_LCTL)|=0x70;
	Memory(UART_0_BASE+(uart*0x1000),UART_CTL)|=0x301;
	
	
}
void UART_sendChar(Uart uart, char data)
{
	while( ((Memory(UART_0_BASE + uart*0x1000, UART_FLAG)) & 0x0020 ) != 0) ;			// wait until TXFF is 0 (transmitter is  full)
	Memory( UART_0_BASE + uart*0x1000, UART_DATA) = data;
}

uint8_t UART_readChar(Uart uart)
{
	//uint8_t c;
	while((Memory( UART_0_BASE + uart*0x1000, UART_FLAG)&0x0010) != 0);     // wait until RXFE is 0 (reciver is empty)
 // c=Memory(UART_0_BASE + uart*0x1000, UART_DATA);
		return Memory(UART_0_BASE + uart*0x1000, UART_DATA);
}
void print_string(Uart uart,char string[])
{
//	uint8_t i =0 ;
//	while(string[i] == '\0')
//	{
//		UART_sendChar(uart,string[i]);
//		i++;
//	}
	while(*string)
{
UART_sendChar(UART00,*(string++));
}
	
	}
	
	
