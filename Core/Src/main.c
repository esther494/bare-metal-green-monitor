#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

#include "stm32f4xx.h"
#include "stdlib.h"

#include "init.h"
#include "gpio.h"
#include "timer.h"
#include "i2c.h"
#include "peripherals/lcd.h"
#include "peripherals/am2320.h"
#include "adcdma.h"
#include "usart.h"

uint32_t ADC_Buffer[2];
uint8_t AM2320_Buffer[8];

uint16_t raw_humidity, raw_temperature;
float humidity = 0, temperature = 0;

void Display_Value(int row, int col, const char *format, ...);

int main(void) {
    // INITIALIZATIONS
    Clock_Init();
    GPIO_Init();
    ADC_Init();
    DMA_Init();
    I2C1_Init();
    I2C3_Init();
    USART1_Init();

    // ADC starts in the initialization functions

    // I2C1
    LCD_Init();
    //LCD_Clear_Display();
    LCD_Cursor_Position(0, 0);
    LCD_Send_String("Humi:");
    LCD_Cursor_Position(1, 0);
    LCD_Send_String("Temp:");
    LCD_Cursor_Position(2, 0);
    LCD_Send_String("Moist:");
    LCD_Cursor_Position(3, 0);
    LCD_Send_String("Light:");

    AM2320_Wakeup();
    AM2320_Send_Command();
    delay_ms(4);
    AM2320_Receive();
    delay_ms(200);

    // USART
    //USART1_Transmit();

    while (1) {
        // READ HUMIDITY AND TEMPERATURE
        AM2320_Wakeup();
        AM2320_Send_Command();
        delay_ms(2);
        AM2320_Receive();
        delay_ms(3000);

        // HANDLE SENSOR DATA HERE
        raw_humidity = (AM2320_Buffer[2] << 8) | AM2320_Buffer[3];
        raw_temperature = (AM2320_Buffer[4] << 8) | AM2320_Buffer[5];

        humidity = raw_humidity / 10;
        temperature = raw_temperature / 10;

        // ADC data (light and moisture level) are sampled by the DMA

        // DISPLAY DATA TO LCD
        Display_Value(0, 5, "%.1f", humidity);
        Display_Value(1, 5, "%.1f", temperature);
        Display_Value(2, 6, "%.lu", ADC_Buffer[0]);
        Display_Value(3, 6, "%.lu", ADC_Buffer[1]);

        delay_ms(3000);
    }
}

void Display_Value(int row, int col, const char * format, ...) {
	char buffer[16];

	va_list var;
	va_start(var, format); // read var after format
	vsprintf(buffer, format, var);
	va_end(var);

	LCD_Cursor_Position(row, col);
	LCD_Send_String(buffer);
}
