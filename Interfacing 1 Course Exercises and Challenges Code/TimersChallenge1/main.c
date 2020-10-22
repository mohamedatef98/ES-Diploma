/*
 * main.c
 *
 *  Created on: Aug 27, 2020
 *      Author: engmo
 */

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char count = 0, number = 0;

void timer0_init (void) {
	TCNT0 = 0;
	TIMSK |= (1 << TOIE0);
	TCCR0 = (1 << FOC0) | (1 << CS02);
	SREG |= (1 << 7);
}

ISR(TIMER0_OVF_vect) {
	count++;
	if(count == 125) {
		number = number == 9 ? 0 : number + 1;
		PORTC = (PORTC & 0xf0) | (number & 0x0f);
		count = 0;
	}
}

int main (void) {
	DDRC |= 0xff;
	PORTC = (PORTC & 0xf0) | (number & 0x0f);
	timer0_init();

	while (1);
}
