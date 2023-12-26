################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include mods/tmeas/subdir.mk
-include mods/storage/subdir.mk
-include mods/ndeft2t/subdir.mk
-include mods/msg/subdir.mk
-include mods/event/subdir.mk
-include mods/compress/heatshrink/subdir.mk
-include mods/compress/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LSL_v1.axf

# Tool invocations
LSL_v1.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\lib_board_dp\Release" -L"C:\Users\Peter\Documents\LPCXpresso_8.2.2_650\workspace\lib_chip_nss\Release" -Xlinker -Map="LSL_v1.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T "LSL_v1_Release.ld" -o "LSL_v1.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) LSL_v1.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-objcopy -v -O ihex LSL_v1.axf LSL_v1.hex ; arm-none-eabi-size "LSL_v1.axf" ; arm-none-eabi-objcopy -v -O binary "LSL_v1.axf" "LSL_v1.bin" ; # checksum -p NHS3152 -d "LSL_v1.bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
