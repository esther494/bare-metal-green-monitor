/*
 * init.c
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#include "init.h"

void Clock_Init(void) {
    // Enable clocks for GPIO ports
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;  // Enable GPIOB clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;  // Enable GPIOC clock

    // Enable clock for ADC
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;    // Enable ADC1 clock

    // Enable clock for DMA
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;    // Enable DMA2 clock

    // Enable clocks for I2C peripherals
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;    // Enable I2C1 clock
    RCC->APB1ENR |= RCC_APB1ENR_I2C3EN;    // Enable I2C3 clock

    // Enable clock for UART
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;  // Enable USART1 clock

    // Configure TIM2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;     // Enable TIM2 clock
    TIM2->PSC = 16000 - 1;                  // Set prescaler to 16000
    TIM2->ARR = 10000 - 1;                  // Set auto-reload value to 10000
    TIM2->CR2 |= TIM_CR2_MMS_1;             // Set Master Mode Selection
    TIM2->CR1 |= TIM_CR1_CEN;               // Enable the timer
}
