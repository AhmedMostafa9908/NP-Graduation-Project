/*
 * timer.c
 *
 *  Created on: Aug 31, 2020
 *      Author: H
 */
#include "timer.h"
#include "Dio.h"


static Str_TimerConfiguration_t Timers[NO_OF_CHANNELS];
static uint16_t TickCounts[NO_OF_CHANNELS];
/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Initialization
 * Input     : Timer_Configuration_S* Confg_S (Struct contain : Timer Channel, Prescaler , Mode as described in Struct)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Init(Str_TimerConfiguration_t* Confg_S)
{
/************************************** Initialization for Timer0 ******************************************************/
	if (Confg_S->Timer_Channel == TIMER0)
	{  /*Configuration for TIMER0 */
		Timers[TIMER0].Timer_Channel = TIMER0;
		if (Confg_S->Interrupt_Mode == POLLING)
		{  /*Initialization for polling*/
			Timers[TIMER0].Interrupt_Mode = POLLING;
			if (Confg_S->Timer_Mode == TIMER_MODE)
			{
				Timers[TIMER0].Timer_Mode = TIMER_MODE;
				Timers[TIMER0].Timer_Psc = Confg_S->Timer_Psc;
				/* CTC Mode */
				SET_BIT(TIMER0_CONTROL_REGISTER, TIMER0_CONTROL_WAVEGENERATION_01);
				CLEAR_BIT(TIMER0_CONTROL_REGISTER, TIMER0_CONTROL_WAVEGENERATION_00);



			}
			else if (Confg_S->Timer_Mode == COUNTER_MODE)
			{
				Timers[TIMER0].Timer_Mode = COUNTER_MODE;
				/* Write your counter initialization here*/
			   /* As we don't support counter mode*/
				return ERROR_OK;
			}

			else
			{

				return ERROR_OK;
			}
		}
		/* Interrupt Mode */
		else if (Confg_S->Interrupt_Mode == INTERRUPT)
		{
			Timers[TIMER0].Interrupt_Mode = INTERRUPT;
			/*Initialization for Interrupt */
			if (Confg_S->Timer_Mode == TIMER_MODE)
			{
				Timers[TIMER0].Timer_Mode = TIMER_MODE;
				/* Write your timer initialization here*/
				Timers[TIMER0].Timer_Psc = Confg_S->Timer_Psc;

				/*CTC mode*/
				SET_BIT(TIMER0_CONTROL_REGISTER, TIMER0_CONTROL_WAVEGENERATION_01);
				CLEAR_BIT(TIMER0_CONTROL_REGISTER, TIMER0_CONTROL_WAVEGENERATION_00);

				/*Enable Timer0 Compare Match Interrupt */
				SET_BIT(TIMER_INTERRUPT_MASK_REGISTER, TIMER0_INTERRUPT_COMPARE_MATCH_ENABLE_BIT);

				/*Enable Global Interrupt */
				SET_BIT(STATUS_REGISTER, GLOBAL_INTERRUPT_BIT);
			}
			else if (Confg_S->Timer_Mode == COUNTER_MODE)
			{
				Timers[TIMER0].Timer_Mode = COUNTER_MODE;
				/* Write your counter initialization here*/
			   /* As we don't support counter mode*/
				return ERROR_OK;
			}
			else
			{
				return ERROR_OK;
			}
		}
		else {
			return ERROR_OK;
		}
	}

/******************************	 Initialization for Timer1  ******************************************************/

	else if (Confg_S->Timer_Channel == TIMER1)
	{
		/*Configuration for TIMER1 */
		Timers[TIMER1].Timer_Channel = TIMER1;
		if (Confg_S->Interrupt_Mode == POLLING)
		{
			Timers[TIMER1].Interrupt_Mode = POLLING;
			/*Initialization for polling */
			if (Confg_S->Timer_Mode == TIMER_MODE)
			{
				Timers[TIMER1].Timer_Mode = TIMER_MODE;
				Timers[TIMER1].Timer_Psc = Confg_S->Timer_Psc;

				/*CTC Mode*/
				CLEAR_BIT(TIMER1_CONTROL_REGISTER_A, TIMER0_CONTROL_WAVEGENERATION_10);
				CLEAR_BIT(TIMER1_CONTROL_REGISTER_A, TIMER0_CONTROL_WAVEGENERATION_11);
				SET_BIT  (TIMER1_CONTROL_REGISTER_B, TIMER0_CONTROL_WAVEGENERATION_12);
				CLEAR_BIT(TIMER1_CONTROL_REGISTER_B, TIMER0_CONTROL_WAVEGENERATION_13);
			}

			else if (Confg_S->Timer_Mode == COUNTER_MODE)
			{
				Timers[TIMER1].Timer_Mode = COUNTER_MODE;
				return ERROR_OK;
			}
			else
			{
				return ERROR_OK;
			}
		}
		else if (Confg_S->Interrupt_Mode == INTERRUPT) {
			/*Initialization for Interrupt */
			Timers[TIMER1].Interrupt_Mode = INTERRUPT;
			if (Confg_S->Timer_Mode == TIMER_MODE)
			{
				Timers[TIMER1].Timer_Mode = TIMER_MODE;

				/*CTC Mode*/
				CLEAR_BIT(TIMER1_CONTROL_REGISTER_A, TIMER0_CONTROL_WAVEGENERATION_10);
				CLEAR_BIT(TIMER1_CONTROL_REGISTER_A, TIMER0_CONTROL_WAVEGENERATION_11);
				SET_BIT  (TIMER1_CONTROL_REGISTER_B, TIMER0_CONTROL_WAVEGENERATION_12);
				SET_BIT  (TIMER1_CONTROL_REGISTER_B, TIMER0_CONTROL_WAVEGENERATION_13);

				/*Enable Global Interrupt*/
				SET_BIT(STATUS_REGISTER, GLOBAL_INTERRUPT_BIT);

				/*Enable Timer1 Compare Match Interrupt*/
				SET_BIT(TIMER_INTERRUPT_MASK_REGISTER, TIMER1_INTERRUPT_COMPARE_MATCH_ENABLE_BIT);
				Timers[TIMER1].Timer_Psc = Confg_S->Timer_Psc;
			}
			else if (Confg_S->Timer_Mode == COUNTER_MODE)
			{
				Timers[TIMER1].Timer_Mode = COUNTER_MODE;
				return ERROR_OK;
			}
			else
			{
				return ERROR_OK;
			}
		}
		else
		{
			return ERROR_OK;
		}

	}

/************************************  Initialization for Timer2  **********************************************/

	else if (Confg_S->Timer_Channel == TIMER2)
	{
		/*Configuration for TIMER2*/
		Timers[TIMER2].Timer_Channel = TIMER2;
		if (Confg_S->Interrupt_Mode == POLLING)
		{
			Timers[TIMER2].Interrupt_Mode = POLLING;
			/*Initialization for Polling */
			if (Confg_S->Timer_Mode == TIMER_MODE)
			{
				Timers[TIMER2].Timer_Mode = TIMER_MODE;
				Timers[TIMER2].Timer_Psc = Confg_S->Timer_Psc;

				/*CTC Mode */
				SET_BIT  (TCCR2, TIMER0_CONTROL_WAVEGENERATION_21);
				CLEAR_BIT(TCCR2	,TIMER0_CONTROL_WAVEGENERATION_20);
			}
			else if (Confg_S->Timer_Mode == COUNTER_MODE)
			{
				Timers[TIMER2].Timer_Mode = COUNTER_MODE;
				return ERROR_OK;
			}
			else
			{
				return ERROR_OK;
			}
		}
		else if (Confg_S->Interrupt_Mode == INTERRUPT)
		{  /* Initialization for interrupt */
			Timers[TIMER2].Interrupt_Mode = INTERRUPT;
			if (Confg_S->Timer_Mode == TIMER_MODE)
			{
				Timers[TIMER2].Timer_Mode = TIMER_MODE;

				/* CTC Mode */
				SET_BIT(TCCR2, TIMER0_CONTROL_WAVEGENERATION_21);
				CLEAR_BIT(TCCR2, TIMER0_CONTROL_WAVEGENERATION_20);
				/*Enable Global Interrupt */
				SET_BIT(STATUS_REGISTER, GLOBAL_INTERRUPT_BIT);

				/*Enable Timer2 Compare Match Interrupt */
				SET_BIT(TIMER_INTERRUPT_MASK_REGISTER, TIMER2_INTERRUPT_COMPARE_MATCH_ENABLE_BIT);
				Timers[TIMER2].Timer_Psc = Confg_S->Timer_Psc;
			}
			else if (Confg_S->Timer_Mode == COUNTER_MODE)
			{
				Timers[TIMER2].Timer_Mode = COUNTER_MODE;
				return ERROR_OK;
			}
			else
			{
				return ERROR_OK;
			}

		}
		else
		{
			return ERROR_OK;
		}

	}

	else
	{
		return ERROR_OK;
	}
	return ERROR_NOK;
}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Start
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), Tick Counting (Counts given by user)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/

