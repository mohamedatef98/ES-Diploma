/*
 * main.c
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */


#include "Keypad.h"

int main (void) {
	uint8 key = 0;
	DDRC = 0;
	DDRD |= (1 <<  PD7);

	PORTD &= ~((1 << PD7));

	while(1) {
		key = Keypad_getPressedKey();
		PORTC = key;
	}
}
