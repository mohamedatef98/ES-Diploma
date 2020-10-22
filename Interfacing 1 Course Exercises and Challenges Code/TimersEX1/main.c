/*
 * main.c
 *
 *  Created on: Aug 27, 2020
 *      Author: engmo
 */

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char count = 0;

void timer0_init(void) {
	TCNT0 = 6;
	TIMSK |= (1 << TOIE0);
	TCCR0 = (1 << FOC0) | (1 << CS02) | (1 << CS00);
	SREG |= (1 << 7);
}

ISR(TIMER0_OVF_vect) {
	count++;
	if (count == 2) {
		PORTC ^= (1 << PC0);
		count = 0;
	}
}

int main (void) {
	DDRC |= (1 << PC0);
	timer0_init();
	PORTC &= ~(1 << PC0);

	while(1);
}



