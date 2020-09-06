/*
 * dio.c
 *
 *  Created on: Aug 30, 2020
 *      Author: H
 */

#include "Dio.h"


/*______________________________________________________________________________________________*/
/*Description: Set PORT Direction (INPUT or OUTPUT)
 * Input     : Copy_u8PortNB (PORT Number) ,  Copy_u8Dir (PORT Direction)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8Init_PORT(uint8_t Copy_u8PortNB,uint8_t Copy_u8Dir)
{   //KHALED
	/* Implement Your Code */

	if( (Copy_u8PortNB == DIOA)|| (Copy_u8PortNB == DIOB) ||  (Copy_u8PortNB == DIOC) || (Copy_u8PortNB == DIOD))
	{
		switch (Copy_u8PortNB)
		{
		case DIOA:
			DIRECTION_PORT0=Copy_u8Dir; //setting whole port A direction
			break;
		case DIOB:
			DIRECTION_PORT1=Copy_u8Dir; //setting whole port B direction
			break;
		case DIOC:
			DIRECTION_PORT2=Copy_u8Dir; //setting whole port C direction
			break;
		case DIOD:
			DIRECTION_PORT3=Copy_u8Dir; //setting whole port D direction
			break;


		}
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}
/*______________________________________________________________________________________________*/

/*Description: Set PIN Direction (INPUT or OUTPUT)
 * Input     :Copy_u8PinNB (PIN Number) ,  Copy_u8Dir (PIN Direction)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8Init_PIN(uint8_t Copy_u8PinN,uint8_t Copy_u8Dir)
{ // YOUSSEF

	/* Implement Your Code */
	if(Copy_u8PinN >= MINIMUM_PIN_NO && Copy_u8PinN <= MAX_PIN_NO)
	    {
	        // Copy_u8Dir should be either having the value input or output.

	        if(Copy_u8Dir == DIO_INPUT || Copy_u8Dir == DIO_OUTPUT)
	        {
	            if(Copy_u8PinN >= DIO_PIN_NO_0 && Copy_u8PinN <= DIO_PIN_NO_7)  // PORT A
	            {
	                if(Copy_u8Dir == DIO_OUTPUT)
	                {
	                    // Setting the required bit in the DDRA register to 1 (output).
	                    SET_BIT(DIRECTION_PORT0, (Copy_u8PinN % 8));
	                }
	                else
	                {
	                    // Clearing the required bit in the DDRA register (input).
	                    CLEAR_BIT(DIRECTION_PORT0, (Copy_u8PinN % 8));
	                }
	                // %8 is used to return a number between 0 and 7.

	            }
	            else if(Copy_u8PinN >= DIO_PIN_NO_8 && Copy_u8PinN <= DIO_PIN_NO_15)  // PORT B
	            {
	                if(Copy_u8Dir == DIO_OUTPUT)
	                {
	                    // Setting the required bit in the DDRB register to 1 (output).
	                    SET_BIT(DIRECTION_PORT1, (Copy_u8PinN % 8));
	                }
	                else
	                {
	                    // Clearing the required bit in the DDRB register (input).
	                    CLEAR_BIT(DIRECTION_PORT1, (Copy_u8PinN % 8));
	                }
	                // %8 is used to return a number between 0 and 7.
	            }
	            else if(Copy_u8PinN >= DIO_PIN_NO_16 && Copy_u8PinN <= DIO_PIN_NO_23)  // PORT C
	            {
	                if(Copy_u8Dir == DIO_OUTPUT)
	                {
	                    // Setting the required bit in the DDRC register to 1 (output).
	                    SET_BIT(DIRECTION_PORT2, (Copy_u8PinN % 8));
	                }
	                else
	                {
	                    // Clearing the required bit in the DDRC register (input).
	                    CLEAR_BIT(DIRECTION_PORT2, (Copy_u8PinN % 8));
	                }
	                // %8 is used to return a number between 0 and 7.
	            }
	            else if(Copy_u8PinN >= DIO_PIN_NO_24 && Copy_u8PinN <= DIO_PIN_NO_31)  // PORT D
	            {
	                if(Copy_u8Dir == DIO_OUTPUT)
	                {
	                    // Setting the required bit in the DDRD register to 1 (output).
	                    SET_BIT(DIRECTION_PORT3, (Copy_u8PinN % 8));
	                }
	                else
	                {
	                    // Clearing the required bit in the DDRD register (input).
	                    CLEAR_BIT(DIRECTION_PORT3, (Copy_u8PinN % 8));
	                }
	                // %8 is used to return a number between 0 and 7.
	            }

	            return NO_ERROR;
	        }
	        else
	        {
	            return ERROR;
	        }
	    }
	    else
	    {
	        return ERROR;
	    }



}
/*______________________________________________________________________________________________*/