uint8_t Timer_Start(uint8_t Copy_uint8_TimerChannel, uint16_t Copy_uint16_TickCounts)
{
	switch (Copy_uint8_TimerChannel)
	{
/**************************************     TIMER0  **************************************************************/
		case TIMER0:
		{
			TIMER0_COUNTER_REGISTER = 0x00; /* to Start from Zero */
			TickCounts[TIMER0] = Copy_uint16_TickCounts;
			TIMER0_OUTPUT_COMPARE_MATCH = Copy_uint16_TickCounts;
			if (Timers[TIMER0].Timer_Psc == F_CPU_CLOCK_TIMER_0)
			{ /*  No Prescaler */
				TIMER0_CONTROL_REGISTER |= (1<<CS00);
				return ERROR_NOK;
			}
			else if (Timers[TIMER0].Timer_Psc == F_CPU_CLOCK_8_TIMER_0)
			{	/* clkI/O /8 */
				TIMER0_CONTROL_REGISTER |= (1<<CS01);
				return ERROR_NOK;
			}
			else if (Timers[TIMER0].Timer_Psc == F_CPU_CLOCK_64_TIMER_0)
			{  /*  clkI/O /64 */
				TIMER0_CONTROL_REGISTER |= (1<<CS00) |(1<<CS01);
				return ERROR_NOK;
			}
			else if (Timers[TIMER0].Timer_Psc == F_CPU_CLOCK_256_TIMER_0)
			{   /*  clkI/O /256 */
				TIMER0_CONTROL_REGISTER |= (1<<CS02);
				return ERROR_NOK;
			}
			else if (Timers[TIMER0].Timer_Psc == F_CPU_CLOCK_1024_TIMER_0)
			{   /*  clkI/O /1024 */
				TIMER0_CONTROL_REGISTER |= (1<<CS00) |(1<<CS02);
				return ERROR_NOK;
			}
			else if (Timers[TIMER0].Timer_Psc == F_EXTERNAL_CLOCK_FALLING_TIMER_0)
			{
				TIMER0_CONTROL_REGISTER |=(1<<CS01) |(1<<CS02);
				return ERROR_NOK;
			}
			else if (Timers[TIMER0].Timer_Psc == F_EXTERNAL_CLOCK_RISING_TIMER_0)
			{
				TIMER0_CONTROL_REGISTER |=(1<<CS00) |(1<<CS01) |(1<<CS02);
				return ERROR_NOK;
			}
			else
			{
				return ERROR_OK;
			}

		}
		break;

/***************************************** TIMER1  ***************************************************************/
		case TIMER1:
		{
			TIMER1_COUNTER_REGISTER = 0x00; /* to start from zero */
			TickCounts[TIMER1] = Copy_uint16_TickCounts;
			TIMER1A_OUTPUT_COMPARE_MATCH = Copy_uint16_TickCounts;
			if (Timers[TIMER1].Timer_Psc == F_CPU_CLOCK_TIMER_1)
			{ /*  No Prescaler */
				TIMER1_CONTROL_REGISTER_B |=(1<<CS10);
				return ERROR_NOK;
			}
			else if (Timers[TIMER1].Timer_Psc == F_CPU_CLOCK_8_TIMER_1)
			{
				TIMER1_CONTROL_REGISTER_B |= (1<<CS11);
				return ERROR_NOK;
			}
			else if (Timers[TIMER1].Timer_Psc == F_CPU_CLOCK_64_TIMER_1)
			{
				TIMER1_CONTROL_REGISTER_B |=(1<<CS10) |(1<<CS11);
				return ERROR_NOK;
			}
			else if (Timers[TIMER1].Timer_Psc == F_CPU_CLOCK_256_TIMER_1)
			{
				TIMER1_CONTROL_REGISTER_B |= (1<<CS12);
				return ERROR_NOK;
			}
			else if (Timers[TIMER1].Timer_Psc == F_CPU_CLOCK_1024_TIMER_1)
			{
				TIMER1_CONTROL_REGISTER_B |= (1<<CS10)|(1<<CS12);
				return ERROR_NOK;
			}
			else if (Timers[TIMER1].Timer_Psc == F_EXTERNAL_CLOCK_FALLING_TIMER_1)
			{
				TIMER1_CONTROL_REGISTER_B |= (1<<CS11)|(1<<CS12);
				return ERROR_NOK;
			}
			else if (Timers[TIMER1].Timer_Psc == F_EXTERNAL_CLOCK_RISING_TIMER_1)
			{
				TIMER1_CONTROL_REGISTER_B |= (1<<CS10)|(1<<CS11)|(1<<CS12);
				return ERROR_NOK;
			}
			else
			{
				return ERROR_OK;
			}
		}

		break;

/*********************************    TIMER2     ******************************************************************/

		case TIMER2:
		{
			TIMER2_COUNTER_REGISTER = 0x00; /* to start from zero */
			TickCounts[TIMER2] = Copy_uint16_TickCounts;
			TIMER2_OUTPUT_COMPARE_MATCH = Copy_uint16_TickCounts;
			if (Timers[TIMER2].Timer_Psc == F_CPU_CLOCK_TIMER_2)
			{ /*  No Prescaler  */
				TIMER2_CONTROL_REGISTER |=(1<<CS20);
				return ERROR_NOK;
			}
			else if (Timers[TIMER2].Timer_Psc == F_CPU_CLOCK_8_TIMER_2)
			{
				TIMER2_CONTROL_REGISTER |= (1<<CS21);
				return ERROR_NOK;
			}
			else if (Timers[TIMER2].Timer_Psc == F_CPU_CLOCK_32_TIMER_2)
			{
				TIMER2_CONTROL_REGISTER |=(1<<CS20)|(1<<CS21);
				return ERROR_NOK;
			}
			else if (Timers[TIMER2].Timer_Psc == F_CPU_CLOCK_64_TIMER_2)
			{
				TIMER2_CONTROL_REGISTER |= (1<<CS22);
				return ERROR_NOK;
			}
			else if (Timers[TIMER2].Timer_Psc == F_CPU_CLOCK_128_TIMER_2)
			{
				TIMER2_CONTROL_REGISTER |=(1<<CS20)|(1<<CS22);
				return ERROR_NOK;
			}
			else if (Timers[TIMER2].Timer_Psc == F_CPU_CLOCK_256_TIMER_2)
			{
				TIMER2_CONTROL_REGISTER |=(1<<CS21)|(1<<CS22);
				return ERROR_NOK;
			}
			else if (Timers[TIMER2].Timer_Psc == F_CPU_CLOCK_1024_TIMER_2)
			{
				TIMER2_CONTROL_REGISTER |=(1<<CS20)|(1<<CS21)|(1<<CS22);
				return ERROR_NOK;
			}
			else
			{
				return ERROR_OK;
			}
		}

		break;
		default:
			return ERROR_OK;
		break;

  }
return ERROR_NOK;
}

