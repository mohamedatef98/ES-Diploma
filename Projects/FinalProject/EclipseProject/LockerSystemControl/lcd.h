/*
 * lcd.h
 *
 *  Created on: Oct 15, 2020
 *      Author: engmo
 */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#define RS PC5
#define RW PC6
#define E PC7

#define DATABUS PORTA
#define CTLPORT PORTC
#define DATABUSDIR DDRA
#define CTLPORTDIR DDRC

void LCD_init (void);

void LCD_sendCommand (const uint8 command);

void LCD_sendData (const uint8 data);

void LCD_displayString (const uint8 * str);

void LCD_goToRowCol (const uint8 row, const uint8 col);

void LCD_displayInteger (const uint8 integer);

void LCD_displayHex (const uint8 integer);

void LCD_clearScreen (void);

#endif /* LCD_H_ */
