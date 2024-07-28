################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AUTOSAR_Implementation/RTE_Generated/Rte_DoorLock_Indication_SWC.c \
../AUTOSAR_Implementation/RTE_Generated/Rte_DoorSensorAbstractionSWC.c 

OBJS += \
./AUTOSAR_Implementation/RTE_Generated/Rte_DoorLock_Indication_SWC.o \
./AUTOSAR_Implementation/RTE_Generated/Rte_DoorSensorAbstractionSWC.o 

C_DEPS += \
./AUTOSAR_Implementation/RTE_Generated/Rte_DoorLock_Indication_SWC.d \
./AUTOSAR_Implementation/RTE_Generated/Rte_DoorSensorAbstractionSWC.d 


# Each subdirectory must supply rules for building sources it contributes
AUTOSAR_Implementation/RTE_Generated/%.o AUTOSAR_Implementation/RTE_Generated/%.su AUTOSAR_Implementation/RTE_Generated/%.cyclo: ../AUTOSAR_Implementation/RTE_Generated/%.c AUTOSAR_Implementation/RTE_Generated/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded courses/AUTOSAR_IN_DEPTH/DoorLock_WS/AUTOSAR_AWSL_STM32Cube_WS/DoorLock_AUTOSAR_Project/HAL/includes" -I"D:/Embedded courses/AUTOSAR_IN_DEPTH/DoorLock_WS/AUTOSAR_AWSL_STM32Cube_WS/DoorLock_AUTOSAR_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-AUTOSAR_Implementation-2f-RTE_Generated

clean-AUTOSAR_Implementation-2f-RTE_Generated:
	-$(RM) ./AUTOSAR_Implementation/RTE_Generated/Rte_DoorLock_Indication_SWC.cyclo ./AUTOSAR_Implementation/RTE_Generated/Rte_DoorLock_Indication_SWC.d ./AUTOSAR_Implementation/RTE_Generated/Rte_DoorLock_Indication_SWC.o ./AUTOSAR_Implementation/RTE_Generated/Rte_DoorLock_Indication_SWC.su ./AUTOSAR_Implementation/RTE_Generated/Rte_DoorSensorAbstractionSWC.cyclo ./AUTOSAR_Implementation/RTE_Generated/Rte_DoorSensorAbstractionSWC.d ./AUTOSAR_Implementation/RTE_Generated/Rte_DoorSensorAbstractionSWC.o ./AUTOSAR_Implementation/RTE_Generated/Rte_DoorSensorAbstractionSWC.su

.PHONY: clean-AUTOSAR_Implementation-2f-RTE_Generated

