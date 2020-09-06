# NP-Graduation-Project
In  this project we use 2 atmega32 microcontrollers to implement motor speed controller and print the current speed on the LCD. We use UART to make the 2 microcontrollers communicate with each other as one transmits and the other receives. The first one operates as UART transmitter, it contains 2 push buttons one to increase speed and the other to decrease it. So when we click on either switch, it sends the speed wanted by the user to the other microcontroller operating as UART receiver. It is connected to the LCD and the motor. 
We control the speed of the motor using software PWM which we had implemented using Timers in CTC mode.   


#  Implementation Details:
   In this project we created all libraries from scratch and applied the concept of layered architecture and static design in our design as we divide our project to 4 layers
 ## 1) The Hardware Registers:
    In this layer we define all regiter addresses and create pointers that allow us to edit in registers.
 ## 2) Microcontroller abstraction layer:
    In this layer we create drivers for our internal prepherals like DIO,Timers, UART.
 ## 3) The Hardware Abstraction Layer:
    In this layer we made drivers for hardware devices used in our project like LCD, Motor PWM, Switches
 ## 4) Application Layer:
    This layer contains our main file so we use this layer to make a program we want to execute
