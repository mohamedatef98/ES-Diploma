/*
 * LCD.h
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#define RS PD4
#define RW PD5
#define E PD6

#define DATABUS PORTC
#define CTLPORT PORTD
#define DATABUSDIR DDRC
#define CTLPORTDIR DDRD

void LCD_init (void);

void LCD_sendCommand (const uint8 command);

void LCD_sendData (const uint8 data);

void LCD_displayString (const uint8 * str);

void LCD_goToRowCol (const uint8 row, const uint8 col);

void LCD_displayInteger (const uint8 integer);

void LCD_clearScreen (void);


#endif /* LCD_H_ */
