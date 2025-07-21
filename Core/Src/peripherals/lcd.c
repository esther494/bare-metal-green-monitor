/*
 * lcd.c
 *
 *  Created on: Jul 21, 2025
 *      Author: esthe
 */

#include "peripherals/lcd.h"


void LCD_Send_Command(char cmd) {
    uint16_t reg;
    char data = cmd;

    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (data&0xf0);
    data_l = ((data<<4)&0xf0);
    data_t[0] = data_u|0x0C;  //en=1, rs=0
    data_t[1] = data_u|0x08;  //en=0, rs=0
    data_t[2] = data_l|0x0C;  //en=1, rs=0
    data_t[3] = data_l|0x08;  //en=0, rs=0

    // START CONDITION
    while (I2C1->SR2 & I2C_SR2_BUSY);
    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB));

    // SLAVE ADDRESS
    I2C1->DR = 0x4E; // 0 is write 0x4E for LCD 0x5C << 1 for sensor
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    reg = I2C1->SR1 | I2C1->SR2;

    for (int i = 0; i < 4; i++) {
        I2C1->DR = data_t[i];
        while(!(I2C1 -> SR1 & I2C_SR1_BTF));
    }

    // Send a stop signal
    I2C1->CR1 |= I2C_CR1_STOP;
}

void LCD_Send_Data(char data) {
    uint16_t reg;

    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (data&0xf0);
    data_l = ((data<<4)&0xf0);
    data_t[0] = data_u|0x0D;  //en=1, rs=1
    data_t[1] = data_u|0x09;  //en=0, rs=1
    data_t[2] = data_l|0x0D;  //en=1, rs=1
    data_t[3] = data_l|0x09;  //en=0, rs=1

    // START CONDITION
    I2C1->CR1 &= ~I2C_CR1_POS;
    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB));
    reg = I2C1->SR1;

    // SLAVE ADDRESS
    I2C1->DR = 0x4E; // 0 is write 0x4E for LCD 0x5C << 1 for sensor
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    reg = I2C1->SR1 | I2C1->SR2;
    while (!(I2C1->SR1 & I2C_SR1_TXE));

    for (int i = 0; i < 4; i++) {
        I2C1->DR = data_t[i];
        while(!(I2C1 -> SR1 & I2C_SR1_BTF));
        reg = 0x00;
        reg = I2C1 -> SR1;
        reg = I2C1 -> SR2;
    }

    // Send a stop signal
    I2C1->CR1 |= I2C_CR1_STOP;
    reg = I2C1 -> SR1;
    reg = I2C1 -> SR2;
}

void LCD_Init(void) {
    delay_ms(40);
    LCD_Send_Command(0x30);
    delay_ms(5);
    LCD_Send_Command(0x30);
    delay_ms(1);
    LCD_Send_Command(0x30);
    delay_ms(10);
    LCD_Send_Command(0x20);
    delay_ms(10);

    LCD_Send_Command(0x28);
    delay_ms(1);
    LCD_Send_Command(0x08);
    delay_ms(1);
    LCD_Send_Command(0x01);
    delay_ms(5);
    LCD_Send_Command(0x06);
    delay_ms(1);
    LCD_Send_Command(0x0C);
}

void LCD_Send_String (char *str) {
    while (*str) LCD_Send_Data (*str++);
}

void LCD_Clear_Display (void) {
    LCD_Send_Command (0x80);
    for (int i = 0; i < 70; i++) {
        LCD_Send_Data(' ');
    }
}

void LCD_Cursor_Position (int row, int col) {
    uint8_t address;
    if (row == 0) {
        address = col;
    }
    else if (row == 1) {
        address = 0x40 + col;
    }
    else if (row == 2) {
        address = 0x14 + col;
    }
    else if (row == 3) {
        address = 0x54 + col;
    }
    else {
        return;
    }
    LCD_Send_Command(0x80 | address);
}
