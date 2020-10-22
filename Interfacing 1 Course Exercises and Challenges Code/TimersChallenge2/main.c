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
	OCR0 = 50;
	TCNT0 = 0;
	TIMSK |= (1 << OCIE0);
	SREG |= (1 << 7);
	TCCR0 = (1 << FOC0) | (1 << WGM01) | (1 << CS01);
}

ISR(TIMER0_COMP_vect) {
	count++;
	PORTC ^= (1 << PC0);
	if (count == 2) {
		PORTC ^= (1 << PC1);
	}
	else if (count == 4) {
		PORTC ^= (1 << PC1);
		PORTC ^= (1 << PC2);
		count = 0;
	}
}

int main (void) {
	DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2);
	PORTC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2));
	timer0_init();

	while(1);
}
