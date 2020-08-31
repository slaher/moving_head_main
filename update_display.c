#include "update_display.h"
#include "chars_segments.h"

volatile uint8_t display_segment_nr = 0;
char display[3] = {0, 0, 0};

void Update_display(bool invert)
{
	switch (display_segment_nr){
		case 0:
			PORTA &= ~(1 << 1); 
			PORTA &= ~(1 << 2);
			PORTA &= ~(1 << 0);//zeruje bit 0 portu D - wy31cza wyowietlacz nr 1
			PORTA |= (1 << 0); //ustawia bit 1 portu D - w31cza wyowietlacz nr 2
			if (!invert)
				PORTK = display_segment_normal(display[0]);
			else
				PORTK = display_segment_inverted(display[2]);
			display_segment_nr++;
			break;

		case 1:
			PORTA &= ~(1 << 2);
			PORTA &= ~(1 << 0);
			PORTA &= ~(1 << 1); //ustawia bit 0 portu D - w31cza wyowietlacz nr 1
			PORTA |= (1 << 1); //zeruje bit 1 portu D - wy31cza wyowietlacz nr 2
			if (!invert)
				PORTK = display_segment_normal(display[1]);
			else
				PORTK = display_segment_inverted(display[1]);
			display_segment_nr++;
			break;

		case 2:
			PORTA &= ~(1 << 1);
			PORTA &= ~(1 << 0);
			PORTA &= ~(1 << 2); //ustawia bit 0 portu D - w31cza wyowietlacz nr 1
			PORTA |= (1 << 2); //zeruje bit 1 portu D - wy31cza wyowietlacz nr 2
			if (!invert)
				PORTK = display_segment_normal(display[2]);
			else
				PORTK = display_segment_inverted(display[0]);
			display_segment_nr=0;
			break;
	} 
}