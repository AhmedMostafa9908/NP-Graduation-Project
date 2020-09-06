
#include "Switch.h"


//////////////////////////////////////////////////////////////////////////////
uint8_t SwitchInit(Switch_t* My_Switch)
{
    // Checking if the input pin number is within the acceptable pin numbers (0-31).
    if (My_Switch->PIN >= MINIMUM_PIN_NO && My_Switch->PIN <= MAX_PIN_NO)
    {
        // Setting the switch pin direction to being input.
        DIO_u8Init_PIN(My_Switch->PIN, DIO_INPUT);

    }
    else
    {
        return ERROR;
    }

    // Checking switch's status for being set to pull up or floating.
    if (My_Switch->Status == PULL_UP || My_Switch->Status == FLOATING)
    {
        // Setting the switch's pin input type to either pull up (1) or floating (0).
        DIO_u8SetPinInputType(My_Switch->PIN, My_Switch->Status);

    }
    else
    {
        return ERROR;
    }

    // Checking if the switch's mode is a valid value.
    if (My_Switch->Mode == INT0_MODE || My_Switch->Mode == INT1_MODE || My_Switch->Mode == INT2_MODE || My_Switch->Mode == POLLING_MODE)
    {
        // Activating interrupt 0 (INT0).
        if (My_Switch->Mode == INT0_MODE)
        {
            // Setting GICR register's bit 6 to 1 to activate INT0.
            SET_BIT(General_Interrupt_CR, 6);
            // Setting INT0 occurrence condition (on a logical change).
            SET_BIT(MCU_control_register, 0);
            SET_BIT(MCU_control_register, 1);
        }
        // Activating interrupt 1 (INT1).
        else if (My_Switch->Mode == INT1_MODE)
        {
            // Setting GICR register's bit 7 to 1 to activate INT1.
            SET_BIT(General_Interrupt_CR, 7);
            // Setting INT1 occurrence condition (on a logical change).
            SET_BIT(MCU_control_register, 2);
            SET_BIT(MCU_control_register, 3);
        }
        // Activating interrupt 2 (INT2).
        else if (My_Switch->Mode == INT2_MODE)
        {
            // Setting GICR register's bit 5 to 1 to activate INT2.
            SET_BIT(General_Interrupt_CR, 5);
            // Setting INT2 occurrence condition (on a rising edge).
            SET_BIT(MCU_control_and_status_register, 6);
        }
        // There is nothing to do when the mode is set to polling.
        return NO_ERROR;
    }
    else
    {
        return ERROR;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
void Enable_Global_Interrupt(void) {

	// Enable global interrupt for SREG register

	SET_BIT(status_Register, pin7);


}
/////////////////////////////////////////////////////////////////////////////////////////
uint8_t IsPressed(Switch_t* My_Switch, uint8_t* Status) {

	// Check if th button pressed by using Get_PinValue'
	if(My_Switch->PIN >= MINIMUM_PIN_NO && My_Switch->PIN <= MAX_PIN_NO){

		DIO_u8GetPinValue(My_Switch->PIN,Status);

		return NO_ERROR;
	}
	return ERROR;
}










