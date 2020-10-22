/*
 * uart.h
 *
 *  Created on: Oct 7, 2020
 *      Author: engmo
 */

#ifndef UART_H_
#define UART_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

#define UART_BAUDRATE 9600

typedef enum {
	UART_NO_RX_TX, UART_TX, UART_RX, UART_RX_TX
} UARTMode;

typedef enum {
	UART_5_BITS, UART_6_BITS, UART_7_BITS, UART_8_BITS
} UARTCharacterSize;

typedef enum {
	UART_NO_PARITY = 0, UART_EVEN_PARITY = 2, UART_ODD_PARITY = 3
} UARTParity;

typedef enum {
	UART_1_STOP_BIT, UART_2_STOP_BIT
} UARTStopBit;

typedef struct {
	UARTCharacterSize characterSize;
	UARTParity parity;
	UARTStopBit stopBit;
	UARTMode mode;
} UARTConfig;

void UART_init(const UARTConfig * const config);

void UART_sendByte(const uint8 data);

uint8 UART_receiveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str);

#endif /* UART_H_ */
