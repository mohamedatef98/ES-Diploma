/*
 * pwm.h
 *
 *  Created on: Sep 25, 2020
 *      Author: engmo
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

typedef enum {
	PWM_INV = 2, PWM_NON_INV = 3
} ModeConfig;

typedef enum {
	PWM_NO_CPU, PWM_FCPU_1, PWM_FCPU_8, PWM_FCPU_64, PWM_FCPU_256, PWM_FCPU_1024
} PrescalerConfig;

typedef struct {
	ModeConfig mode;
	PrescalerConfig prescaler;
} PWMConfig;

void PWM_start(const PWMConfig *const config, const uint8 value);

#endif /* PWM_H_ */
