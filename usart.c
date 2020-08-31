#include "usart.h"

void USART_DMX_Init(unsigned int baudrate0)
{
	/* Set baud rate */
	UBRR0H= (unsigned char)(baudrate0>>8);
	UBRR0L = (unsigned char)baudrate0;

	/* Enable receiver and interrupt*/
	UCSR0B= (1<<RXEN0)|(1<<RXCIE0)|(1<<TXEN0);

	/* Set frame format: 9data UCSZ0 = 7, 8data UCSZ0 = 3, 1stop bit */
	UCSR0C = (1<<UCSZ00)|(1<<UCSZ01)|(0<<UCSZ02)|(1<<USBS0);
}


void USART_Ethernet_Init(unsigned int baudrate1)
{
	/* Set baud rate */
	UBRR1H= (unsigned char)(baudrate1>>8);
	UBRR1L = (unsigned char)baudrate1;
	/* Enable receiver and interrupt*/
	UCSR1B= (1<<RXEN1)|(1<<RXCIE1);

	/* Set frame format: 9data UCSZ0 = 7, 8data UCSZ0 = 3, 1stop bit */
	UCSR1C = (1<<UCSZ10)|(1<<UCSZ11)|(0<<UCSZ12)|(1<<USBS1);
}