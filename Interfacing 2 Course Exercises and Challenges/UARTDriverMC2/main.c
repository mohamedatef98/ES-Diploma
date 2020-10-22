/*
 * main.c
 *
 *  Created on: Sep 24, 2020
 *      Author: engmo
 */


#include "uart.h"
#include "lcd.h"

int main (void) {
	uint8 string[100];
	UARTConfig uart = { UART_8_BITS, UART_NO_PARITY, UART_1_STOP_BIT, UART_RX_TX };
	UART_init(&uart);

	LCD_init();

	UART_sendByte(0x02);

	UART_receiveString(string);

	LCD_displayString(string);

	UART_sendString(string);

	while(1) {
	}
}
