# NP-Graduation-Project
In this project we used 2 atmega32 microcontrollers to implement motor speed controller and printing the current speed on the LCD. So, we used UART to make the 2 microcontrollers communicate with each other. The first microcontroller operates as a UART sender. It contains 2 push buttons, one to increase speed and the another one to decrease it. On pressing the push button, it sends the speed to the second microcontroller which operates as UART receiver. The LCD and The motor are connected to the second microcontroller, we control the speed of the motor using software PWM which we had implemented using Timers in CTC mode.   


#  Implementation Details:
   In this project we have created all libraries from scratch and applied the concept of layered architecture and static design in our design. So we divided our project into 4 layers.
 ## 1) The Hardware Registers:
    In this layer we have defined all register addresses and created pointers that allow us to edit registers' data.
 ## 2) Microcontroller Abstraction Layer:
    In this layer we have created drivers for our internal peripherals like DIO, Timers, and UART.
 ## 3) The Hardware Abstraction Layer:
    In this layer we made drivers for hardwares that we use in our project like LCD, Motor PWM, and Switches.
 ## 4) Application Layer:
    This layer contains our main, so we use it to create a program that we want to execute.
