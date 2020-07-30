#include "I2C.h"
I2C_PinType SCL,SDL;
uint8_t port=0;
void setPin(I2C_Module Module)
{
	switch(Module) 
	{
		case I2C_Module_0 :
			SDL = I2C_PINB3;
			SCL = I2C_PINB2;
		  port=1;
			break;
		case I2C_Module_1 :
			SDL = I2C_PINA7;
			SCL = I2C_PINA6;
		port=0;
			break;
		case I2C_Module_2 :
			SDL = I2C_PINB5;
			SCL = I2C_PINB4;
		port=1;
			break;
		case I2C_Module_3 :
			SDL = I2C_PIND1;
			SCL = I2C_PIND0;
		port=3;
			break;	
	}
}
void I2C_Master_init (I2C_Module Module ,I2C_Mode mode)
{
	setPin(Module);
	(*SYS_RCGCI2C)|=(1<<Module);
	(*SYSCTL_RCGCGPIO)|=(1<<port);
	Memory(PORTA_BASE+port*0x1000,GPIO_AFSEL_OFFEST)=((1<<SCL)|(1<<SDL));
	Memory(PORTA_BASE+port*0x1000,GPIO_DEN_OFFEST)=((1<<SCL)|(1<<SDL));
	Memory(PORTA_BASE+port*0x1000,GPIO_AMSEL_OFFEST)&=~(0xFF<<SCL*4);
  Memory(PORTA_BASE+port*0x1000,GPIO_PUR_OFFSET	)=((1<<SCL)|(1<<SDL));
	Memory(PORTA_BASE+port*0x1000,GPIO_ODR_OFFSET)=(1<<SDL);
  Memory(PORTA_BASE+port*0x1000,GPIO_PCTL_OFFSET) &=~(0xFF<<SCL*4);
	Memory(PORTA_BASE+port*0x1000,GPIO_PCTL_OFFSET) |=(0x33<<SCL*4);
	Memory (I2C_Module0_BASE+Module*0x1000,I2CMCR)|=(1<<4);
	Memory (I2C_Module0_BASE+Module*0x1000,I2CMTPR)=7;
}
void Set_Slave_Address (I2C_Module Module, uint8_t Address)
{
	Memory(I2C_Module0_BASE+Module*0x1000,I2CMSA) &= ~(0xFE);
  Memory(I2C_Module0_BASE+Module*0x1000,I2CMSA)|=(Address<<1);
}
void I2C_Write_Byte (I2C_Module Module,  uint8_t data)
{
	Memory(I2C_Module0_BASE+Module*0x1000, I2CMSA) &= ~(1<<0);
	Memory (I2C_Module0_BASE+Module*0x1000,I2CMDR)=data;
	Memory (I2C_Module0_BASE+Module*0x1000,I2CMCS)=0x07;
	while ((Memory(I2C_Module0_BASE+Module*0x1000,I2CMCS) &(1<<0)) !=0);
}
uint8_t I2C_readByte(volatile I2C_Module Module)
{
	Memory(I2C_Module0_BASE+Module*0x1000,I2CMSA) |= (1<<0);
	Memory(I2C_Module0_BASE+Module*0x1000, I2CMCS) = 0x07;
	while ((Memory(I2C_Module0_BASE+Module*0x1000,I2CMCS) &(1<<0)) !=0);
	return Memory(I2C_Module0_BASE+Module*0x1000, I2CMDR);
}
void I2C_writeTransaction(volatile I2C_Module Module, char* data){
	Memory(I2C_Module0_BASE+Module*0x1000,I2CMSA) &= ~(1<<0);
	int i=0;
	I2C_Write_Byte(Module, data[i++]); 
	do{
		I2C_Write_Byte(Module, data[i]);  
		i++;
	}while(data[i]!=0);
	
	I2C_Write_Byte(Module, data[i]);  
	for(int j =0 ; j<100 ; j++);
}
