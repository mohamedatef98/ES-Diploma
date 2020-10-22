/*
 * main.c
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */


#include "LCD.h"

int main (void) {
	LCD_init();
	LCD_displayString("M7med");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_goToRowCol(1, 4);
	LCD_displayInteger(30);

	while(1);
}
