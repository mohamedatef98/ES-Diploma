/*
 * ADC.c
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */

#include "adc.h"

void volatile (*callback)(void) = 0;

uint16 volatile ADC_value = 0;

ISR(ADC_vect) {
	ADC_value = ADC;
	if (callback != 0)
		callback();
}

void ADC_init(const ADCConfig *const configPtr) {
	ADMUX = configPtr->vref << 6;

	ADCSRA = (1 << ADEN) | (1 << ADIE) | (configPtr->prescaler & 0b0111);
}

void ADC_readChannel(const uint8 channel_number) {
	ADMUX = (ADMUX & 0xE0) | (channel_number & 0x07);
	ADCSRA |= (1 << ADSC);
}

void ADC_setCallback(void volatile (*func)(void)) {
	callback = func;
}
