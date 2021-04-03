/*
 * LCD.c
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */


#include "LCD.h"
#include <stdio.h>

void LCD_init (void) {
	DATABUSDIR |= 0xF0; /* Make data pins output */
	DATABUSDIR |= (1 << RS) | (1 << RW) | (1 << E); /* Make Control pins output */

	_delay_ms(20);
	LCD_sendCommand(0x33);
	LCD_sendCommand(0x32);
	LCD_sendCommand(0x28);
	LCD_sendCommand(0x0C);
	LCD_sendCommand(0x06);
	LCD_sendCommand(0x01);
}

void LCD_sendCommand (const uint8 command) {
	DATABUS = (DATABUS & 0x0F) | (command & 0xF0);
	CLEAR_BIT(DATABUS, RS);
	CLEAR_BIT(DATABUS, RW);
	SET_BIT(DATABUS, E);
	_delay_us(1);
	CLEAR_BIT(DATABUS, E);
	_delay_us(200);
	DATABUS = (DATABUS & 0x0F) | (command << 4);
	SET_BIT(DATABUS, E);
	_delay_us(1);
	CLEAR_BIT(DATABUS, E);
	_delay_ms(2);
}

void LCD_sendData (const uint8 data) {
	DATABUS = (DATABUS & 0x0F) | (data & 0xF0);
	SET_BIT(DATABUS, RS);
	CLEAR_BIT(DATABUS, RW);
	SET_BIT(DATABUS, E);
	_delay_us(1);
	CLEAR_BIT(DATABUS, E);
	_delay_us(200);
	DATABUS = (DATABUS & 0x0F) | (data << 4);
	SET_BIT(DATABUS, E);
	_delay_us(1);
	CLEAR_BIT(DATABUS, E);
	_delay_ms(2);
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

void LCD_clearScreen (void) {
	LCD_sendCommand(0x01);
}

