/*
 * pwm.h
 *
 *  Created on: Oct 7, 2020
 *      Author: engmo
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

typedef enum {
	PWM_NON_INV = 2, PWM_INV = 3
} PWMMode;


typedef enum {
	PWM_CPU_0, PWM_CPU_1, PWM_CPU_8, PWM_CPU_64, PWM_CPU_256, PWM_CPU_1024
} PWMPrescaler;

typedef struct {
	PWMMode mode;
	PWMPrescaler prescaler;
} PWMConfig;

void PWM_init(const PWMConfig * const config);

void PWM_setDutyCycle(const uint8 dutyCycle);

#endif /* PWM_H_ */
