/*
 * adc.h
 *
 *  Created on: Sep 25, 2024
 *      Author: esthe
 */

#ifndef ADCDMA_H_
#define ADCDMA_H_

#include "stm32f4xx.h"

void ADC_Init(void);
void DMA_Init(void);

extern uint32_t ADC_Buffer[2]; // Declare ADC_Buffer as extern

#endif /* ADCDMA_H_ */
