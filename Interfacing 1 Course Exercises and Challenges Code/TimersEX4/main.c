/*
 * main.c
 *
 *  Created on: Sep 4, 2020
 *      Author: engmo
 */


#include <avr/io.h>
#include <util/delay.h>

void PWM_TIMER0_init (const unsigned char OCR) {
	DDRB |= (1 << PB3);
	TCNT0 = 0;
	OCR0 = OCR;
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
}

int main (void) {
	while(1) {
		PWM_TIMER0_init(128);
		_delay_ms(2000);
		PWM_TIMER0_init(64);
		_delay_ms(2000);
	}
}
