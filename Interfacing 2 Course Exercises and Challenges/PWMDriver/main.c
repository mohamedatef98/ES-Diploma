/*
 * main.c
 *
 *  Created on: Oct 7, 2020
 *      Author: engmo
 */

#include "pwm.h"

int main(void) {
	PWMConfig pwm = { PWM_NON_INV, PWM_CPU_8 };
	PWM_init(&pwm);

	PWM_setDutyCycle(50);

	while (1) {
		uint8 duty;
		for (duty = 0; duty < 255; duty++) {
			PWM_setDutyCycle(duty);
			_delay_ms(10);
		}
		_delay_ms(100);
		for (duty = 255; duty > 0; duty--) {
			PWM_setDutyCycle(duty);
			_delay_ms(10);
		}
	}
}
