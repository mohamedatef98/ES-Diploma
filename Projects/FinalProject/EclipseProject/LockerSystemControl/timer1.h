/*
 * timer1.h
 *
 *  Created on: Oct 16, 2020
 *      Author: engmo
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

typedef enum {
	TIMER1_COM1A_NORMAL, TIMER1_COM1A_TOGGLE, TIMER1_COM1A_CLEAR, TIMER1_COM1A_SET
} TIMER1COM1AMode;

typedef enum {
	TIMER1_COM1B_NORMAL, TIMER1_COM1B_TOGGLE, TIMER1_COM1B_CLEAR, TIMER1_COM1B_SET
} TIMER1COM1BMode;

typedef enum {
	TIMER1_NORMAL = 0, TIMER1_CTC = 4
} TIMER1WaveGenerationMode;

typedef enum {
	TIMER1_CPU_0, TIMER1_CPU_1, TIMER1_CPU_8, TIMER1_CPU_64, TIMER1_CPU_256, TIMER1_CPU_1024
} TIMER1Prescaler;

typedef struct {
	TIMER1COM1AMode com1aMode;
	TIMER1COM1BMode com1bMode;
	TIMER1WaveGenerationMode waveGenerationMode;
	TIMER1Prescaler prescaler;
} TIMER1Config;

void TIMER1_init(const TIMER1Config * const config);

void TIMER1_count(const uint16 timerValue);

void TIMER1_count10sec(void);

#endif /* TIMER1_H_ */
