/*
 * lcd.c
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */


#include "lcd.h"

#include <stdio.h>

void LCD_init (void) {
	CTLPORTDIR |= (1 << RS) | (1 << RW) | (1 << E);
	DATABUSDIR = ~0;

	LCD_sendCommand(0x38);
	LCD_sendCommand(0x0C);
	LCD_sendCommand(0x01);
}

void LCD_sendCommand (const uint8 command) {
	CLEAR_BIT(CTLPORT, RS);
	CLEAR_BIT(CTLPORT, RW);
	_delay_ms(1);
	SET_BIT(CTLPORT, E);
	_delay_ms(1);
	DATABUS = command;
	_delay_ms(1);
	CLEAR_BIT(CTLPORT, E);
	_delay_ms(1);
}

void LCD_sendData (const uint8 data) {
	SET_BIT(CTLPORT, RS);
	CLEAR_BIT(CTLPORT, RW);
	_delay_ms(1);
	SET_BIT(CTLPORT, E);
	_delay_ms(1);
	DATABUS = data;
	_delay_ms(1);
	CLEAR_BIT(CTLPORT, E);
	_delay_ms(1);
}

void LCD_displayString (const uint8 * str) {
	while(*str) LCD_sendData(*str++);
}

void LCD_goToRowCol (const uint8 row, const uint8 col) {
	uint8 address = 0;
	switch (row) {
	case 0: address = col;
		break;
	case 1: address = 0x40 + col;
		break;
	case 2:	address = 0x10 + col;
		break;
	case 3: address = 0x50 + col;
		break;
	}

	LCD_sendCommand(0x80 | address);
}

void LCD_displayInteger (const uint8 integer) {
	uint8 buffer[16];
	sprintf(buffer, "%d", integer);

	LCD_displayString(buffer);
}

void LCD_displayHex (const uint8 integer) {
	uint8 buffer[16];
	sprintf(buffer, "%x", integer);

	LCD_displayString(buffer);
}

void LCD_clearScreen (void) {
	LCD_sendCommand(0x01);
}

