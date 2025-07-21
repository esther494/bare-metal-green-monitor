/*
 * i2c.c
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#include "i2c.h"

void I2C1_Init(void) {
    I2C1->CR1 &= ~I2C_CR1_PE;                            // Turn off I2C1

    I2C1->CR1 = I2C_CR1_SWRST;                           // Reset I2C1
    I2C1->CR1 &= ~I2C_CR1_SWRST;                         // Release reset

    I2C1->CR2 |= 0x10;                                   // Set the peripheral clock frequency (16 MHz)

    I2C1->CCR = 0x50;                                    // Set clock control register value
    I2C1->TRISE = 0x11;                                  // Set rise time register value

    I2C1->CR1 |= I2C_CR1_PE;                             // Enable I2C peripheral
}

void I2C3_Init(void) {
    // Turn off I2C3
    I2C3->CR1 &= ~I2C_CR1_PE;

    // Reset I2C3
    I2C3->CR1 = I2C_CR1_SWRST;
    I2C3->CR1 &= ~I2C_CR1_SWRST;

    // Set I2C3 parameters
    I2C3->CR2 |= 0x10;                       // Set the peripheral clock frequency (assuming 16 MHz here)
    I2C3->CCR = 0x50;                        // Set the I2C3 clock control register
    I2C3->TRISE = 0x11;                      // Set the rise time

    I2C3->CR1 |= I2C_CR1_PE;                 // Enable I2C peripheral
}
