################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/newlib/assert.c \
../system/src/newlib/exit.c \
../system/src/newlib/sbrk.c \
../system/src/newlib/startup.c \
../system/src/newlib/syscalls.c 

CPP_SRCS += \
../system/src/newlib/cxx.cpp 

OBJS += \
./system/src/newlib/assert.o \
./system/src/newlib/cxx.o \
./system/src/newlib/exit.o \
./system/src/newlib/sbrk.o \
./system/src/newlib/startup.o \
./system/src/newlib/syscalls.o 

C_DEPS += \
./system/src/newlib/assert.d \
./system/src/newlib/exit.d \
./system/src/newlib/sbrk.d \
./system/src/newlib/startup.d \
./system/src/newlib/syscalls.d 

CPP_DEPS += \
./system/src/newlib/cxx.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/newlib/%.o: ../system/src/newlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=24000000 -I"../include" -I"E:\ITI_work\Japanese_University_ARM\workspace\BOOTLOADER\My_Include\03-MCAL\MUSART" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../My_Include/00-LIB" -I"../My_Include/03-MCAL/MGPIO" -I"../My_Include/03-MCAL/MRCC" -I"../My_Include/03-MCAL/MSTK" -I"../My_Include/03-MCAL/MNVIC" -I"../My_Include/03-MCAL/MFLASH" -I"../My_Include/SCHEDULER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/newlib/%.o: ../system/src/newlib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=24000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/newlib/startup.o: ../system/src/newlib/startup.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=24000000 -DOS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS -I"../include" -I"E:\ITI_work\Japanese_University_ARM\workspace\BOOTLOADER\My_Include\03-MCAL\MUSART" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../My_Include/00-LIB" -I"../My_Include/03-MCAL/MGPIO" -I"../My_Include/03-MCAL/MRCC" -I"../My_Include/03-MCAL/MSTK" -I"../My_Include/03-MCAL/MNVIC" -I"../My_Include/03-MCAL/MFLASH" -I"../My_Include/SCHEDULER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"system/src/newlib/startup.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


