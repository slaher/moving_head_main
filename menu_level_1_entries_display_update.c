#include "menu_level_1_entries_display_update.h"

int menu_entry_nr = 1;

void Menu_level_1_entries_display_update(int entry_nr)
{
	switch (menu_entry_nr){
		case 1:
			Update_display_variable(data_A, data_d, data_r);
			break;
					
		case 2:		
			Update_display_variable(data_d, data_i, data_S);
			break;
					
		case 3:
			Update_display_variable(data_P, data_r, data_r);
			break;
					
		case 4:
			Update_display_variable(data_r, data_S, data_t);
			break;
	}				
	_delay_ms(250);	
}