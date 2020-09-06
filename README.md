# NP-Graduation-Project
In  this project we use 2 atmega32 microcontrollers to implement motor speed controller and printing the current speed on the LCD so we use UART to make the 2 microcontroller communicate to each other. The first one operate as UART sender it contains 2 push buttons one to increase speed and the other one to decrease the speed so when we click on it,it sends the speed to the second microcontroller which operate as UART receiver. It contains the LCD and the motor we control the speed of the motor using software PWM which we had implemented using Timers in CTC mode.   


#  Implementation Details:
In this project we have created all libraryis from scratch and apply the concept of layered architecture and static design in our design so we divide our project to 4 layers
 1) The Hardware Registers:
In this layer we had defined all regiter addresses and created pointers that allow us to edit in registers.
 2) Microcontroller abstraction layer:
In this layer we have created drivers for our internal prepherals like DIO,Timers, UART.
 3) The Hardware Abstraction Layer:
In this layer we made a drivers for hardwares that we use in our project like LCD, Motor PWM, Switches
 4) Application Layer:
This layer contains our main so we use this layer to make a program that we want to execute
