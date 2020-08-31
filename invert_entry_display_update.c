#include "invert_entry_display_update.h"

void Invert_entry_display_update(bool invert)
{
	if(!invert)
		Update_display_variable(data_empty, data_n, 0);				
	
	else
		Update_display_variable(data_Y, data_E, data_S);
}
