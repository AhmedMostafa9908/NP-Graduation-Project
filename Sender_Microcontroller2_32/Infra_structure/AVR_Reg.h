/*
 * AVR_Reg.h
 *
 *  Created on: Aug 30, 2020
 *      Author: H
 */

#ifndef DIO_DRIVER_AVR_REG_H_
#define DIO_DRIVER_AVR_REG_H_

#define PORTA *((volatile uint8_t*) 0x3B)
#define PORTB *((volatile uint8_t*) 0x38)
#define PORTC *((volatile uint8_t*) 0x35)
#define PORTD *((volatile uint8_t*) 0x32)

#define PINA *((volatile uint8_t*) 0x39)
#define PINB *((volatile uint8_t*) 0x36)
#define PINC *((volatile uint8_t*) 0x33)
#define PIND *((volatile uint8_t*) 0x30)

#define DDRA *((volatile uint8_t*) 0x3A)
#define DDRB *((volatile uint8_t*) 0x37)
#define DDRC *((volatile uint8_t*) 0x34)
#define DDRD *((volatile uint8_t*) 0x31)


/* Interrupt Registers */
#define  SREG      *((volatile uint8_t*) 0x5F)  /* Status Register */
#define  MCUCR	   *((volatile uint8_t*) 0x55)
#define  MCUCSR    *((volatile uint8_t*) 0x54)
#define  GICR	   *((volatile uint8_t*) 0x5B)
#define  GIFR	   *((volatile uint8_t*) 0x5A)

/* Timer 0   Registers (8 bit Timer/Counter) */
#define  TCCR0	   *((volatile uint8_t*) 0x53)
#define  TCNT0	   *((volatile uint8_t*) 0x52)
#define  OCR0	   *((volatile uint8_t*) 0x5C)


/* Timer 1 Registers (16 bit Timer/Counter) */

#define  TCCR1A    *((volatile uint8_t*)  0x4F)
#define  TCCR1B	   *((volatile uint8_t*)  0x4E)
#define  TCNT1	   *((volatile uint16_t*) 0x4C)
#define  OCR1A	   *((volatile uint16_t*) 0x4A)
#define  OCR1B	   *((volatile uint16_t*) 0x48)
#define  ICR1	   *((volatile uint16_t*) 0x46)



/* Timer 2   Registers (8 bit Timer/Counter) */

#define  TCCR2		*((volatile uint8_t*) 0x45)
#define  TCNT2		*((volatile uint8_t*) 0x44)
#define  OCR2		*((volatile uint8_t*) 0x43)


#define  TIMSK		*((volatile uint8_t*) 0x59)
#define  TIFR		*((volatile uint8_t*) 0x58)

/* UART   Registers  */
#define  UCSRA 		*((volatile uint8_t*) 0x2B)
#define  UCSRB 		*((volatile uint8_t*) 0x2A)
#define  UCSRC 		*((volatile uint8_t*) 0x40)
#define  UBRRL 		*((volatile uint8_t*) 0x29)
#define  UBRRH 		*((volatile uint8_t*) 0x40)

#define  UDRR       *((volatile uint8_t*) 0x2C)
#define  UDRW       *((volatile uint8_t*) 0x2C)

#endif /* DIO_DRIVER_AVR_REG_H_ */
