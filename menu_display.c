#include "menu_display.h"

bool invert = false;

void Menu_display()
{
	OCR1A = 2250;
							
	Invert_entry_display_update(invert);

	TIMSK1 |= (1 << OCIE1A); 
	while(1){
		if (!(PINA & (1<<BUTTON_MENU))){
			Update_display_variable(data_d, 1, 5);				
			TIMSK1 &= ~(1 << OCIE1A);  
			TIMSK0 |= (1<<OCIE0A);
		
			_delay_ms(300);
			break;
		}
		
		else if (!(PINA & (1<<BUTTON_SELECT))){
			Invert_entry_display_update(invert);
			
			_delay_ms(300);
		
			while(1){
				if (!(PINA & (1<<BUTTON_MENU))){
					_delay_ms(30);
					break;
				}
		
				else if (!(PINA & (1<<BUTTON_SELECT))){
					invert=!invert;
					Invert_entry_display_update(invert);
				
					_delay_ms(300);
				}	
			}
		}
	}
}