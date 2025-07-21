/*
 * usart.c
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#include "usart.h"

void USART1_Init(void) {
    USART1->CR1 &= ~USART_CR1_UE;  // Disable USART for configuration

    USART1->CR1 &= ~USART_CR1_M;  // Word length = 8 bits
    USART1->CR1 &= ~USART_CR1_PCE;  // No parity control
    USART1->CR2 &= ~USART_CR2_STOP;  // 1 stop bit

    // Baud rate setup (assuming 16 MHz clock and 115200 baud rate)
    USART1->BRR = 138;

    USART1->CR1 |= USART_CR1_TE;  // Enable transmitter
    USART1->CR1 |= USART_CR1_RE;  // Enable receiver (optional, if needed)

    USART1->CR1 |= USART_CR1_UE;  // Enable USART1
}


void USART1_Transmit(void) {
    char * buffer = "Test \n\r";
    for (int i = 0; i < strlen(buffer); i++) {
        USART1->DR = buffer[i];
        while((USART1->SR & USART_SR_TC) == 0);
    }
}
