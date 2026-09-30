#include "usart.h"
#include <avr/io.h>

void USART_init(unsigned int ubrr)
{
	/* seteaza baud rate-ul */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;

	/* porneste transmitatorul */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);

	UCSR0C = 3<<UCSZ00;
}

void USART_transmit(char data)
{
	/* asteapta pana bufferul e gol */
	while(!(UCSR0A & (1<<UDRE0)));

	/* pune datele in buffer; transmisia va porni automat in urma scrierii */
	UDR0 = data;
}

char USART_receive()
{
	/* asteapta cat timp bufferul e gol */
	while(!(UCSR0A & (1<<RXC0)));

	/* returneaza datele din buffer */
	return UDR0;
}

void USART_print(const char *data)
{
	while(*data != '\0')
		USART_transmit(*data++);
}