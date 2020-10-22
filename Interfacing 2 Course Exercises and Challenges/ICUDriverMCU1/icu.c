
#include "icu.h"

volatile static void (*callback) (void) = 0;

ISR(TIMER1_CAPT_vect) {
	if (callback) callback();
}

void ICU_init(const ICUConfig * const config) {
	DDRD &= ~(1 << PD6);
	TCNT1 = 0;
	ICR1 = 0;
	TCCR1A = 0;
//	TCCR1B = ((config->edge & 1) << ICES1) | (config->prescaler & 0b111);
	TCCR1B = (TCCR1B & 0xF8) | (config->prescaler);
		/*
	     * insert the required edge type in ICES1 bit in TCCR1B Register
		 */
	TCCR1B = (TCCR1B & 0xBF) | ((config->edge)<<6);
	TIMSK |= (1 << TICIE1);
}

void ICU_setCallBack(void(*a_ptr)(void)) {
	callback = a_ptr;
}

void ICU_setEdgeDetectionType(const ICUEdgeType edgeType) {
	TCCR1B = (TCCR1B & 0xbf) | ((edgeType & 1) << 6);
}

uint16 ICU_getInputCaptureValue(void) {
	return ICR1;
}

void ICU_clearTimerValue(void) {
	TCNT1 = 0;
}

void ICU_DeInit(void) {
	TIMSK &= ~(1 << TICIE1);
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;
}
