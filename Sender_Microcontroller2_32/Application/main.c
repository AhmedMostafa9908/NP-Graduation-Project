#include "timer.h"
#include "Dio.h"
#include "Std_Types.h"
#include "UART.h"
#include "Switch.h"
#include <avr/interrupt.h>
#include <util/delay.h>

/*  Motor_Speed LookUp Table */
const uint8_t Speed_Array[11]={0x00,0x1A,0x33,0x4D,0x66,0x80,0x99,0xB3,0xCC,0xE6,0xFF};


uint8_t SpeedIndex=5; /*that represnt index of 50 */


/* Interrupt0 ISR */
ISR(INT0_vect)
{
	 _delay_ms(200);

/* Increase speed */
 if(SpeedIndex<10)
   {
    SpeedIndex++;
   }
 else
   {
    SpeedIndex=10;
   }
  UART_sendByte(Speed_Array[SpeedIndex]);
}

/* Interrupt1 ISR */
ISR(INT1_vect){
	 _delay_ms(200);
/* we have to check on SpeedIndex to prevent segmentation error */
 if(SpeedIndex>0)
   {
    SpeedIndex--;
   }
   else
  {
   SpeedIndex=0;
  }

/* then send  Speed_Array[SpeedIndex] to the uart */
 UART_sendByte(Speed_Array[SpeedIndex]);

}


int main()
{

/* UART Initialization */
str_UartConfg_t *UART1,uart1;
UART1=&uart1;
UART1->u32_BaudRate=9600;
UART1->u8_DataBits  =UART_8_BIT_MODE;
UART1->u8_FlagAction=UART_POLLING;
UART_init(UART1);


/* Initialize Increase Speed Button */
Switch_t Switch1,*pswitch1;
pswitch1=&Switch1;
pswitch1->PIN=26;
pswitch1->Mode=INT0_MODE;
pswitch1->Status=PULL_UP;
SwitchInit(pswitch1);

/* Initialize Decrease Speed Button  */
Switch_t Switch2,*pswitch2;
pswitch2=&Switch2;
pswitch2->PIN=27;
pswitch2->Mode=INT1_MODE;
pswitch2->Status=PULL_UP;
SwitchInit(pswitch2);

/* Enable Global Interrupt */
sei();


while(1)
{
}

return 0;
}
