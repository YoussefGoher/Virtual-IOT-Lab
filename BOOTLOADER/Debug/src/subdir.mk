################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MyTasks.c \
../src/main.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/MyTasks.o \
./src/main.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/MyTasks.d \
./src/main.d \
./src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=24000000 -I"../include" -I"E:\ITI_work\Japanese_University_ARM\workspace\BOOTLOADER\My_Include\03-MCAL\MUSART" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../My_Include/00-LIB" -I"../My_Include/03-MCAL/MGPIO" -I"../My_Include/03-MCAL/MRCC" -I"../My_Include/03-MCAL/MSTK" -I"../My_Include/03-MCAL/MNVIC" -I"../My_Include/03-MCAL/MFLASH" -I"../My_Include/SCHEDULER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=24000000 -I"../include" -I"E:\ITI_work\Japanese_University_ARM\workspace\BOOTLOADER\My_Include\03-MCAL\MUSART" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../My_Include/00-LIB" -I"../My_Include/03-MCAL/MGPIO" -I"../My_Include/03-MCAL/MRCC" -I"../My_Include/03-MCAL/MSTK" -I"../My_Include/03-MCAL/MNVIC" -I"../My_Include/03-MCAL/MFLASH" -I"../My_Include/SCHEDULER" -std=gnu11 -Wno-padded -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/stm32f4xx_hal_msp.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


