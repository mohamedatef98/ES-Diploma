/******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.h
 *
 * Description: Header file for the AVR ICU driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

typedef enum {
	ICU_CPU_0, ICU_CPU_1, ICU_CPU_8, ICU_CPU_64, ICU_CPU_256, ICU_CPU_1024
} ICUPrescaler;

typedef enum {
	ICU_FALL, ICU_RISE
} ICUEdgeType;

typedef struct {
	ICUEdgeType edge;
	ICUPrescaler prescaler;
} ICUConfig;


void ICU_init(const ICUConfig * const Config_Ptr);

void ICU_setCallBack(void(*a_ptr)(void));

void ICU_setEdgeDetectionType(const ICUEdgeType edgeType);

uint16 ICU_getInputCaptureValue(void);

void ICU_clearTimerValue(void);

void ICU_DeInit(void);

#endif /* ICU_H_ */

