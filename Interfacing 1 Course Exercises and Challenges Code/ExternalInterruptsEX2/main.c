/*
 * main.c
 *
 *  Created on: Aug 22, 2020
 *      Author: engmo
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char flash = 0;

void int1_init(void) {
	// Make INT1 pin output
	DDRD &= ~(1 << PD3);
	// enable pull up res
	PORTD |= (1 << PD3);
	// enable int1 at falling edges
	MCUCR |= (1 << ISC11);
	MCUCR &= ~(1 << ISC10);
	GICR |= (1 << INT1);
	// enable global interrupts
	SREG |= (1 << 7);
}

ISR(INT1_vect) {
	// when button is pressed, we should flash
	flash = 1;
}

int main (void) {
	// leds state
	unsigned char leds = 0b00000001;
	unsigned char i = 0;
	// make portc output and flash first led
	DDRC = 0xff;
	PORTC = leds;
	int1_init();

	while (1) {
		// if we should flash, we flash
		if (flash == 1) {
			for(i = 0; i < 5; i++) {
				PORTC = 0xff;
				_delay_ms(500);
				PORTC = 0x00;
				_delay_ms(500);
			}
			flash = 0;
		}
		// else keep rolling on leds
		else {
			_delay_ms(500);
			leds = leds << 1;
			if (leds == 0) leds = 1;
			PORTC = leds;
		}
	}
}
