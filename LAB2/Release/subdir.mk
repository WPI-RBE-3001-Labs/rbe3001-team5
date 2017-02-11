################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DAC.c \
../PID.c \
../SPI.c \
../USARTDebug.c \
../main.c \
../motors.c \
../ports.c \
../pot.c \
../timer.c 

OBJS += \
./ADC.o \
./DAC.o \
./PID.o \
./SPI.o \
./USARTDebug.o \
./main.o \
./motors.o \
./ports.o \
./pot.o \
./timer.o 

C_DEPS += \
./ADC.d \
./DAC.d \
./PID.d \
./SPI.d \
./USARTDebug.d \
./main.d \
./motors.d \
./ports.d \
./pot.d \
./timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Matias\Documents\Worcester Polytechnic Institute\3Junior Year\C-Term\RBE3001\rbe3001-team5\RBELib\include" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega644p -DF_CPU=18432000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


