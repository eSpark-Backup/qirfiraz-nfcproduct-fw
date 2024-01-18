################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/eSpark/Documents/LPCXpresso_8.2.2_650/space/mods/led/led.c 

OBJS += \
./mods/led/led.o 

C_DEPS += \
./mods/led/led.d 


# Each subdirectory must supply rules for building sources it contributes
mods/led/led.o: C:/Users/eSpark/Documents/LPCXpresso_8.2.2_650/space/mods/led/led.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=c99 -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -I"C:\Users\eSpark\Documents\LPCXpresso_8.2.2_650\space\lib_chip_nss" -I"C:\Users\eSpark\Documents\LPCXpresso_8.2.2_650\space\lib_board_dp\inc" -I"C:\Users\eSpark\Documents\LPCXpresso_8.2.2_650\space\lib_board_dp\mods" -I"C:\Users\eSpark\Documents\LPCXpresso_8.2.2_650\space\lib_chip_nss\inc" -I"C:\Users\eSpark\Documents\LPCXpresso_8.2.2_650\space\lib_chip_nss\mods" -I"C:\Users\eSpark\Documents\LPCXpresso_8.2.2_650\space\mods" -include"C:\Users\eSpark\Documents\LPCXpresso_8.2.2_650\space\lib_chip_nss\mods\chip_sel.h" -include"C:\Users\eSpark\Documents\LPCXpresso_8.2.2_650\space\lib_board_dp\mods\board_sel.h" -Og -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


