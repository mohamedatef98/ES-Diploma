/*
 * main.c
 *
 *  Created on: Oct 11, 2020
 *      Author: engmo
 */


#include "spi.h"

int main (void) {
	uint8 d;
	SPIMasterConfig spi = { SPI_DATA_ORDER_LSB, SPI_CLK_POL_IDLE_LOW, SPI_LEAD_EDGE, SPI_CPU_4 };
	SPI_initMaster(&spi);

	_delay_ms(500);

	while(1) {
		d = Keypad_getPressedKey();
		SPI_sendByte(d);
	}
}
