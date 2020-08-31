#include "stepper_motor_position.h"

int ldat = 0;
uint8_t datapan;
uint16_t datatilt;
int backpan = 1;	
int backtilt = 1;

void MotorPosition(void)
{
	ldat++;				// pozycja PAN ustawiana co 4 wywo³ania, poniewa¿ pozycji TILT jest 4 razy wiêcej
	
	if (ldat == 4)
	{
		if(datapan>backpan)
		{	
			PORTB = (PORTB & 0xf0) | (pan[backpan] & 0x0f);
			backpan++;
		}
			
		else if (datapan < backpan)
		{
			PORTB = (PORTB & 0xf0) | (pan[backpan] & 0x0f);
			backpan--;
		}
		
		else {};
		
		ldat = 0;
	}
		
	if (datatilt > backtilt)
	{	
		PORTB = (PORTB & 0x0F) | (tilt[backtilt] & 0xF0);
		backtilt++;
	}
			
	else if (datatilt < backtilt)
	{
		PORTB = (PORTB & 0x0F) | (tilt[backtilt] & 0xF0);
		backtilt--;
	}
	
	else {};
	
}
