/*
 * uart.c
 *
 *  Created on: Oct 7, 2020
 *      Author: engmo
 */


#include "uart.h"

#define BAUD_PRESCALE (((F_CPU / (UART_BAUDRATE * 8UL))) - 1)

void UART_init(const UARTConfig * const config) {
	uint16 baudRate = BAUD_PRESCALE;
	UCSRA |= (1 << U2X);
	UCSRB = (config->mode & 0b11) << TXEN;
	UCSRC = (1 << URSEL) | ((config->parity & 0b11) << UPM0) | ((config->stopBit & 1) << USBS) | ((config->characterSize & 0b11) << UCSZ0);
	UBRRL = baudRate;
	UBRRH = (baudRate >> 8);

}

void UART_sendByte(const uint8 data) {
	while(BIT_IS_CLEAR(UCSRA, UDRE));

	UDR = data;
}

uint8 UART_receiveByte(void) {
	while(BIT_IS_CLEAR(UCSRA, RXC));

	return UDR;
}

void UART_sendString(const uint8 *str) {
	while(*str) UART_sendByte(*str++);
	UART_sendByte('#');
}

void UART_receiveString(uint8 *str) {
	uint8 t, i = 0;
	while((t = UART_receiveByte()) != '#') str[i++] = t;
	str[i] = '\0';
}
