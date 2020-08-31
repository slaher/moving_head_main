#include "menu_program.h"

int program_nr = 1;

void Menu_program()
{
	OCR1A = 2250;
							
	Update_display_variable(data_P, data_r, program_nr);			
		
	TIMSK1 |= (1 << OCIE1A); 
	while(1){
		if (!(PINA & (1<<BUTTON_MENU))){
			Update_display_variable(data_P, data_r, data_r);			
			TIMSK1 &= ~(1 << OCIE1A);  
			TIMSK0 |= (1<<OCIE0A);
			
			_delay_ms(300);
			break;
		}
		
		else if (!(PINA & (1<<BUTTON_SELECT))){
			Update_display_variable(data_P, data_r, program_nr);
			_delay_ms(300);

			while(1){
				if (!(PINA & (1<<BUTTON_MENU))){
					_delay_ms(30);
					break;
				}

				else if (!(PINA & (1<<BUTTON_SELECT))){
					program_nr++;
					if (program_nr==3)
						program_nr=1;
					Update_display_variable(data_P, data_r, program_nr);

					_delay_ms(300);
				}
			}
		}
	}
}
