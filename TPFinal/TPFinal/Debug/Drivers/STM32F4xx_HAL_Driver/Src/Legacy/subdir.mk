################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Src/Legacy/%.o: ../Drivers/STM32F4xx_HAL_Driver/Src/Legacy/%.c Drivers/STM32F4xx_HAL_Driver/Src/Legacy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/BSP/STM32F4xx_Nucleo_144" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/Core/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API/inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API/src" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Src" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/BSP" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy

clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy:
	-$(RM) ./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d ./Drivers/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o

.PHONY: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy

