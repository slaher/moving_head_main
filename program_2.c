#include "program_2.h"

int step_prog_2 = 1;

void  Program_2(void)
{
	if (step_prog_2 == 1)
	{				
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0xFF;
		datatilt = 255*2.5;
		datapan = 1/2.6667;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 2)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0x00;
		datapan = 255/2.6667;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 3)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		step_prog_2++;
	}
	
	
	else if (step_prog_2 == 4)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		datapan = 1/2.6667;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 5)
	{				
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0xFF;
		step_prog_2++;
	}

	else if (step_prog_2 == 6)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0x00;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 7)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0xFF;
		datatilt = 0*2.5;
		datapan = 255/2.6667;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 8)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		datapan = 1/2.6667;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 9)
	{				
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 10)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0x00;
		step_prog_2 = 1;
	}
	
	else if (step_prog_2 == 11)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		datatilt = 0*2.5;
		LED_R_PWM = 0x00;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0xFF;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 12)
	{				
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		datapan = 255/2.6667;
		step_prog_2++;
	}
	
	else if (step_prog_2 == 13)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0x00;
		datapan = 1/2.6667;
		step_prog_2++;
	}
}
