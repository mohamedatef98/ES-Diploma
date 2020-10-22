/*
 * int1.c
 *
 *  Created on: Sep 25, 2020
 *      Author: engmo
 */

#include "int1.h"

static volatile void (*callback)(void) = 0;

ISR(INT1_vect) {
	if (callback != 0)
		callback();
}

void INT1_init(const INT1SenseControlConfig sc) {
	GICR |= (1 << INT1);
	MCUCR = (MCUCR & 0xf3) | ((sc & 0b11) << 2);
}

void INT1_setCallback(void (*func)(void)) {
	callback = func;
}
