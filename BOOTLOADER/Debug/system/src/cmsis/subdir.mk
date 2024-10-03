################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/cmsis/system_stm32f4xx.c \
../system/src/cmsis/vectors_stm32f401xc.c 

OBJS += \
./system/src/cmsis/system_stm32f4xx.o \
./system/src/cmsis/vectors_stm32f401xc.o 

C_DEPS += \
./system/src/cmsis/system_stm32f4xx.d \
./system/src/cmsis/vectors_stm32f401xc.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/cmsis/system_stm32f4xx.o: ../system/src/cmsis/system_stm32f4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=24000000 -I"../include" -I"E:\ITI_work\Japanese_University_ARM\workspace\BOOTLOADER\My_Include\03-MCAL\MUSART" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../My_Include/00-LIB" -I"../My_Include/03-MCAL/MGPIO" -I"../My_Include/03-MCAL/MRCC" -I"../My_Include/03-MCAL/MSTK" -I"../My_Include/03-MCAL/MNVIC" -I"../My_Include/03-MCAL/MFLASH" -I"../My_Include/SCHEDULER" -std=gnu11 -Wno-padded -MMD -MP -MF"$(@:%.o=%.d)" -MT"system/src/cmsis/system_stm32f4xx.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/cmsis/%.o: ../system/src/cmsis/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=24000000 -I"../include" -I"E:\ITI_work\Japanese_University_ARM\workspace\BOOTLOADER\My_Include\03-MCAL\MUSART" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../My_Include/00-LIB" -I"../My_Include/03-MCAL/MGPIO" -I"../My_Include/03-MCAL/MRCC" -I"../My_Include/03-MCAL/MSTK" -I"../My_Include/03-MCAL/MNVIC" -I"../My_Include/03-MCAL/MFLASH" -I"../My_Include/SCHEDULER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


