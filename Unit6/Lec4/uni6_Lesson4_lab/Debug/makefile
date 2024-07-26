################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
uni6_Lesson4_lab.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
uni6_Lesson4_lab.list \

OBJCOPY_BIN += \
uni6_Lesson4_lab.bin \


# All Target
all: uni6_Lesson4_lab.elf secondary-outputs

# Tool invocations
uni6_Lesson4_lab.elf: $(OBJS) $(USER_OBJS) E:\GitHubRepo\Master-Embedded-Systems\Unit6\Lec4\uni6_Lesson4_lab\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "uni6_Lesson4_lab.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\GitHubRepo\Master-Embedded-Systems\Unit6\Lec4\uni6_Lesson4_lab\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="uni6_Lesson4_lab.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

uni6_Lesson4_lab.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "uni6_Lesson4_lab.list"
	@echo 'Finished building: $@'
	@echo ' '

uni6_Lesson4_lab.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "uni6_Lesson4_lab.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
