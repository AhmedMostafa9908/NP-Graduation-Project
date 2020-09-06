#include "PWM.h"
#include "timer.h"
#include "Dio.h"
#include "PWM_Cfg.h"

void PWM_void_Init(Str_TimerConfiguration_t *timer)
{
	Timer_Init(timer);
	Timer_Start(TIMER0,255);
	DIO_u8Init_PIN(MOTOR_PWM_PIN,DIO_OUTPUT);   /* SET PB0 OUTPUT*/

}


void  PWM_void_SetDutyCycle(uint8_t *Copy_uint16_t_DutyCycle)
{
	while(1)
	{
		if(TCNT0>=*Copy_uint16_t_DutyCycle)
		{
			CLEAR_BIT(VALUE_PORT1,0);
		}
		else
		{
		   SET_BIT(VALUE_PORT1,0);
		}

	}


}
