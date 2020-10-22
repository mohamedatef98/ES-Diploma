/*
 * pwm.c
 *
 *  Created on: Sep 25, 2020
 *      Author: engmo
 */

#include "pwm.h"

void PWM_start(const PWMConfig *const config, const uint8 value) {
	DDRB |= (1 << PB3);
	OCR0 = value;
	TCCR0 = (1 << WGM01) | (1 << WGM00) | ((config->mode & 0b11) << 4)
			| (config->prescaler & 0b111);
}
