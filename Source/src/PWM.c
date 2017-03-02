/*
 * PWM.c
 *
 *  Created on: 27/11/2016
 *      Author: dartz
 */

#include <avr/io.h>
#include "../Project_Headers/Timers.h"

void PWM_init(){
	DDRB |= (1 << DDB1)|(1 << DDB2); // PB1 and PB2 is now an output
	//ICR1 = 0x3FFF; // set TOP to 10 bits
	OCR1A = 0x00FF; // set PWM for 25% duty cycle @ 10bit
	OCR1B = 0x02FF; // set PWM for 75% duty cycle @ 10bit
	TCCR1B |= _BV(CS10); // START the timer with no Prescaler
	TCCR1A |= _BV(COM1A1) | _BV(COM1B1); // set none-inverting mode
	TCCR1A |= _BV(WGM11) | _BV(WGM10);
	TCCR1B |= _BV(WGM12); // set Fast PWM mode using ICR1 as TOP
}

