################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/peripherals/am2320.c \
../Core/Src/peripherals/lcd.c 

OBJS += \
./Core/Src/peripherals/am2320.o \
./Core/Src/peripherals/lcd.o 

C_DEPS += \
./Core/Src/peripherals/am2320.d \
./Core/Src/peripherals/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/peripherals/%.o Core/Src/peripherals/%.su Core/Src/peripherals/%.cyclo: ../Core/Src/peripherals/%.c Core/Src/peripherals/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Inc/peripherals -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-peripherals

clean-Core-2f-Src-2f-peripherals:
	-$(RM) ./Core/Src/peripherals/am2320.cyclo ./Core/Src/peripherals/am2320.d ./Core/Src/peripherals/am2320.o ./Core/Src/peripherals/am2320.su ./Core/Src/peripherals/lcd.cyclo ./Core/Src/peripherals/lcd.d ./Core/Src/peripherals/lcd.o ./Core/Src/peripherals/lcd.su

.PHONY: clean-Core-2f-Src-2f-peripherals

