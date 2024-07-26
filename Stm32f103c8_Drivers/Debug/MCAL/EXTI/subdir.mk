################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTI/EXTI.c 

OBJS += \
./MCAL/EXTI/EXTI.o 

C_DEPS += \
./MCAL/EXTI/EXTI.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTI/EXTI.o: ../MCAL/EXTI/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"E:/GitHubRepo/Master-Embedded-Systems/Stm32f103c8_Drivers/MCAL" -I"E:/GitHubRepo/Master-Embedded-Systems/Stm32f103c8_Drivers/HAL" -I"E:/GitHubRepo/Master-Embedded-Systems/Stm32f103c8_Drivers/MCAL/GPIO" -I"E:/GitHubRepo/Master-Embedded-Systems/Stm32f103c8_Drivers/MCAL/LIBS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/EXTI/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

