################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/crp.c \
../src/lsl_logs.c \
../src/lsl_main.c \
../src/lsl_memory.c \
../src/lsl_mems.c \
../src/lsl_nfc.c 

OBJS += \
./src/crp.o \
./src/lsl_logs.o \
./src/lsl_main.o \
./src/lsl_memory.o \
./src/lsl_mems.o \
./src/lsl_nfc.o 

C_DEPS += \
./src/crp.d \
./src/lsl_logs.d \
./src/lsl_main.d \
./src/lsl_memory.d \
./src/lsl_mems.d \
./src/lsl_nfc.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__REDLIB__ -I"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\SBS_Gen_v1\inc" -I"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\lib_chip_nss\inc" -I"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\lib_board_dp\inc" -I"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\mods" -I"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\SBS_Gen_v1\mods" -I"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\lib_board_dp\mods" -I"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\lib_chip_nss\mods" -include"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\SBS_Gen_v1\mods\app_sel.h" -include"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\lib_board_dp\mods\board_sel.h" -include"C:\Users\eSpark\Documents\MCUXpressoIDE_10.2.1_795\workspace\lib_chip_nss\mods/chip_sel.h" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


