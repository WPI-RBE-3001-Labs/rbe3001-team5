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
mfcamposabadPrelab1.lss \

FLASH_IMAGE += \
mfcamposabadPrelab1.hex \

EEPROM_IMAGE += \
mfcamposabadPrelab1.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: mfcamposabadPrelab1.elf secondary-outputs

# Tool invocations
mfcamposabadPrelab1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,mfcamposabadPrelab1.map -Wl,-u,vfprintf -lprintf_flt -lm -L"C:\Users\Matias\Documents\Worcester Polytechnic Institute\3Junior Year\C-Term\RBE3001\rbe3001-team5\RBELib\Release" -mmcu=atmega644p -o "mfcamposabadPrelab1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

mfcamposabadPrelab1.lss: mfcamposabadPrelab1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S mfcamposabadPrelab1.elf  >"mfcamposabadPrelab1.lss"
	@echo 'Finished building: $@'
	@echo ' '

mfcamposabadPrelab1.hex: mfcamposabadPrelab1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex mfcamposabadPrelab1.elf  "mfcamposabadPrelab1.hex"
	@echo 'Finished building: $@'
	@echo ' '

mfcamposabadPrelab1.eep: mfcamposabadPrelab1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex mfcamposabadPrelab1.elf  "mfcamposabadPrelab1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: mfcamposabadPrelab1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega644p mfcamposabadPrelab1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) mfcamposabadPrelab1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
