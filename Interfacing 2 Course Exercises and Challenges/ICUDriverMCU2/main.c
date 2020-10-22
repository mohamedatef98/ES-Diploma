/*
 * main.c
 *
 *  Created on: Oct 6, 2020
 *      Author: engmo
 */


#include "pwm.h"
#include "adc.h"

int main (void) {
	PWMConfig pwm = { PWM_NON_INV, PWM_CPU_8 };
	ADCConfig adc = { AVCC, ADC_FCPU_8 };

	ADC_init(&adc);

	PWM_init(&pwm);

	while(1) {
		ADC_readChannel(0);
		PWM_setDutyCycle(((float)ADC_getValue() / 1024) * 255);
	}
}
