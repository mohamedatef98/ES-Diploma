/*
 * main.c
 *
 *  Created on: Sep 4, 2020
 *      Author: engmo
 */
#include <avr/io.h>


void PWM_TIMER0_init(const unsigned char OCR) {
	DDRB |= (1 << PB3);
	TCNT0 = 0;
	OCR0 = OCR;
	TCNT0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
	SREG |= 1 << 7;
}

int main (void) {
	PWM_TIMER0_init(128);

	while(1);
}
