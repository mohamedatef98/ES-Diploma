/*
 * main.c
 *
 *  Created on: Oct 11, 2020
 *      Author: engmo
 */


#include "spi.h"
#include "LCD.h"

int main (void) {
	uint8 data;
	SPISlaveConfig spi = { SPI_DATA_ORDER_LSB, SPI_CLK_POL_IDLE_LOW, SPI_LEAD_EDGE };
	SPI_initSlave(&spi);

	LCD_init();

	while(1) {
		data = SPI_receiveByte();
		LCD_sendData(data);
	}
}
