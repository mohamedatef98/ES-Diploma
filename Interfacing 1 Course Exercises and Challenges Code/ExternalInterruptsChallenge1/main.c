/*
 * main.c
 *
 *  Created on: Aug 22, 2020
 *      Author: engmo
 */

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char number = 0;

void int2_init(void) {
	// set PB2 as input
	DDRB &= ~(1 << PB2);

	// enable INT2 at rising edges
	MCUCSR |= (1 << ISC2);
	GICR |= (1 << INT2);

	// enable interrupts globally
	SREG |= (1 << 7);
}

ISR(INT2_vect) {
	number++;
	if (number == 10) number = 0;
	PORTC = (PORTC & 0xf0) | (number & 0x0f);
}

int main (void) {
	// portc output
	DDRC = 0xff;
	// display initial number
	PORTC = number;

	int2_init();

	while(1);
}

