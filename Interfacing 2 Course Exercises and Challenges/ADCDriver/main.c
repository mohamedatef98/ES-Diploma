/*
 * main.c
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */


#include "LCD.h"
#include "ADC.h"

void printValue (void) {
	uint8 temperature = value * 150 / 307;
	LCD_clearScreen();
	LCD_displayString("Temp: ");
	LCD_displayInteger(temperature);
	LCD_displayString("°C.");
}

int main (void) {
	ADCConfig adc1 = { AVCC, FCPU_8 };
	LCD_init();
	ADC_init(&adc1);
	sei();

	while (1) {
		ADC_readChannel(0);
		ADC_setCallback(printValue);
		_delay_ms(10);
	}
}
