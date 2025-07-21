/*
 * gpio.h
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f4xx.h"  // Include MCU-specific definitions

// GPIO
#define SET_PIN_MODE(GPIOx, PIN, MODE) (GPIOx->MODER |= (MODE << (PIN * 2)))
#define SET_PIN_OTYPE(GPIOx, PIN, OTYPE) (GPIOx->OTYPER |= (OTYPE << PIN))
#define SET_PIN_SPEED(GPIOx, PIN, SPEED) (GPIOx->OSPEEDR |= (SPEED << (PIN * 2)))
#define SET_PIN_AF(GPIOx, PIN, AF) (GPIOx->AFR[PIN >> 3] |= (AF << ((PIN % 8) * 4)))
#define SET_PIN_PUPD(GPIOx, PIN, PUPD) (GPIOx->PUPDR |= (PUPD << (PIN * 2)))

#define GPIO_MODE_INPUT 0b00
#define GPIO_MODE_OUTPUT 0b01
#define GPIO_MODE_AF 0b10
#define GPIO_MODE_ANALOG 0b11

#define GPIO_OTYPE_PUSHPULL 0b0
#define GPIO_OTYPE_OPENDRAIN 0b1

#define GPIO_OSPEED_LOW 0b00
#define GPIO_OSPEED_MEDIUM 0b01
#define GPIO_OSPEED_HIGH 0b10
#define GPIO_OSPEED_VERYHIGH 0b11

#define GPIO_PUPD_NONE 0b00
#define GPIO_PUPD_PULLUP 0b01
#define GPIO_PUPD_PULLDOWN 0b10
#define GPIO_PUPD_RESERVED 0b11

#define GPIO_AF0  0b0000
#define GPIO_AF1  0b0001
#define GPIO_AF2  0b0010
#define GPIO_AF3  0b0011
#define GPIO_AF4  0b0100
#define GPIO_AF5  0b0101
#define GPIO_AF6  0b0110
#define GPIO_AF7  0b0111
#define GPIO_AF8  0b1000
#define GPIO_AF9  0b1001
#define GPIO_AF10 0b1010
#define GPIO_AF11 0b1011
#define GPIO_AF12 0b1100
#define GPIO_AF13 0b1101
#define GPIO_AF14 0b1110
#define GPIO_AF15 0b1111

void GPIO_Init(void);

#endif /* INC_GPIO_H_ */
