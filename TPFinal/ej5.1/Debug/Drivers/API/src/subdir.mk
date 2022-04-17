################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/src/API_debounce.c \
../Drivers/API/src/API_delay.c \
../Drivers/API/src/API_uart.c \
../Drivers/API/src/rtc.c 

OBJS += \
./Drivers/API/src/API_debounce.o \
./Drivers/API/src/API_delay.o \
./Drivers/API/src/API_uart.o \
./Drivers/API/src/rtc.o 

C_DEPS += \
./Drivers/API/src/API_debounce.d \
./Drivers/API/src/API_delay.d \
./Drivers/API/src/API_uart.d \
./Drivers/API/src/rtc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/src/%.o: ../Drivers/API/src/%.c Drivers/API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/CMSIS/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/BSP/STM32F4xx_Nucleo_144" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/Core/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/API/inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/API/src" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/API" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/STM32F4xx_HAL_Driver" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/STM32F4xx_HAL_Driver/Src" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/BSP" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/ej5.1/Drivers/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-src

clean-Drivers-2f-API-2f-src:
	-$(RM) ./Drivers/API/src/API_debounce.d ./Drivers/API/src/API_debounce.o ./Drivers/API/src/API_delay.d ./Drivers/API/src/API_delay.o ./Drivers/API/src/API_uart.d ./Drivers/API/src/API_uart.o ./Drivers/API/src/rtc.d ./Drivers/API/src/rtc.o

.PHONY: clean-Drivers-2f-API-2f-src

