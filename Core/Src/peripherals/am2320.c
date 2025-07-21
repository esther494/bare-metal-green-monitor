/*
 * am2320.c
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#include "peripherals/am2320.h"

void AM2320_Wakeup(void) {
    uint8_t reg;
    // START CONDITION
    I2C3->CR1 &= ~I2C_CR1_POS;
    I2C3->CR1 |= I2C_CR1_START;
    while (!(I2C3->SR1 & I2C_SR1_SB));
    reg = I2C3->SR1;

    // SLAVE ADDRESS
    I2C3->DR = 0xB8; // Set slave address
    //while (!(I2C3->SR1 & I2C_SR1_ADDR));
    //reg = I2C3->SR1 | I2C3->SR2; // Clear address flag
    //while (!(I2C3->SR1 & I2C_SR1_TXE)); // Wait until data register is empty

    delay_ms(1);
    // Send a stop signal
    I2C3->CR1 |= I2C_CR1_STOP; // Stop transmission
    reg = I2C3->SR1; // Read status register
    reg = I2C3->SR2; // Read status register 2 to clear flags
}

void AM2320_Send_Command(void) {
    uint8_t reg;
    // START CONDITION
    I2C3->CR1 &= ~I2C_CR1_POS;
    I2C3->CR1 |= I2C_CR1_START;
    while (!(I2C3->SR1 & I2C_SR1_SB));
    reg = I2C3->SR1;

    // SLAVE ADDRESS
    I2C3->DR = 0xB8; // Set slave address
    while (!(I2C3->SR1 & I2C_SR1_ADDR));
    reg = I2C3->SR1 | I2C3->SR2; // Clear address flag
    while (!(I2C3->SR1 & I2C_SR1_TXE)); // Wait until data register is empty

    // SEND CMD
    uint8_t cmd[3] = {0x03, 0x00, 0x04};
    for (int i = 0 ; i < 3; i++) {
        I2C3->DR = cmd[i]; // Send command byte
        while(!(I2C3->SR1 & I2C_SR1_BTF)); // Wait until byte transfer finished
        reg = 0x00; // Clear reg
        reg = I2C3->SR1; // Read status register
        reg = I2C3->SR2; // Read status register 2 to clear flags
    }

    // Send a stop signal
    I2C3->CR1 |= I2C_CR1_STOP; // Stop transmission
    reg = I2C3->SR1; // Read status register
    reg = I2C3->SR2; // Read status register 2 to clear flags
}

void AM2320_Receive(void) {
    uint8_t reg;
    // START CONDITION
    I2C3->CR1 &= ~I2C_CR1_POS;
    I2C3->CR1 |= I2C_CR1_START;
    I2C3 -> CR1 |= I2C_CR1_ACK;
    while (!(I2C3->SR1 & I2C_SR1_SB));
    reg = I2C3->SR1;

    // SLAVE ADDRESS
    I2C3->DR = 0xB9; // Set slave address
    while (!(I2C3->SR1 & I2C_SR1_ADDR));
    reg = I2C3->SR1 | I2C3->SR2; // Clear address flag
    //while (!(I2C3->SR1 & I2C_SR1_TXE)); // Wait until data register is empty
    // you dont need to do this because you are in read mode now

    // READ DATA
    for (int i = 0; i < 8; i++) {
        if (i + 1 == 8) {
            I2C3->CR1 &= ~I2C_CR1_ACK;
            I2C3->CR1 |= I2C_CR1_STOP;
        }
        while (!(I2C3->SR1 & I2C_SR1_RXNE));
        AM2320_Buffer[i] = I2C3->DR;
    }
}
