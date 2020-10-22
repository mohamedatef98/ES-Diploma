/*
 * timer1.c
 *
 *  Created on: Oct 16, 2020
 *      Author: engmo
 */


#include "timer1.h"

void TIMER1_init(const TIMER1Config * const config) {
	TCNT1 = 0;
	OCR1A = 0;
	OCR1B = 0;

	TCCR1A = (( config->com1aMode & 0b11 ) << COM1A0) | (( config->com1bMode & 0b11 ) << COM1B0);
	TCCR1B = config->prescaler& 0b111;
	if (config->waveGenerationMode == TIMER1_CTC) {
		TCCR1B |= (1 << WGM12);
	}
}

void TIMER1_count(const uint16 timerValue) {
	TCNT1 = 65535 - timerValue;
	while(BIT_IS_CLEAR(TIFR, TOV1));
	SET_BIT(TIFR, TOV1);
}

void TIMER1_count10sec(void) {
	TIMER1_count(39062);
	TIMER1_count(39062);
}
