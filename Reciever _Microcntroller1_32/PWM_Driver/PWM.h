#ifndef  PWM_H
#define  PWM_H


#include "AVR_Reg.h"
#include "Common_Macros.h"
#include "Std_Types.h"
#include "PWM.h"
#include "stdint.h"
#include "stddef.h"
#include "timer.h"


void PWM_void_Init(Str_TimerConfiguration_t *timer);

void PWM_void_SetDutyCycle(uint8_t* Copy_uint16_t_DutyCycle);














#endif
