################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer1/Src/subdir.mk
-include MCAL/GIE/Src/subdir.mk
-include MCAL/EXTI/Src/subdir.mk
-include MCAL/DIO/Src/subdir.mk
-include HAL/Ultrasonic/Src/subdir.mk
-include HAL/Servo/Src/subdir.mk
-include HAL/MotorDriver/Src/subdir.mk
-include HAL/IR_Sensor/Src/subdir.mk
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
Mahmoud.lss \

FLASH_IMAGE += \
Mahmoud.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Mahmoud.elf secondary-outputs

# Tool invocations
Mahmoud.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Mahmoud.map -mmcu=atmega32 -o "Mahmoud.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Mahmoud.lss: Mahmoud.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Mahmoud.elf  >"Mahmoud.lss"
	@echo 'Finished building: $@'
	@echo ' '

Mahmoud.hex: Mahmoud.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Mahmoud.elf  "Mahmoud.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Mahmoud.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Mahmoud.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Mahmoud.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
