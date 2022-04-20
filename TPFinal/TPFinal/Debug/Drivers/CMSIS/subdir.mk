################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/system_stm32f4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/%.o: ../Drivers/CMSIS/%.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/BSP/STM32F4xx_Nucleo_144" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/Core/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API/inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API/src" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Src" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/BSP" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32f4xx.d ./Drivers/CMSIS/system_stm32f4xx.o

.PHONY: clean-Drivers-2f-CMSIS

