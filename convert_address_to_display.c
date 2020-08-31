#include "convert_address_to_display.h"

char address_dmx_tab[3] = {0,0,0};

void Convert_address_to_display(int dmx_address)
{	
	address_dmx_tab[0] = (dmx_address/100);
	address_dmx_tab[1] = (dmx_address / 10)%10;
	address_dmx_tab[2] = dmx_address % 10;
	
	Update_display_variable(address_dmx_tab[0], address_dmx_tab[1], address_dmx_tab[2]);
}

