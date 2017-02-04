################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../debug.c \
../firstblink.c \
../globa_variables.c \
../globals.c \
../main.c \
../ports.c \
../timers.c 

OBJS += \
./debug.o \
./firstblink.o \
./globa_variables.o \
./globals.o \
./main.o \
./ports.o \
./timers.o 

C_DEPS += \
./debug.d \
./firstblink.d \
./globa_variables.d \
./globals.d \
./main.d \
./ports.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Matias\Documents\Worcester Polytechnic Institute\3Junior Year\C-Term\RBE3001\rbe3001-team5\RBELib\include" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega644p -DF_CPU=18432000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


