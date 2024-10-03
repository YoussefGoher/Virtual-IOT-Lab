################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/diag/trace-impl.c \
../system/src/diag/trace.c 

OBJS += \
./system/src/diag/trace-impl.o \
./system/src/diag/trace.o 

C_DEPS += \
./system/src/diag/trace-impl.d \
./system/src/diag/trace.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/diag/%.o: ../system/src/diag/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=24000000 -I"../include" -I"E:\ITI_work\Japanese_University_ARM\workspace\BOOTLOADER\My_Include\03-MCAL\MUSART" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../My_Include/00-LIB" -I"../My_Include/03-MCAL/MGPIO" -I"../My_Include/03-MCAL/MRCC" -I"../My_Include/03-MCAL/MSTK" -I"../My_Include/03-MCAL/MNVIC" -I"../My_Include/03-MCAL/MFLASH" -I"../My_Include/SCHEDULER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


