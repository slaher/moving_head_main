#include "menu_restart_microcontroller.h"

void Menu_restart_microcontroller(void)
{
	while(1){
		if (!(PINA & (1<<BUTTON_SELECT)))
			Restart_microcontroller();
	}
}

void Restart_microcontroller(void)
{
	asm("cli");
	asm("jmp 0");
}