/*Description: Set PORT Value (from 0 to 255)
 * Input     : Copy_u8PortNB (PORT Number) , Copy_u8Value (Value)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPortValue(uint8_t Copy_u8PortNB,uint8_t Copy_u8Value)
{ //  yasmeen
	/* Implement Your Code */
	switch(Copy_u8PortNB)
		{
			case DIOA:
			{
				VALUE_PORT0 = Copy_u8Value;
				return NO_ERROR;
			}
			break;
			case DIOB:
			{
				VALUE_PORT1 = Copy_u8Value;
				return NO_ERROR;
			}
			break;
			case DIOC:
			{
				VALUE_PORT2 = Copy_u8Value;
				return NO_ERROR;
			}
			break;
			case DIOD:
			{
				VALUE_PORT3 = Copy_u8Value;
				return NO_ERROR;
			}
			break;
			default:
			 return ERROR;
			break;


		}


}

/*______________________________________________________________________________________________*/
/*Description: Set PIN Value (HIGH or LOW)
 * Input     : Copy_u8PinNB (PIN Number) , Copy_u8Value (Value)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPinValue(uint8_t Copy_u8PinN,uint8_t Copy_u8Value)
{    // Ahmed Mohamed
	/* Implement Your Code */

	if(Copy_u8PinN>=MINIMUM_PIN_NO && Copy_u8PinN<=MAX_PIN_NO && (Copy_u8Value==DIO_HIGH || Copy_u8Value==DIO_LOW))
		{
			//incase no error occurred
			if(Copy_u8PinN >= DIO_PIN_NO_0 && Copy_u8PinN <= DIO_PIN_NO_7)
			{
				//port A
				if(Copy_u8Value==DIO_HIGH)
				{
					SET_BIT(VALUE_PORT0,Copy_u8PinN);

				}
				else
				{
					CLEAR_BIT(VALUE_PORT0,Copy_u8PinN);

				}

			}
			else if(Copy_u8PinN>=DIO_PIN_NO_8 && Copy_u8PinN<=DIO_PIN_NO_15)
			{
				//port B
				if(Copy_u8Value==DIO_HIGH)
				{
					SET_BIT(VALUE_PORT1,(Copy_u8PinN-DIO_PIN_NO_8));

				}
				else
				{
					CLEAR_BIT(VALUE_PORT1,(Copy_u8PinN-DIO_PIN_NO_8));

				}
			}
			else if(Copy_u8PinN>=DIO_PIN_NO_16 && Copy_u8PinN<=DIO_PIN_NO_23)
			{
				//port C
				if(Copy_u8Value==DIO_HIGH)
				{
					SET_BIT(VALUE_PORT2,(Copy_u8PinN-DIO_PIN_NO_16));

				}
				else
				{
					CLEAR_BIT(VALUE_PORT2,(Copy_u8PinN-DIO_PIN_NO_16));

				}
			}
			else
			{
				//port D
				if(Copy_u8Value==DIO_HIGH)
				{
					SET_BIT(VALUE_PORT3,(Copy_u8PinN-DIO_PIN_NO_24));

				}
				else
				{
					CLEAR_BIT(VALUE_PORT3,(Copy_u8PinN-DIO_PIN_NO_24));

				}
			}

			return NO_ERROR;
		}
		else
		{
			//incase an error occurred
			return ERROR;
		}

}

