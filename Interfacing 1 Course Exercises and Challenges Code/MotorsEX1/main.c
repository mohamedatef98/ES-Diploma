/*
 * main.c
 *
 *  Created on: Aug 22, 2020
 *      Author: engmo
 */


#include <avr/io.h>

int main (void) {
	//Set PA0, PA1, PA2 as inputs
	DDRA &= ~((1 << PA0) | (1 << PA1) | (1 << PA2));

	// Set PC0, PC1 as outputs and put zero on them
	DDRC |= (1 << PC0) | (1 << PC1);
	PORTC &= ~((1 << PC0) | (1 << PC1));

	while (1) {
		// if first switch is pressed (PA0 is set) -> clockwise
		if (PINA & (1 << PA0)) {
			PORTC &= ~(1 << PC0);
			PORTC |= (1 << PC1);
		}

		// if second switch is pressed (PA1 is set) -> anti-clockwise
		else if (PINA & (1 << PA1)) {
			PORTC |= (1 << PC0);
			PORTC &= ~(1 << PC1);
		}

		// if third switch is pressed (PA2 is set) -> stop
		else if (PINA & (1 << PA2)) {
			PORTC &= ~(1 << PC0);
			PORTC &= ~(1 << PC1);
		}
	}
}
