/*
 * main.c
 *
 *  Created on: Oct 14, 2020
 *      Author: engmo
 */

#include "eeprom.h"

int main (void) {
	uint8 d;
	EEPROM_init();
	DDRD = 0xff;
	DDRA = 0xff;
	DDRB = 0xff;

	PORTA = EEPROM_writeByte(0x0002, 0xAA);

	_delay_ms(1000);

	PORTB = EEPROM_readByte(0x0002, &d);
	PORTD = d;


	while(1);
}
