################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/Src/font12.c \
../BSP/Src/font16.c \
../BSP/Src/font20.c \
../BSP/Src/font24.c \
../BSP/Src/font8.c \
../BSP/Src/ili9341.c \
../BSP/Src/l3gd20.c \
../BSP/Src/lcd_log.c \
../BSP/Src/stm32f429i_discovery.c \
../BSP/Src/stm32f429i_discovery_eeprom.c \
../BSP/Src/stm32f429i_discovery_gyroscope.c \
../BSP/Src/stm32f429i_discovery_io.c \
../BSP/Src/stm32f429i_discovery_lcd.c \
../BSP/Src/stm32f429i_discovery_sdram.c \
../BSP/Src/stm32f429i_discovery_ts.c \
../BSP/Src/stmpe811.c 

OBJS += \
./BSP/Src/font12.o \
./BSP/Src/font16.o \
./BSP/Src/font20.o \
./BSP/Src/font24.o \
./BSP/Src/font8.o \
./BSP/Src/ili9341.o \
./BSP/Src/l3gd20.o \
./BSP/Src/lcd_log.o \
./BSP/Src/stm32f429i_discovery.o \
./BSP/Src/stm32f429i_discovery_eeprom.o \
./BSP/Src/stm32f429i_discovery_gyroscope.o \
./BSP/Src/stm32f429i_discovery_io.o \
./BSP/Src/stm32f429i_discovery_lcd.o \
./BSP/Src/stm32f429i_discovery_sdram.o \
./BSP/Src/stm32f429i_discovery_ts.o \
./BSP/Src/stmpe811.o 

C_DEPS += \
./BSP/Src/font12.d \
./BSP/Src/font16.d \
./BSP/Src/font20.d \
./BSP/Src/font24.d \
./BSP/Src/font8.d \
./BSP/Src/ili9341.d \
./BSP/Src/l3gd20.d \
./BSP/Src/lcd_log.d \
./BSP/Src/stm32f429i_discovery.d \
./BSP/Src/stm32f429i_discovery_eeprom.d \
./BSP/Src/stm32f429i_discovery_gyroscope.d \
./BSP/Src/stm32f429i_discovery_io.d \
./BSP/Src/stm32f429i_discovery_lcd.d \
./BSP/Src/stm32f429i_discovery_sdram.d \
./BSP/Src/stm32f429i_discovery_ts.d \
./BSP/Src/stmpe811.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/Src/%.o: ../BSP/Src/%.c BSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/fhnw/mspr/workspace/V2_FreeRTOS_Intro/App/Inc" -I"C:/fhnw/mspr/workspace/V2_FreeRTOS_Intro/BSP/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

