# Bare-Metal Green Monitor
## Purpose
The purpose of this project is to create a device that displays environmental values such as temperature, humidity, light, and soil moisture. Some household plants are very sensitive to environmental changes, such as Calathea, which can wilt from slight temperature and humidity changes. This device helps users monitor such changes using an LCD display and sensors. In order to reduce system overhead, this project was done in bare-metal without the help of HAL drivers.
## Hardware
| Component                  |      Name      |      Link      |
|----------------------------|:--------------:|:--------------:|
| Microcontroller             | STM32F401RE    | [Link](https://www.st.com/en/microcontrollers-microprocessors/stm32f401re.html) |
| Wifi Microcontroller        | ESP32-DEVKITC-32E | [Link](https://www.espressif.com/en/products/devkits/esp32-devkitc) |
| LCD                        | LCD2004        | [Link](https://www.sunfounder.com/products/i2c-lcd2004-module) |
| Temperature & Humidity Sensor | AM2320       | [Link](https://www.adafruit.com/product/3721) |
| Light Sensor                | DFR0026        | [Link](https://www.dfrobot.com/product-1004.html) |
| Soil Moisture Sensor        | SEN0114        | [Link](https://www.digikey.ca/en/products/detail/dfrobot/SEN0114/6588525) |
### Connections
<img width="808" height="287" alt="Untitled presentation" src="https://github.com/user-attachments/assets/4b1e2f76-31ea-420f-bc6c-4bde3dffcf7a" />

## Software
The program is written in C without the use of HAL drivers. It uses direct hardware register access to configure and program communication protocols. The program consists of initialization files (init.h, gpio.h, timer.h) and communication protocol implementation files (i2c.h, adcdma.h, usart.h).
