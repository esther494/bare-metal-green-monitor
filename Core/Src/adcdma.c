/*
 * adcdma.c
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#include "adcdma.h"

void ADC_Init(void) {
    // Reset CR1 & CR2
    ADC1->CR2 = 0;
    ADC1->CR1 = 0;

    ADC->CCR |= (1U << ADC_CCR_ADCPRE_Pos);             // Set ADC prescaler to divide by 4
    ADC1->CR1 &= ~(3U << ADC_CR1_RES_Pos);              // Clear resolution bits (1 2-bit)

    // ADC1->CR2 |= ADC_CR2_CONT;                       // Set ADC to continuous mode
    ADC1->CR1 |= ADC_CR1_SCAN;                          // Enable scan mode

    ADC1->SMPR2 |= (4U << ADC_SMPR2_SMP0_Pos);          // Set sampling time for channel 0 (PA0)
    ADC1->SMPR2 |= (4U << ADC_SMPR2_SMP1_Pos);          // Set sampling time for channel 1 (PA1)

    ADC1->SQR3 = (1 << ADC_SQR3_SQ2_Pos) | (0 << ADC_SQR3_SQ1_Pos); // Configure sequence order
    ADC1->SQR1 |= 1 << ADC_SQR1_L_Pos;                              // Set number of channels to convert (2 channels)

    ADC1->CR2 |= 0 << 10;                                // EOC configuration (Why set to 0?)
    ADC1->CR2 |= 0b0110 << 24;                           // Set TIM2 TRGO
    ADC1->CR2 |= ADC_CR2_EXTEN_0;                        // Enable external trigger

    ADC1->CR2 |= 1 << 8;                                 // Enable DMA
    ADC1->CR2 |= 1 << 9;                                 // Set DDS

    ADC1->CR2 |= ADC_CR2_ADON;                           // Set ADON bit to enable ADC
    ADC1->CR2 |= ADC_CR2_SWSTART;                        // Start conversion
}

void DMA_Init(void) {
    DMA2_Stream0->CR &= ~DMA_SxCR_EN;                     // Disable DMA Stream 0
    while (DMA2_Stream0->CR & DMA_SxCR_EN);               // Wait until DMA Stream 0 is disabled

    DMA2_Stream0->CR |= (0 << DMA_SxCR_CHSEL_Pos);        // Set Channel 0 for ADC1
    DMA2_Stream0->CR &= ~DMA_SxCR_DIR;                    // Clear direction bits (Peripheral-to-Memory)
    DMA2_Stream0->CR |= (2 << DMA_SxCR_MSIZE_Pos) |       // Set memory data size to 16 bits
                        (2 << DMA_SxCR_PSIZE_Pos);        // Set peripheral data size to 16 bits
    DMA2_Stream0->CR |= DMA_SxCR_MINC;                    // Enable memory increment mode
    DMA2_Stream0->CR |= DMA_SxCR_CIRC;                    // Enable circular mode

    DMA2_Stream0->NDTR = 2;                               // Set number of data items to transfer
    DMA2_Stream0->PAR = (uint32_t)&ADC1->DR;              // Set peripheral address to ADC1 data register
    DMA2_Stream0->M0AR = (uint32_t)ADC_Buffer;            // Set memory address to ADC_Buffer
    DMA2_Stream0->CR |= DMA_SxCR_EN;                      // Enable DMA Stream 0
}
