################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Peter/Documents/LPCXpresso_8.2.2_650/workspace/mods/storage/storage.c 

OBJS += \
./mods/storage/storage.o 

C_DEPS += \
./mods/storage/storage.d 


# Each subdirectory must supply rules for building sources it contributes
mods/storage/storage.o: C:/Users/Peter/Documents/LPCXpresso_8.2.2_650/workspace/mods/storage/storage.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DNDEBUG -D__CODE_RED -DCORE_M0PLUS -D__REDLIB__ -I"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\LSL_v1\inc" -I"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\lib_board_dp\inc" -I"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\lib_chip_nss\inc" -I"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\mods" -I"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\LSL_v1\mods" -I"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\lib_board_dp\mods" -I"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\lib_chip_nss\mods" -include"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\LSL_v1\mods\app_sel.h" -include"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\lib_board_dp\mods\board_sel.h" -include"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\lib_chip_nss\mods/chip_sel.h" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


