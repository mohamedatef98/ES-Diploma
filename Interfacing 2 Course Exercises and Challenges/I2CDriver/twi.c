/*
 * TWI.c
 *
 *  Created on: Oct 14, 2020
 *      Author: engmo
 */

#include "twi.h"

#define TW_STATUS (TWSR & 0xF8)

void TWI_init(const uint8 deviceAddress) {
	TWBR = TW_BR;
	TWSR = TW_PS & 0b11;
	TWAR = deviceAddress << 1;
	TWCR = (1 << TWEN);
}

void TWI_start(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTA);
	while(BIT_IS_CLEAR(TWCR, TWINT));
}

void TWI_stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_write(const uint8 data) {
	TWDR = data;
	TWCR = (1 << TWEN) | (1 << TWINT);
	while(BIT_IS_CLEAR(TWCR, TWINT));
}

uint8 TWI_readWithACK(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
	while(BIT_IS_CLEAR(TWCR, TWINT));
	return TWDR;
}

uint8 TWI_readWithNACK(void) {
	TWCR = (1 << TWEN) | (1 << TWINT);
	while(BIT_IS_CLEAR(TWCR, TWINT));
	return TWDR;
}

uint8 TWI_getStatus (void) {
	return TW_STATUS;
}

