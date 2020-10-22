/*
 * ADC.c
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */


#include "adc.h"

#ifndef POLLING
	void volatile (*callback) (void) = 0;

ISR(ADC_vect) {
	callback();
}
#endif

void ADC_init (const ADCConfig * const configPtr) {
	ADMUX = configPtr->vref << 6;

	ADCSRA = (1 << ADEN) | (configPtr->prescaler & 0b0111);

	#ifndef POLLING
		ADCSRA =| (1 << ADIE);
	#endif
}

void ADC_readChannel (const uint8 channel_number) {
	ADMUX = (ADMUX & 0xE0) | (channel_number & 0x07);
	ADCSRA |= (1 << ADSC);

	#ifdef POLLING
		while(BIT_IS_CLEAR(ADCSRA, ADIF));
		ADCSRA |= ADIF;
	#endif
}

uint16 ADC_getValue() {
	return ADC;
}

#ifndef POLLING
	void ADC_setCallback (void volatile (*func) (void)) {
		callback = func;
	}
#endif
