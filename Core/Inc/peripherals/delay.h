/*
 * delay.h
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#ifndef INC_PERIPHERALS_DELAY_H_
#define INC_PERIPHERALS_DELAY_H_

#define CLOCK_FREQUENCY 16000000UL // 16 MHz
#define CYCLES_PER_MS (CLOCK_FREQUENCY / 1000)

static inline void delay_ms(uint32_t ms);

static inline void delay_ms(uint32_t ms) {
    uint32_t total_cycles = ms * CYCLES_PER_MS;
    while (total_cycles--) {
        __asm("nop");
    }
}

#endif /* INC_PERIPHERALS_DELAY_H_ */
