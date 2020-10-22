/*
 * main.c
 *
 *  Created on: Sep 4, 2020
 *      Author: engmo
 */


#include <avr/io.h>
#include <util/delay.h>

void WDT_ON (void) {
	WDTCR = (1 << WDE) | (1 << 1 << WDP2) | (1 << WDP1) | (1 << WDP0);
}

void WDT_OFF (void) {
	WDTCR |= (1 << WDTOE) | (1 << WDE);
	WDTCR = 0;
}

int main(void) {
	DDRB |= (1 << PB3);
	PORTB |= (1 << PB3);
	_delay_ms(1000);
	PORTB &= ~(1 << PB3);
	WDT_ON();
	while(1);
	WDT_OFF();
}
