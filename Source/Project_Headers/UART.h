/*
 * UART.h
 *
 *  Created on: 05/11/2016
 *      Author: dartz
 */

#ifndef PROJECT_HEADERS_UART_H_
#define PROJECT_HEADERS_UART_H_

extern char buffer_RX[];
extern char buffer_TX[];

struct fifo {
	unsigned char *buffer;	/* the buffer holding the data */
	unsigned int size;	/* the size of the allocated buffer */
	unsigned int in;	/* data is added at offset (in % size) */
	unsigned int out;	/* data is extracted from off. (out % size) */
};

extern void uart_putchar(char tx_char);


extern unsigned char uart_getchar();


extern void uart_init();


#endif /* PROJECT_HEADERS_UART_H_ */
