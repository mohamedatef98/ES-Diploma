/*
 * main.c
 *
 *  Created on: Sep 25, 2020
 *      Author: engmo
 */
#include "motor.h"
#include "adc.h"
#include "lcd.h"
#include "int1.h"

int main(void) {
	ADCConfig adc = { ADC_AREF, ADC_FCPU_8 };
	ADC_init(&adc);

	LCD_init();

	MOTOR_init();

	INT1_init(INT1_RISE);
	INT1_setCallback(MOTOR_reverse);

	SREG |= (1 << 7);

	while (1) {
		uint8 motorSpeed = 0;
		ADC_readChannel(0);
		LCD_clearScreen();

		LCD_displayString("ADC Value: ");
		LCD_displayInteger(ADC_value);

		motorSpeed = ADC_value >> 2;
		MOTOR_runWithSpeed(motorSpeed);
	}
}

