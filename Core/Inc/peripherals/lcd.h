/*
 * LCD.h
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#ifndef INC_PERIPHERALS_LCD_H_
#define INC_PERIPHERALS_LCD_H_

#include "delay.h"

#define SLAVE_ADDRESS_LCD 0x4E

void LCD_Send_Command(char cmd);
void LCD_Send_Data(char data);
void LCD_Init(void);
void LCD_Send_String (char *str);
void LCD_Clear_Display (void);
void LCD_Cursor_Position(int row, int col);

#endif /* INC_PERIPHERALS_LCD_H_ */
