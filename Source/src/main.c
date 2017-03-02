/*
 * main.c
 *
 *  Created on: 05/11/2016
 *      Author: dartz
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "../Project_Headers/UART.h"
#include "../Project_Headers/Timers.h"
#include "../Project_Headers/ADC.h"

#define TRUE 1
#define FALSE 0

int main(void){
	uart_init();
	PWM_init();
	adc_init();
	unsigned char input[16];
	unsigned char n = 0;

	while(TRUE) {
		while (n <= 15){
			input[n] = uart_getchar();
			if (input[0] == 0x7E) n++;
		}
		/*for (unsigned char i = 0; i < 16; i++){
			input[i] = uart_getchar();
		}*/
		n = input[0] = 0;
		//OCR1A = adc_read(0);
		OCR1B = adc_read(1);
		OCR1A = ((unsigned int)input[13] << 8) + input[14];

		//input[0] = uart_getchar();
		//uart_putchar(input[0]);
	}
	return 0;
}
