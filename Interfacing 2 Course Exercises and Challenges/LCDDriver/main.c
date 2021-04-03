/*
 * main.c
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */


#include "LCD.h"

int main (void) {
	uint8 counter = 0;
	LCD_init();


	while(1) {
		LCD_displayInteger(counter++);
		_delay_ms(1000);
		LCD_clearScreen();

	}
}
