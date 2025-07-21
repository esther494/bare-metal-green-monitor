/*
 * am2320.h
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#ifndef INC_PERIPHERALS_AM2320_H_
#define INC_PERIPHERALS_AM2320_H_

#include "stm32f4xx.h"  // Include MCU-specific definitions
#include "delay.h"

void AM2320_Wakeup(void);
void AM2320_Send_Command(void);
void AM2320_Receive(void);

extern uint8_t AM2320_Buffer[8];

#endif /* INC_PERIPHERALS_AM2320_H_ */
