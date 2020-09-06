/*
 * UART.h
 *
 *  Created on: Sep 1, 2020
 *      Author: H
 */

#ifndef  SWITCH_DRIVER_UART_H_
#define  SWITCH_DRIVER_UART_H_

#include "AVR_Reg.h"
#include "Common_Macros.h"
#include "Std_Types.h"
#include "stdint.h"
#include "stddef.h"
#include "Dio.h"

#define status_Register SREG
#define pin7 7
#define PULL_UP 1
#define FLOATING 0
#define General_Interrupt_CR GICR
#define MCU_control_register MCUCR
#define MCU_control_and_status_register MCUCSR
#define INT0_MODE 0
#define INT1_MODE 1
#define INT2_MODE 2
#define POLLING_MODE 3

typedef struct SWITCH{
uint8_t PIN;
uint8_t Status; // PULLUP or FLOATING
uint8_t Mode;   //INT0 or INT1 or INT2 or  POLLING
}Switch_t;

/*- FUNCTION-LIKE MACROS -----------------------------------*/





/*- FUNCTION DECLARATIONS ----------------------------------*/
/*************************************************************
*Description: Initialization of Switch
* Input     : pointer to Switch configuration struct
* Output    : Error Status
* */
extern uint8_t SwitchInit(Switch_t *My_Switch);

/*************************************************************
*Description: Enable global interrupt
* Input     : void
* Output    : Error Status
* */
extern void Enable_Global_Interrupt(void);

/*************************************************************
*Description: Check if the button is pressed
* Input     : pointer to status and pointer to switch
* Output    : Error Status
* */
extern uint8_t IsPressed(Switch_t* My_Switch, uint8_t* Status);


//*************************************************************

#endif
