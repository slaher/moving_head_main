#ifndef USART_H_
#define USART_H_

#include "avr/io.h"


void USART_DMX_Init(unsigned int baudrate0);
void USART_Ethernet_Init(unsigned int baudrate1);


#endif /* USART_H_ */