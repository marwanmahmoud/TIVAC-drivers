#include "sysctrl.h"
#include "gpio.h"
#include "common.h"
#include "pwm.h"

int main(){
	
	PWM_GENERATE_SQUARE_WAVE(PWM00,GENERATOR1,PIN1,FREQUANCY_1KHZ,10);
	
	while(1){

	}
}