/*______________________________________________________________________________________________*/
/*Description: Get PORT Value
 * Input     :  Copy_u8PortNB (PORT Number),*Copy_u8Value (Pointer to send value to it)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8GetPortValue(uint8_t Copy_u8PortNB,uint8_t *Copy_u8Value)
{  // HANA

	/* Implement Your Code */
	if ( (Copy_u8Value == NULL) ||	(Copy_u8PortNB > 3) ||	(Copy_u8PortNB < 0))
	  {
	   return ERROR;
	  }
	  else
	  {
	    switch(Copy_u8PortNB)
	    {
	     case DIOA:
		 {
			 *Copy_u8Value=READ_PORT0;   //*PORTA is assigned the number 0
	          return NO_ERROR;

		 }
		 break;

	     case DIOB:
		 {
			 *Copy_u8Value=READ_PORT1;   //*PORTB is assigned the number 1
			 return NO_ERROR;

		 }
		 break;

	     case DIOC:
		 {        *Copy_u8Value=READ_PORT2;   //*PORTC is assigned the number 2
	              return NO_ERROR;
		 }
		 break;

	     case DIOD:
		 {
				*Copy_u8Value=READ_PORT3;   //*PORTD is assigned the number 3
	              return NO_ERROR;
		 }
		 break;
		 default:  return ERROR;  break;
	    }
	  }


}

/*______________________________________________________________________________________________*/
/*Description: Get PIN Value (HIGH or LOW)
 * Input     : Copy_u8PinN (PIN Number) ,*Copy_u8Value (Pointer to send value to it)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8GetPinValue(uint8_t Copy_u8PinN,uint8_t *Copy_u8Value)
{
	// AHMED MOSTAFA



	/* Implement Your Code */
	if((Copy_u8PinN>= MINIMUM_PIN_NO) && (Copy_u8PinN< TOTAL_NO_OF_PINS)){
		//port A
		if((Copy_u8PinN>=DIO_PIN_NO_0) && (Copy_u8PinN<=DIO_PIN_NO_7)){

				*Copy_u8Value=GET_BIT(READ_PORT0,(Copy_u8PinN%8));

			return  NO_ERROR;
		}

		//port B
		else if((Copy_u8PinN>=DIO_PIN_NO_8) && (Copy_u8PinN<=DIO_PIN_NO_15)){

			*Copy_u8Value=GET_BIT(READ_PORT1,(Copy_u8PinN%8));

			return  NO_ERROR;
				}

		//port C
		else if((Copy_u8PinN>=DIO_PIN_NO_16) && (Copy_u8PinN<=DIO_PIN_NO_23)){

			*Copy_u8Value=GET_BIT(READ_PORT2,(Copy_u8PinN%8));

			return  NO_ERROR;
			}

		//port D
		else if((Copy_u8PinN>=DIO_PIN_NO_24) && (Copy_u8PinN<=DIO_PIN_NO_31)){

			*Copy_u8Value=GET_BIT(READ_PORT3,(Copy_u8PinN%8));
			return  NO_ERROR;
				}
		else{
			return ERROR;
		}

	}
	else{

		return ERROR;
	}

}

