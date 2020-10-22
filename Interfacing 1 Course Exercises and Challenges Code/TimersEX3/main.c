/*
 * main.c
 *
 *  Created on: Aug 27, 2020
 *      Author: engmo
 */

#include <avr/io.h>
#include <avr/interrupt.h>

void timer0_init(void) {
	OCR0 = 250;
	DDRB |= (1 << PB3);
	TCCR0 = (1 << FOC0) | (1 << WGM01) | (1 << COM00) | (1 << CS00);
}


int main (void) {
	timer0_init();
}
