/*
 * spi.h
 *
 *  Created on: Oct 11, 2020
 *      Author: engmo
 */

#ifndef SPI_H_
#define SPI_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

typedef enum {
	SPI_DATA_ORDER_MSB, SPI_DATA_ORDER_LSB
} SPIDataOrder;

typedef enum {
	SPI_CLK_POL_IDLE_LOW, SPI_CLK_POL_IDLE_HIGH
} SPIClkPolarity;

typedef enum {
	SPI_LEAD_EDGE, SPI_TRAIL_EDGE
} SPIClkPhase;

typedef enum {
	SPI_CPU_4, SPI_CPU_16, SPI_CPU_64, SPI_CPU_128, SPI_CPU_2, SPI_CPU_8, SPI_CPU_32, SPI_CPU_64_2
} SPIPrescaler;

typedef struct {
	SPIDataOrder dataOrder;
	SPIClkPolarity clkPolarity;
	SPIClkPhase clkPhase;
	SPIPrescaler prescaler;
} SPIMasterConfig;

typedef struct {
	SPIDataOrder dataOrder;
	SPIClkPolarity clkPolarity;
	SPIClkPhase clkPhase;
} SPISlaveConfig;

void SPI_initMaster (const SPIMasterConfig * const config);

void SPI_initSlave (const SPISlaveConfig * const config);

void SPI_sendByte (const uint8 data);

uint8 SPI_receiveByte (void);

void SPI_sendString (const uint8 * str);

void SPI_receiveString (uint8 * str);


#endif /* SPI_H_ */
