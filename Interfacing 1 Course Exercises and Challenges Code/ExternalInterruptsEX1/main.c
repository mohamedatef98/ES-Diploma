/*
 * main.c
 *
 *  Created on: Aug 22, 2020
 *      Author: engmo
 */

#include <avr/io.h>
#include <avr/interrupt.h>

void int0_init(void) {
	MCUCR |= (1 << ISC00) | (1 << ISC01);
	GICR |= (1 << INT0);
	DDRD &= ~(1 << PD3);
	SREG |= (1 << 7);
}

ISR(INT0_vect) {
	PORTC ^= (1 << PC0);
}

int main (void) {
	int0_init();
	DDRC |= (1 << PC0);
	PORTC |= (1 << PC0);

	while(1);
}
