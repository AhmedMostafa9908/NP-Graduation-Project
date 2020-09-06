/*
 * UART.h
 *
 *  Created on: Sep 1, 2020
 *      Author: H
 */

#ifndef UART_DRIVER_UART_H_
#define UART_DRIVER_UART_H_

#include "AVR_Reg.h"
#include "Common_Macros.h"
#include "Std_Types.h"
#include "UART_Cfg.h"
#include "stdint.h"
#include "stddef.h"

typedef struct
{
 uint32_t u32_BaudRate;
 uint8_t u8_DataBits;  /* (5~9) bits */
 uint8_t u8_FlagAction;  /***interrupt or polling***/
}str_UartConfg_t;

#define FOSC   1000000
typedef uint8_t UART_Error_t;

/*- FUNCTION-LIKE MACROS -----------------------------------*/
#define DISABLE       0U
#define ENABLE        1U

#define NO_ERROR 0
#define ERROR    1

#define UART_ONE_STOP_BIT  0U
#define UART_TWO_STOP_BITS 1U


#define UART_POLLING 0U
#define UART_INTERRUPT 1U



#define UART_FLAG_ACTION 4U
#define UART_ALL_INTERRUPT_DISABLED 5U

#define UART_PARITY_EVEN 0U
#define UART_PARITY_ODD 1U
#define UART_NO_PARITY 2U

#define UART_5_BIT_MODE 0
#define UART_6_BIT_MODE 1
#define UART_7_BIT_MODE 2
#define UART_8_BIT_MODE 3
#define UART_9_BIT_MODE 7

#define UCSZ0    1
#define UCSZ1    2
#define UCSZ2    2
#define UMSEL    6  //Mode Select (Asynchronous or Synchronous)
#define USBS     3  //Stop bit select
/* for parity Mode */
#define UBM0     4
#define UBM1     5
#define URSEL    7

#define UDRE    5

/*- Registers ----------------------------------*/

#define USART_CONTORL_STATUS_REGISTER_A           UCSRA
#define USART_CONTORL_STATUS_REGISTER_B           UCSRB
#define USART_CONTORL_STATUS_REGISTER_C           UCSRC
#define USART_BAUD_RATE_REGISTER_LOW              UBRRL
#define USART_BAUD_RATE_REGISTERs_HIGH            UBRRH
#define USART_DATA_REGISTER_READ                  UDRR
#define USART_DATA_REGISTER_WRITE                 UDRW

#define  RXC      7
#define  RXCIE    7
#define  TXCIE    6
#define  UDRIE    5



/*- FUNCTION DECLARATIONS ----------------------------------*/
/*************************************************************
*Description: Initialization of Uart Module
* Input     : poiter to uart configuration struct
* Output    : Error Status
* */
extern uint8_t UART_init(str_UartConfg_t * uart_config);

/*************************************************************
*Description: Sending byte of data
* Input     : u16Data to send
* Output    : Error Status
* */
extern uint8_t UART_sendByte( uint8_t u8_Data);

/*************************************************************
*Description: Receiving byte of data
* Input     : pointer to u16Data
* Output    : Error Status
* */
extern uint8_t UART_recieveByte(uint8_t *u8_Data);


/*************************************************************
*Description: Receiving Flag used in Case of Polling
* Input     : pointer to u8Data
* Output    : No Return
* */
extern uint8_t UART_GetPollingFlag(uint8_t *u8_Data);

/*************************************************************
*Description: Call Back for function to send to ISR
* Input     : pointer to function
* Output    : ERROR Status
* */
extern uint8_t UART_TX_SetCallBack(void (*Copy_FunctionAddress)(void));
/*
*Description: Call Back for function to Receive Data
* Input     : pointer to function
* Output    : ERROR Status
* */
extern uint8_t UART_RX_SetCallBack(void (*Copy_FunctionAddress)(void));

#endif /* UART_DRIVER_UART_H_ */