/*______________________________________________________________________________________________*/
/*Description: Set PORT Type in case of INPUT Direction (PULL UP or FLOATING)
 * Input     :  Copy_u8PortNB (PORT Number),Copy_u8InputType(1 for PULL UP and 0 for FLOATING)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPortInputType(uint8_t Copy_u8PortNB,uint8_t Copy_u8InputType)
{  // AHMED MOSTAFA
	/* Implement Your Code */
	if(Copy_u8PortNB==DIOA){
		//PORT A
		if(Copy_u8InputType>=1){

			DIRECTION_PORT0= DIO_INPUT;
			VALUE_PORT0=Copy_u8InputType;
			return NO_ERROR;
		}
		else{
			return ERROR;
		}}

	//PORT B
	else if(Copy_u8PortNB==DIOB){
		if(Copy_u8InputType>=1){

			DIRECTION_PORT1= DIO_INPUT;
			VALUE_PORT1=Copy_u8InputType;
			return NO_ERROR;
			}
			else{
				return ERROR;
				}}
	//PORT C
	else if(Copy_u8PortNB==DIOC){
		if(Copy_u8InputType>=1){

			DIRECTION_PORT2= DIO_INPUT;
			VALUE_PORT2=Copy_u8InputType;
			return NO_ERROR;
			}
			else{
			return ERROR;
				}}
	//PORT D
	else if(Copy_u8PortNB==DIOD){
		if(Copy_u8InputType>=1){

			DIRECTION_PORT3= DIO_INPUT;
			VALUE_PORT3=Copy_u8InputType;
			return NO_ERROR;
				}
			else{
			return ERROR;
				}

		}
	 else{
		return ERROR;

	}
}
/*______________________________________________________________________________________________*/
/*Description: Set PORT Type in case of INPUT Direction (PULL UP or FLOATING)
 * Input     : Copy_u8PinN(PIN NO) ,Copy_u8InputType(1 for PULL UP and 0 for FLOATING)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPinInputType(uint8_t Copy_u8PinN,uint8_t Copy_u8InputType)
{           // YASMEEN
	/* Implement Your Code */
	if(Copy_u8PinN <= MAX_PIN_NO)
		{
			if(Copy_u8PinN / 8 == 0)  // in PORTA
			{
				if( Copy_u8InputType == PULL_UP)
				{
					SET_BIT(VALUE_PORT0,Copy_u8PinN);    //Enable PULL_UP
					return NO_ERROR;
				}
				else if( Copy_u8InputType == FLOATING)
				{
					CLEAR_BIT(VALUE_PORT0 ,Copy_u8PinN);     //Disable PULL_UP
					return NO_ERROR;
				}
				else
				{
					return ERROR;
				}
			}
			else if(Copy_u8PinN / 8 == 1)  // PORTB
			{
			     Copy_u8PinN-=8;
				if( Copy_u8InputType == PULL_UP)
				{
					SET_BIT(VALUE_PORT1,Copy_u8PinN);		//Enable PULL_UP
					return NO_ERROR;
				}
				else if( Copy_u8InputType == FLOATING)
				{
					CLEAR_BIT(VALUE_PORT1 ,Copy_u8PinN);		//Disable PULL_UP
					return NO_ERROR;
				}
				else
				{
					return ERROR;
				}
			}
			else if(Copy_u8PinN / 8 == 2)  // PORTC
			{
			     Copy_u8PinN -=16;
				if( Copy_u8InputType == PULL_UP)
				{
					SET_BIT(VALUE_PORT2,Copy_u8PinN);		//Enable PULL_UP
					return NO_ERROR;
				}
				else if( Copy_u8InputType == FLOATING)
				{
					CLEAR_BIT(VALUE_PORT2 ,Copy_u8PinN);		//Disable PULL_UP
					return NO_ERROR;
				}
				else
				{
					return ERROR;
				}
			}
			else  // PORTD
			{
				Copy_u8PinN -=24;
				if( Copy_u8InputType == PULL_UP)
				{
					SET_BIT(VALUE_PORT3,Copy_u8PinN);      //Enable PULL_UP
					return NO_ERROR;
				}
				else if( Copy_u8InputType == FLOATING)
				{
					CLEAR_BIT(VALUE_PORT3 ,Copy_u8PinN);   //Disable PULL_UP
					return NO_ERROR;
				}
				else
				{
					return ERROR;
				}
			}

		}
		else
		{
			return ERROR;
		}
}
