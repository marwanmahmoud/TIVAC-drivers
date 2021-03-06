#ifndef _pwm_H
#define _pwm_H
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
//#include "TM4C123GH6PM.h"
#define Memory(X,Y)			 	(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
#define PWM_CLOCK ((volatile uint32_t*)0x400FEA40)
#define RCC_PWM  ((volatile uint32_t*)0x400FE060)
#define RCGC_PWM	 ((volatile uint32_t*)0x400FE100)
#define SYSCTL_RCGCGPIO 		((volatile uint32_t*)0x400FE608)
#define RCGC2_REG_GPIO			    ((volatile uint32_t *)0x400FE108)	
typedef enum PWM_Module
{
PWM00 =0x40028000,
PWM01 =0x40029000,
} PWM_Module;
//typedef enum OUTPUT_PIN{
//PIN1,
//PIN2,
//}OUTPUT_PIN;
typedef enum GENERATOR{
GENERATOR1,
GENERATOR2,
GENERATOR3,
GENERATOR4,
}GENERATOR;
typedef enum DUTY_CYCLE{
DUTY_CYCLE_10 = 10,
DUTY_CYCLE_50 = 50,	
DUTY_CYCLE_25 = 25,
DUTY_CYCLE_30 = 30,	
DUTY_CYCLE_40 = 40,	
//DUTY_CYCLE_50 = 50/100 ,	
DUTY_CYCLE_60 = 60,
DUTY_CYCLE_70 = 70,
DUTY_CYCLE_75 = 75,
DUTY_CYCLE_80 = 80,
DUTY_CYCLE_90 = 90,
DUTY_CYCLE_100 = 100,
}DUTY_CYCLE;
typedef enum PWM_Regs{
PWM_ENABLE_R=0x008,
SRPWM=0x540,
PWM_G1_CTL=0x040,
PWM_G2_CTL=0x080,
PWM_G3_CTL=0x0C0, 	
PWM_G4_CTL= 0x100,
PWM_G1_LOAD_R=0x050,
PWM_G2_LOAD_R=0x090,
PWM_G3_LOAD_R=0x0D0,
PWM_G4_LOAD_R=0x110,
PWM_G1_COUNTER_R=0x054,
PWM_G2_COUNTER_R=0x094,
PWM_G3_COUNTER_R=0x0D4,
PWM_G4_COUNTER_R=0x114,
PWM_G1_CMPA_R=0x058,
PWM_G2_CMPA_R=0x098,
PWM_G3_CMPA_R=0x0D8,
PWM_G4_CMPA_R=0x118,
PWM_G1_CMPB_R=0x05C,
PWM_G2_CMPB_R=0x08C,
PWM_G4_CMPB_R=0x0DC,
PWM_G5_CMPB_R=0x11C,
PWM_G1_GENPINA_R=0x060,
PWM_G2_GENPINA_R=0x0A0,
PWM_G3_GENPINA_R=0x0E0,
PWM_G4_GENPINA_R=0x120,
PWM_G1_GENPINB_R=0x064,
PWM_G2_GENPINB_R=0x0A4,
PWM_G3_GENPINB_R=0x0E4,
PWM_G4_GENPINB_R=0x124,
}PWM_Regs;
typedef enum OUTPUT_FREQUANCY{
 FREQUANCY_1HZ =1,
FREQUANCY_1KHZ=1000,
FREQUANCY_2KHZ=2000,
FREQUANCY_3KHZ=3000,
FREQUANCY_4KHZ=4000,	
FREQUANCY_5KHZ=5000,	
FREQUANCY_6KHZ=6000,	
FREQUANCY_7KHZ=7000,	
FREQUANCY_8KHZ=8000,	
FREQUANCY_9KHZ=9000,	
FREQUANCY_10KHZ=10000,
FREQUANCY_11KHZ=11000,
FREQUANCY_12KHZ=12000,	
FREQUANCY_13KHZ=13000,
FREQUANCY_14KHZ=14000,
FREQUANCY_15KHZ=15000,
FREQUANCY_16KHZ=16000,
FREQUANCY_17KHZ=17000,
FREQUANCY_18KHZ=18000,
FREQUANCY_19KHZ=19000,
FREQUANCY_20KHZ=20000,
FREQUANCY_21KHZ=21000,
FREQUANCY_22KHZ=22000,
FREQUANCY_23KHZ=23000,
FREQUANCY_50KHZ=50000,
FREQUANCY_100KHZ=100000,
FREQUANCY_200KHZ=200000,
FREQUANCY_250KHZ=250000,
FREQUANCY_80KHZ=80000,
FREQUANCY_90KHZ=90000,
}OUTPUT_FREQUANCY;
void PWM_GENERATE_SQUARE_WAVE(PWM_Module module,GENERATOR generator,Pin pin ,OUTPUT_FREQUANCY frequancy,DUTY_CYCLE duty);
	void delayMs(int n);
#endif