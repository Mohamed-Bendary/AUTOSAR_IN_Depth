################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AUTOSAR_Implementation/MCAL/DIO.c 

OBJS += \
./AUTOSAR_Implementation/MCAL/DIO.o 

C_DEPS += \
./AUTOSAR_Implementation/MCAL/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
AUTOSAR_Implementation/MCAL/%.o AUTOSAR_Implementation/MCAL/%.su AUTOSAR_Implementation/MCAL/%.cyclo: ../AUTOSAR_Implementation/MCAL/%.c AUTOSAR_Implementation/MCAL/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded courses/AUTOSAR_IN_DEPTH/DoorLock_WS/AUTOSAR_AWSL_STM32Cube_WS/DoorLock_AUTOSAR_Project/HAL/includes" -I"D:/Embedded courses/AUTOSAR_IN_DEPTH/DoorLock_WS/AUTOSAR_AWSL_STM32Cube_WS/DoorLock_AUTOSAR_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-AUTOSAR_Implementation-2f-MCAL

clean-AUTOSAR_Implementation-2f-MCAL:
	-$(RM) ./AUTOSAR_Implementation/MCAL/DIO.cyclo ./AUTOSAR_Implementation/MCAL/DIO.d ./AUTOSAR_Implementation/MCAL/DIO.o ./AUTOSAR_Implementation/MCAL/DIO.su

.PHONY: clean-AUTOSAR_Implementation-2f-MCAL

