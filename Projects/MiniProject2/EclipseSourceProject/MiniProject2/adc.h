/*
 * ADC.h
 *
 *  Created on: Sep 18, 2020
 *      Author: engmo
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

typedef enum {
	ADC_AREF, ADC_AVCC, ADC_INTERNAL_VREF = 3
} VrefConfig;

typedef enum {
	ADC_FCPU_2,
	ADC_FCPU2,
	ADC_FCPU_4,
	ADC_FCPU_8,
	ADC_FCPU_16,
	ADC_FCPU_32,
	ADC_FCPU_64,
	ADC_FCPU_128
} PrescalerConfig;

typedef struct {
	VrefConfig vref;
	PrescalerConfig prescaler;
} ADCConfig;

extern volatile uint16 ADC_value;

void ADC_init(const ADCConfig *const configPtr);

void ADC_readChannel(const uint8 channel_number);

void ADC_setCallback(void volatile (*func)(void));

#endif /* ADC_H_ */
