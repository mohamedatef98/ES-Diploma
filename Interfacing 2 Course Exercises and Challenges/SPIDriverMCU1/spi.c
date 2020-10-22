/*
 * spi.c
 *
 *  Created on: Oct 11, 2020
 *      Author: engmo
 */

#include "spi.h"

void SPI_initMaster (const SPIMasterConfig * const config) {
	DDRB |= (1 << PB4) | (1 << PB5) | (1 << PB7);
	DDRB &= ~(1 << PB6);

	SPSR = (SPSR & 0xfe) | ((config->prescaler >> 2) & 0b1 << SPI2X);

	SPCR = (1 << SPE) | ((config->dataOrder & 0b1) << DORD) | (1 << MSTR) |
			((config->clkPolarity & 0b1) << CPOL) | ((config->clkPhase & 0b1) << CPHA) |
			(config->prescaler & 0b11);
}

void SPI_initSlave (const SPISlaveConfig * const config) {
	DDRB &= (1 << PB4) | (1 << PB5) | (1 << PB7);
	DDRB |= (1 << PB6);

	SPCR = (1 << SPE) | ((config->dataOrder & 0b1) << DORD) |
			((config->clkPolarity & 0b1) << CPOL) | ((config->clkPhase & 0b1) << CPHA);
}

void SPI_sendByte (const uint8 data) {
	SPDR = data;

	while(BIT_IS_CLEAR(SPSR, SPIF));
}

uint8 SPI_receiveByte (void) {
	while(BIT_IS_CLEAR(SPSR, SPIF));

	return SPDR;
}

void SPI_sendString (const uint8 * str) {
	while(*str) SPI_sendByte(*str++);

	SPI_sendByte('#');
}


void SPI_receiveString (uint8 * str) {
	uint8 t;
	while((t = SPI_receiveByte()) != '#') *str++ = t;

	*str = '\0';
}
