#include  "AVR_Reg.h"
#include "timer.h"
#include "Dio.h"
#include "UART.h"
#include "Std_Types.h"
#include <avr/io.h>
#include  <avr/interrupt.h>
#include "LCD.h"
#include <util/delay.h>
#include "PWM.h"

uint8_t Recieved_Speed,*PRecieved_Speed;

void RX_MyISR (void)
{
	*PRecieved_Speed=USART_DATA_REGISTER_READ;
	 LCD_clearScreen();
	 uint8_t speed[] ="Speed= ";
	 LCD_displayString(speed);
	 LCD_goToRowColumn(1, 8);
	 LCD_integerToString((Recieved_Speed*100)/255);

}


int main()

{

	PRecieved_Speed=&Recieved_Speed;

	//UART Initialization
	str_UartConfg_t *UART1,uart1;
	UART1=&uart1;
	UART1->u32_BaudRate=9600;
	UART1->u8_DataBits=UART_8_BIT_MODE;
	UART1->u8_FlagAction=UART_INTERRUPT;
	UART_init(UART1);

	/* PWM Initialization */
	Str_TimerConfiguration_t *timer0 ,Timer0;
	timer0 = &Timer0;
	Timer0.Interrupt_Mode = POLLING;
	Timer0.Timer_Channel = TIMER0;
	Timer0.Timer_Mode = TIMER_MODE;
	Timer0.Timer_Psc = F_CPU_CLOCK_1024_TIMER_0;
	PWM_void_Init(timer0);

	/* Enable Global Interrupt */
	sei();
	UART_RX_SetCallBack(RX_MyISR);
   Recieved_Speed=0x80;

	/* LCD Initialization */
	LCD_init();
	uint8_t speed[] ="Speed= ";
	LCD_displayString(speed);
	LCD_goToRowColumn(1, 8);
	LCD_integerToString((Recieved_Speed*100)/255);


while (1)
{
	PWM_void_SetDutyCycle(PRecieved_Speed);

}
      return 0;

}
