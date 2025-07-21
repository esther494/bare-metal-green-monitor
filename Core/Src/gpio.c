/*
 * gpio.c
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#include "gpio.h"

void GPIO_Init(void) {
    // Initialize PA0 as Moisture Sensor Sensor (ANALOG)
    SET_PIN_MODE(GPIOA, 0, GPIO_MODE_ANALOG);

    // Initialize PA1 as Light Sensor (ANALOG)
    SET_PIN_MODE(GPIOA, 1, GPIO_MODE_ANALOG);

    // Configure PB6 for LCD SCL (I2C1)
    SET_PIN_MODE(GPIOB, 6, GPIO_MODE_AF);                  // Alternate Function Mode
    SET_PIN_OTYPE(GPIOB, 6, GPIO_OTYPE_OPENDRAIN);         // Open-drain
    SET_PIN_SPEED(GPIOB, 6, GPIO_OSPEED_HIGH);             // High Speed
    SET_PIN_AF(GPIOB, 6, GPIO_AF4);                        // AF4
    SET_PIN_PUPD(GPIOB, 6, GPIO_PUPD_PULLUP);              // Pull-up

    // Configure PB7 for LCD SDA (I2C1)
    SET_PIN_MODE(GPIOB, 7, GPIO_MODE_AF);                  // Alternate Function Mode
    SET_PIN_OTYPE(GPIOB, 7, GPIO_OTYPE_OPENDRAIN);         // Open-drain
    SET_PIN_SPEED(GPIOB, 7, GPIO_OSPEED_HIGH);             // High Speed
    SET_PIN_AF(GPIOB, 7, GPIO_AF4);                        // AF4
    SET_PIN_PUPD(GPIOB, 7, GPIO_PUPD_PULLUP);              // Pull-up

    // Configure PA8 for Temperature Sensor SCL (I2C3)
    SET_PIN_MODE(GPIOA, 8, GPIO_MODE_AF);                  // Alternate Function Mode
    SET_PIN_OTYPE(GPIOA, 8, GPIO_OTYPE_OPENDRAIN);         // Open-drain
    SET_PIN_SPEED(GPIOA, 8, GPIO_OSPEED_HIGH);             // High Speed
    SET_PIN_AF(GPIOA, 8, GPIO_AF4);                        // AF4
    SET_PIN_PUPD(GPIOA, 8, GPIO_PUPD_PULLUP);              // Pull-up

    // Configure PC9 for Temperature Sensor SDL (I2C3)
    SET_PIN_MODE(GPIOC, 9, GPIO_MODE_AF);                  // Alternate Function Mode
    SET_PIN_OTYPE(GPIOC, 9, GPIO_OTYPE_OPENDRAIN);         // Open-drain
    SET_PIN_SPEED(GPIOC, 9, GPIO_OSPEED_HIGH);             // High Speed
    SET_PIN_AF(GPIOC, 9, GPIO_AF4);                        // AF4
    SET_PIN_PUPD(GPIOC, 9, GPIO_PUPD_PULLUP);              // Pull-up

    // Configure PA9 for UART Transmit
    SET_PIN_MODE(GPIOA, 9, GPIO_MODE_AF);                  // Alternate Function Mode
    SET_PIN_OTYPE(GPIOA, 9, GPIO_OTYPE_PUSHPULL);          // Push-pull
    SET_PIN_SPEED(GPIOA, 9, GPIO_OSPEED_HIGH);             // High Speed
    SET_PIN_AF(GPIOA, 9, GPIO_AF7);                        // AF7
    SET_PIN_PUPD(GPIOA, 9, GPIO_PUPD_NONE);                // No pull-up, pull-down

    // Configure PA10 for UART Receive
    SET_PIN_MODE(GPIOA, 10, GPIO_MODE_AF);                 // Alternate Function Mode
    SET_PIN_OTYPE(GPIOA, 10, GPIO_OTYPE_PUSHPULL);         // Push-pull
    SET_PIN_SPEED(GPIOA, 10, GPIO_OSPEED_HIGH);            // High Speed
    SET_PIN_AF(GPIOA, 10, GPIO_AF7);                       // AF7
    SET_PIN_PUPD(GPIOA, 10, GPIO_PUPD_NONE);               // No pull-up, pull-down
}
