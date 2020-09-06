################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include UART_Driver/subdir.mk
-include Timer_Driver/subdir.mk
-include PWM_Driver/subdir.mk
-include LCD/subdir.mk
-include DIO_Driver/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
GPIO_32.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: GPIO_32.elf secondary-outputs

# Tool invocations
GPIO_32.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,GPIO_32.map -mmcu=atmega32 -o "GPIO_32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

GPIO_32.lss: GPIO_32.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S GPIO_32.elf  >"GPIO_32.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: GPIO_32.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 GPIO_32.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) GPIO_32.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
