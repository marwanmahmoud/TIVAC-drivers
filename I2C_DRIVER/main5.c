#include  "I2C.h"
void delayMs(int n)
{    int i, j;    for(i = 0 ; i < n; i++)        for(j = 0; j < 3180; j++)            {}  /* do nothing for 1 ms */}
int main()
{
	
	char c='c';
	while(1){
 I2C_Master_init(I2C_Module_0,Standared_Mode);
	Set_Slave_Address ( I2C_Module_0 ,  0x55);
			delayMs(100);
 I2C_Write_Byte ( I2C_Module_0, 'M');		delayMs(100);I2C_Write_Byte ( I2C_Module_0, 'A');		delayMs(100);I2C_Write_Byte ( I2C_Module_0, 'R');		delayMs(100);I2C_Write_Byte ( I2C_Module_0, 'W');		delayMs(100);I2C_Write_Byte ( I2C_Module_0, 'A');		delayMs(100);I2C_Write_Byte ( I2C_Module_0, 'N');
		delayMs(100);  I2C_Write_Byte ( I2C_Module_0, '\n');
	}
	
	
	
	
	
	
	
}