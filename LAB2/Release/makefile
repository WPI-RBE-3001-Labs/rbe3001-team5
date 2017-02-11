################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
LAB2.lss \

FLASH_IMAGE += \
LAB2.hex \

EEPROM_IMAGE += \
LAB2.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LAB2.elf secondary-outputs

# Tool invocations
LAB2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LAB2.map -Wl,-u,vfprintf -lprintf_flt -lm -L"C:\Users\Matias\Documents\Worcester Polytechnic Institute\3Junior Year\C-Term\RBE3001\rbe3001-team5\RBELib\Release" -mmcu=atmega644p -o "LAB2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LAB2.lss: LAB2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LAB2.elf  >"LAB2.lss"
	@echo 'Finished building: $@'
	@echo ' '

LAB2.hex: LAB2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LAB2.elf  "LAB2.hex"
	@echo 'Finished building: $@'
	@echo ' '

LAB2.eep: LAB2.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LAB2.elf  "LAB2.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LAB2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega644p LAB2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LAB2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
