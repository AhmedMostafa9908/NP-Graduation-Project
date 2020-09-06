/*
 * UART.c
 *
 *  Created on: Sep 1, 2020
 *      Author: H
 */
#include"UART.h"
#include  <avr/interrupt.h>
/*************************************************************
*Description: Initialization of Uart Module
* Input     : pointer to uart configuration struct
* Output    : Error Status
* */
//#define void (*func) (void)       IntHandler
void (*RX_IntHandler)(void)=NULL;   /* RX pointer to function */
void (*TX_IntHandler)(void)=NULL;   /*TX  pointer to function */
uint8_t BaudRateRegisterValue;

uint8_t UART_init (str_UartConfg_t * uart_config)
{
	 /* Set BaudRate */
	  BaudRateRegisterValue= FOSC/(16 * (uart_config->u32_BaudRate-1));
	  USART_BAUD_RATE_REGISTERs_HIGH = (BaudRateRegisterValue) >>8;
	  USART_BAUD_RATE_REGISTER_LOW = BaudRateRegisterValue;

	  SET_BIT(USART_CONTORL_STATUS_REGISTER_B , 4);     /* RX enable*/
	  SET_BIT(USART_CONTORL_STATUS_REGISTER_B , 3);     /* TX enable*/

	  /* 5 Bit Mode*/
	if(uart_config -> u8_DataBits ==UART_5_BIT_MODE)
	{
	  USART_CONTORL_STATUS_REGISTER_C|=(1<<URSEL)|(1<<USBS);
	}

	/* 6 Bit Mode*/
	else if(uart_config-> u8_DataBits == UART_6_BIT_MODE)
	{
		USART_CONTORL_STATUS_REGISTER_C|=(1<<URSEL)|(1<<USBS)|(1<<UCSZ0);
	}

	/* 7 Bit Mode*/
	else if(uart_config -> u8_DataBits == UART_7_BIT_MODE)
	{
		USART_CONTORL_STATUS_REGISTER_C|=(1<<URSEL)|(1<<USBS)|(1<<UCSZ1);
	}

	/* 8 Bit Mode*/
	else if(uart_config -> u8_DataBits == UART_8_BIT_MODE)
	{
		USART_CONTORL_STATUS_REGISTER_C|=(1<<URSEL)|(1<<USBS)|(1<<UCSZ0)|(1<<UCSZ1);
	}

	/* 9 Bit Mode*/
	else
	{
        USART_CONTORL_STATUS_REGISTER_C |=(1<<URSEL)|(1<<USBS)|(1<<UCSZ0)|(1<<UCSZ1);
        USART_CONTORL_STATUS_REGISTER_B |= (1<<UCSZ2);
	}

	/* Interrupt Mode */
	if(uart_config->u8_FlagAction == UART_INTERRUPT)
	{
		/*RX INT Enable & TX INT Enable */
		USART_CONTORL_STATUS_REGISTER_B |= (1<<RXCIE) |(1<<TXCIE);
		return NO_ERROR;

	}
	/* Polling Mode*/
	else if(uart_config ->u8_FlagAction == UART_POLLING)
	{
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}



 }

//_________________________________________________________________________________________________________________________________________
/*Description: Receiving byte of data
* Input     : pointer to u8Data int
* Output    : Error Status
*/
//_________________________________________________________________________________________________________________________________
uint8_t UART_recieveByte(uint8_t *u8_Data)
{
	if(u8_Data != NULL)
	{
		/* This is to check that all of the data is received*/
		while(BIT_IS_CLEAR(USART_CONTORL_STATUS_REGISTER_A,RXC));

		/*Get the Received Data */
		*u8_Data = USART_DATA_REGISTER_READ;

		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}

}
//________________________________________________________________________________________________________________________________________
/*************************************************************
*Description: Receiving Flag used in Case of Polling
* Input     : pointer to u8Data
* Output    : No Return
* */
uint8_t UART_GetPollingFlag(uint8_t *u8_Data)
{
    if(u8_Data == NULL)
    {
       return ERROR;
    }
    else
    {
     uint8_t holder;
        /* holder gets the value 128 if RXC bit is set or 0 if RXC bit is cleared*/
     holder = USART_CONTORL_STATUS_REGISTER_A & (1 << RXC);
     if(holder == 128)   /* there are an Unread Data in the  Receive Buffer */
     {
        holder = 1;
     }
     else  /* The Receive Buffer is Empty */
     {
        holder = 0;
     }
     *u8_Data = holder;  /* Read Data Received */

       return NO_ERROR;
    }
}
//________________________________________________________________________________________________________________________________________
/*************************************************************
*Description: Sending byte of data
* Input     : u16Data to send
* Output    : Error Status
* */
uint8_t UART_sendByte( uint8_t u8_Data)
{
 //wait for the transmission buffer to be empty
 while(BIT_IS_CLEAR(USART_CONTORL_STATUS_REGISTER_A,UDRE));
 USART_DATA_REGISTER_READ = u8_Data; //put data in buffer, send data
 return NO_ERROR;

}
//_______________________________________________________________________________________________________________________________________

/*************************************************************
*Description: Call Back for function to send to ISR
* Input     : pointer to function
* Output    : ERROR Status
* */
 uint8_t UART_TX_SetCallBack(void (*Copy_FunctionAddress)(void))
 {
	 TX_IntHandler= Copy_FunctionAddress;
      return NO_ERROR;
 }

 //___________________________________________________________________________________________________________________________
/*
*Description: Call Back for function to Receive Data
* Input     : pointer to function
* Output    : ERROR Status
* */
 uint8_t UART_RX_SetCallBack(void (*Copy_FunctionAddress)(void))
{
	 RX_IntHandler = Copy_FunctionAddress;
       return NO_ERROR;
}
 /* TX Complete ISR */
ISR(USART_TXC_vect)
{
  TX_IntHandler();
}

/* RX Complete ISR */
ISR(USART_RXC_vect)
{

 RX_IntHandler();

}

 //_________________________________________________________________________________________________________________________________________
