/*
 * buzzer.h
 *
 *  Created on: Oct 16, 2020
 *      Author: engmo
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#define BUZZER_PIN PB7
#define BUZZER_DDR DDRB
#define BUZZER_PORT PORTB

void Buzzer_init(void);

void Buzzer_buzz(void);

void Buzzer_unBuzz(void);

#endif /* BUZZER_H_ */
