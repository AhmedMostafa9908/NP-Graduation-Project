################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/main.c 

OBJS += \
./Application/main.o 

C_DEPS += \
./Application/main.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o: ../Application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\PoWeR\Desktop\NP_Training\AVR_projects1\GPIO_32\DIO_Driver" -I"C:\Users\PoWeR\Desktop\NP_Training\AVR_projects1\GPIO_32\Infra_structure" -I"C:\Users\PoWeR\Desktop\NP_Training\AVR_projects1\GPIO_32\LCD" -I"C:\Users\PoWeR\Desktop\NP_Training\AVR_projects1\GPIO_32\PWM_Driver" -I"C:\Users\PoWeR\Desktop\NP_Training\AVR_projects1\GPIO_32\Timer_Driver" -I"C:\Users\PoWeR\Desktop\NP_Training\AVR_projects1\GPIO_32\UART_Driver" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


