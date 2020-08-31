#include "led_rgb_methods.h"

uint16_t strobeB=0;
uint16_t strobeA=0;

void Strobe_method(uint8_t data_dmx_input)
{
	cli();
	if(data_dmx_input>19){
		strobeA=700+(255-data_dmx_input)*119;
		strobeB=strobeA*0.9;
		OCR5B=strobeB;
		OCR5A=strobeA;		
		TCCR5A=0b00110011;		
	}

	else if (data_dmx_input<10){
		TCCR5A=0b00000011;
		PORTL|=(1<<PL4);  
	}

	else{
		TCCR5A=0b0000011;
		PORTL&=~(1<<PL4);				 
	}
	
	sei();						
}