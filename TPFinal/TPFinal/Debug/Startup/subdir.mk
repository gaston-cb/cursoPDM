################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f429xx.s 

OBJS += \
./Startup/startup_stm32f429xx.o 

S_DEPS += \
./Startup/startup_stm32f429xx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/BSP/STM32F4xx_Nucleo_144" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/Core/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API/inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API/src" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/API" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/STM32F4xx_HAL_Driver/Src" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/BSP" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/TPFinal/TPFinal/Drivers/CMSIS" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f429xx.d ./Startup/startup_stm32f429xx.o

.PHONY: clean-Startup

