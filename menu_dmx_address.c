#include "menu_dmx_address.h"

int address_dmx = 0;

void Menu_dmx_address()
{
	OCR1A = 2250; // U
		Convert_address_to_display(address_dmx);				
	
		TIMSK1 |= (1 << OCIE1A);  
		while(1){
			if (!(PINA & (1<<BUTTON_MENU))){
				eeprom_write_word((uint16_t *)140,address_dmx);

				Update_display_variable(data_A, data_d, data_r);				

				TIMSK1 &= ~(1 << OCIE1A);   
				TIMSK0 |= (1<<OCIE0A);
				_delay_ms(300);

			break;
		}
	
	
	//////////// KLAWISZ+++++++++++++
	
		else if(bit_is_clear(PINA,BUTTON_UP)){
			TIMSK1 &= ~(1 << OCIE1A);  
			address_dmx++;
			
			if (address_dmx>512) 
				address_dmx=1;
			Convert_address_to_display(address_dmx);				

		
		_delay_ms(200); 
			 
		while(1){
			if(bit_is_clear(PINA,BUTTON_UP)){
			TIMSK0 |= (1<<OCIE0A);   
				address_dmx++;
				if (address_dmx>512) 
					address_dmx=1;
				Convert_address_to_display(address_dmx);				

				_delay_ms(20); 
			}

			else break;
		} //koniec while
		
	TIMSK1 |= (1 << OCIE1A);
	}

	///////////KLAWISZ --

	else if(bit_is_clear(PINA,BUTTON_DOWN)) {
		TIMSK1 &= ~(1 << OCIE1A); 
		address_dmx--;
		if (address_dmx<1) 
			address_dmx=512;				
		Convert_address_to_display(address_dmx);				

		_delay_ms(200); 
			 
		while(1){
			if(bit_is_clear(PINA,BUTTON_DOWN)){
				TIMSK0 |= (1<<OCIE0A);	
				address_dmx--;
				if (address_dmx<1) 
					address_dmx=512;
				Convert_address_to_display(address_dmx);				

				_delay_ms(20); 
			}

			else break;
		} //koniec while
	
		TIMSK1 |= (1 << OCIE1A);        
	}				
			
}
}