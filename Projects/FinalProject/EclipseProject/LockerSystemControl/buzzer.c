/*
 * buzzer.c
 *
 *  Created on: Oct 16, 2020
 *      Author: engmo
 */


#include "buzzer.h"

void Buzzer_init(void) {
	BUZZER_DDR |= (1 << BUZZER_PIN);
	CLEAR_BIT(BUZZER_PORT, BUZZER_PIN);
}

void Buzzer_buzz(void) {
	SET_BIT(BUZZER_PORT, BUZZER_PIN);
}

void Buzzer_unBuzz(void) {
	CLEAR_BIT(BUZZER_PORT, BUZZER_PIN);
}
