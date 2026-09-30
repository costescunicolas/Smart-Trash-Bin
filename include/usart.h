#ifndef USART_H_
#define USART_H_

#include <stdio.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#define BAUD 9600
#define MYUBBR ((F_CPU / (16UL * BAUD)) - 1)

void USART_init(unsigned int ubrr);
void USART_transmit(char data);
char USART_receive();
void USART_print(const char *str);


#endif // USART_H_