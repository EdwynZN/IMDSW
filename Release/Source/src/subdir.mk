################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/src/ADC.c \
../Source/src/PWM.c \
../Source/src/UART.c \
../Source/src/main.c 

C_DEPS += \
./Source/src/ADC.d \
./Source/src/PWM.d \
./Source/src/UART.d \
./Source/src/main.d 

OBJS += \
./Source/src/ADC.o \
./Source/src/PWM.o \
./Source/src/UART.o \
./Source/src/main.o 


# Each subdirectory must supply rules for building sources it contributes
Source/src/%.o: ../Source/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


