/*
 * main.c
 *
 *  Created on: Sep 24, 2020
 *      Author: engmo
 */


#include "uart.h"

int main (void) {
	UARTConfig uart = { UART_8_BITS, UART_NO_PARITY, UART_1_STOP_BIT, UART_RX_TX };
	uint8 t;
	UART_init(&uart);

	t = UART_receiveByte();

	DDRA |= 0xff;

	PORTA = t;

	UART_sendString("I am another Micro Like you!");

	while(1);
}
