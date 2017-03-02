/*
 * UART.c
 *
 *  Created on: 05/11/2016
 *      Author: dartz
 */

#include <avr/io.h>
#include "../Project_Headers/UART.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#ifndef BAUD
#define BAUD 115200
#endif
#include <util/setbaud.h>

#define BUFFER_SIZE 20 //Buffer Size for both Tx & Rx

char buffer_RX[BUFFER_SIZE]; //Buffer Array Rx
char buffer_TX[BUFFER_SIZE]; //Buffer Array Tx

void uart_init() {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */
}

void uart_putchar(char tx_char) {
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = tx_char;
}

unsigned char uart_getchar() {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}
