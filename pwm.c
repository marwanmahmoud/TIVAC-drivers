#include "pwm.h"
#include "TM4C123GH6PM.h"
#include "sysctrl.h"
#include "gpio.h"
void delayMs(int n)
{    int i, j;    for(i = 0 ; i < n; i++)        for(j = 0; j < 3180; j++)            {}  /* do nothing for 1 ms */}
	
void PWM_GENERATE_SQUARE_WAVE(PWM_Module module,GENERATOR generator,Pin pin ,OUTPUT_FREQUANCY frequancy,DUTY_CYCLE duty)
{
	if(module==PWM00)
	{
		uint16_t  temp = (16000000UL/frequancy);
	 uint16_t temp1= temp/8;
	
	SYSCTL->RCC &= ~(1 << 20);
	SYSCTL->RCGCPWM |= 1;
	while(!(SYSCTL->PRPWM & 1));
	
	
	SYSCTRL_initGPIO(SYSCTRL_GPIOB);
	GPIO_initPin(GPIOB, PIN6, GPIO_CONF_PREPH);
	GPIO_setPCTL(GPIOB, PIN6, 4);
		Memory(module,PWM_G1_CTL)=0;
		Memory(module,PWM_G1_GENPINA_R)=0x0000008C;
		Memory(module,PWM_G1_LOAD_R)= temp ; /* set load value  */
	Memory(module,PWM_G1_CMPA_R) =temp1 ; /* set duty cycle  */
	  //Memory(module,PWM_G1_LOAD_R)=16000;
		//Memory(module,PWM_G1_CMPA_R)=15555;
		Memory(module,PWM_G1_CTL)=1;
		Memory(module,PWM_ENABLE_R)|=0x01;
//PWM0->_0_CTL = 0; /* stop counter */
//PWM0->_0_GENA = 0x0000008C; /* M1PWM7 output set when reload, */
//	/* clear when match PWMCMPA */
//	//PWM0->_0_LOAD=16000; 
//	//PWM0->_0_CMPA=15000;
	//Memory(module,PWM_G1_LOAD_R)= (uint16_t) (16000000/frequancy); /* set load value  */
	//Memory(module,PWM_G1_CMPA_R) =(uint16_t)(1-duty/100)*(16000000/frequancy) ; /* set duty cycle  */
//	PWM0->_0_CTL = 1; /* start timer */
//	PWM0->ENABLE |= 0x01; /* start PWM0 ch0 */
	}
	
}
	
//	uint32_t delay=0;
//		(*PWM_CLOCK)|=0x01;
//delayMs(100);
//	(*RCGC_PWM)|=0x00100000;
//delayMs(100);
//(*RCC_PWM)&= ~(0x00100000);
//delayMs(100);
//		 if(generator==GENERATOR1)
//		 {
//			
//			 if(pin==PIN1)
//			 {
//			(*SYSCTL_RCGCGPIO)|=0x02;
//				 delayMs(100);
//				// SYSCTL->RCGCGPIO|=0x02;
//				 delay++;
//			(*RCGC2_REG_GPIO)=(1<<2);
//				 	delayMs(100);
//			GPIOB->AFSEL=0x40;
//				 
//			GPIOB->PCTL=0x0400000;
//				 
//			GPIOB->AMSEL=0x00;
//				
//			GPIOB->DEN=(1<<6);
//				
//			GPIOB->DIR=(1<<6);
//				 
//				  Memory(module,PWM_G1_CTL)=0x00000000;
//			 delayMs(100);
//			Memory(module,PWM_G1_GENPINA_R)=0x0000008C;
//				
//			Memory(module,PWM_G1_LOAD_R)=50000;
//				
//			Memory(module,PWM_G1_CMPA_R)=25000;
//			
//			Memory(module,PWM_G1_CTL)|=0x00000001;
//		
//			//Memory(module,SRPWM)=0x01;
//			Memory(module,PWM_ENABLE_R)=(1<<1);
//			

	
	
	
	
	
	
	
	
	
	
	
	
	

	