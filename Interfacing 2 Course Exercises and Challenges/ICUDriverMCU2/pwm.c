/*
 * pwm.c
 *
 *  Created on: Oct 7, 2020
 *      Author: engmo
 */

#include "pwm.h"

void PWM_init(const PWMConfig * const config) {
	TCNT0 = 0;
	TCCR0 = 0;
	OCR0 = 0;
	DDRB  = DDRB | (1<<PB3);
	TCCR0 = (((config->mode) & 0b11) << COM00) | (1 << WGM00) | (1 << WGM01) | ((config->prescaler) & 0b111);
}

void PWM_setDutyCycle (const uint8 dutyCycle) {
	OCR0 = dutyCycle;
}
