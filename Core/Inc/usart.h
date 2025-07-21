/*
 * usart.h
 *
 *  Created on: Oct 23, 2024
 *      Author: esthe
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"  // Include MCU-specific definitions

void USART1_Init(void);
void USART1_Transmit(void);

#endif /* USART_H_ */