/*_______________________________________________________________________________________________________________________________*/


/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Stop
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Stop(uint8_t Copy_uint8_TimerChannel)
{
	switch (Copy_uint8_TimerChannel)
	{
	case TIMER0:
	{
		CLEAR_BIT(TIMER0_CONTROL_REGISTER, CS00);
		CLEAR_BIT(TIMER0_CONTROL_REGISTER, CS01);
		CLEAR_BIT(TIMER0_CONTROL_REGISTER, CS02);
		return ERROR_OK;
	}
		break;

	case TIMER1:
	{
		CLEAR_BIT(TIMER1_CONTROL_REGISTER_B, CS10);
		CLEAR_BIT(TIMER1_CONTROL_REGISTER_B, CS11);
		CLEAR_BIT(TIMER1_CONTROL_REGISTER_B, CS12);
		return ERROR_OK;
	}
	break;
	case TIMER2:
	{
		CLEAR_BIT(TIMER2_CONTROL_REGISTER, CS20);
		CLEAR_BIT(TIMER2_CONTROL_REGISTER, CS21);
		CLEAR_BIT(TIMER2_CONTROL_REGISTER, CS22);
		return ERROR_OK;
	}
	break;

	default:
		return ERROR_NOK;
	break;
	}
}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer Reset
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Reset(uint8_t Copy_uint8_TimerChannel)
{
	//checker if the inputs are correct or not
	if (Copy_uint8_TimerChannel == TIMER0 || Copy_uint8_TimerChannel == TIMER1 || Copy_uint8_TimerChannel == TIMER2)
	{
		if (Copy_uint8_TimerChannel == TIMER0)
		{

			TIMER0_COUNTER_REGISTER =0x00;
		}
		else if (Copy_uint8_TimerChannel == TIMER1)
		{

			TIMER1_COUNTER_REGISTER=0x00;
		}
		else
		{
			TIMER2_COUNTER_REGISTER=0x00;
		}

		return ERROR_NOK;
	}
	else
	{
		return ERROR_OK;
	}
}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Get Timer Tick Time value to use it by user
 * Input     : Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), *Timer_Time (Pointer to return Value)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Get_TickTime(uint8_t Copy_uint8_TimerChannel, uint32_t* Copy_uint8Ptr_TimerTickTime)
{
	if (Copy_uint8Ptr_TimerTickTime == NULL)
	{
		return ERROR_OK; /* error occurred as the pointer points to null */
	}
	else
	{
		if (Copy_uint8_TimerChannel == TIMER0 || Copy_uint8_TimerChannel == TIMER1 || Copy_uint8_TimerChannel == TIMER2)
		{
			if (Copy_uint8_TimerChannel == TIMER0)
			{
				*Copy_uint8Ptr_TimerTickTime = Timers[0].Timer_Psc / CPU_FREQ;   // CPU_Frequency is defined in this file.
			}
			else if (Copy_uint8_TimerChannel == TIMER1)
			{
				*Copy_uint8Ptr_TimerTickTime = Timers[1].Timer_Psc / CPU_FREQ;
			}
			else if (Copy_uint8_TimerChannel == TIMER2)
			{
				*Copy_uint8Ptr_TimerTickTime = Timers[2].Timer_Psc / CPU_FREQ;
			}

		}
		else
		{
			return ERROR_OK; /*error occurred as Timer channel is not supported */
		}
	}return ERROR_NOK;  /* no error occurred*/
}
/*_______________________________________________________________________________________________________________________________*/



