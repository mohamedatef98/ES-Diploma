/*
 * motor.c
 *
 *  Created on: Sep 25, 2020
 *      Author: engmo
 */

#include "pwm.h"
#include "motor.h"

static PWMConfig pwm = { PWM_INV, PWM_FCPU_8 };

void MOTOR_init(void) {
	MOTOR_DDR |= (1 << MOTOR_POS) | (1 << MOTOR_NEG);
	SET_BIT(MOTOR_PORT, MOTOR_POS);
	CLEAR_BIT(MOTOR_PORT, MOTOR_NEG);
	PWM_start(&pwm, 128);
}

void MOTOR_runWithSpeed(const uint8 speed) {
	PWM_start(&pwm, speed);
}

void MOTOR_reverse(void) {
	MOTOR_PORT ^= (1 << MOTOR_POS) | (1 << MOTOR_NEG);
}
