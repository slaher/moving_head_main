#include "program_1.h"

int step_prog_1 = 1;

void  Program_1(void)
{
	if (step_prog_1 == 1)
	{				
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0xFF;
		datatilt = 255*2.5;
		datapan = 1/2.6667;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 2)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 3)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0x00;
		datapan = 255/2.6667;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 4)
	{				
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0xFF;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 5)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		datapan = 1/2.6667;
		step_prog_1++;
	}

	else if (step_prog_1 == 6)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0x00;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 7)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0xFF;
		datatilt = 0*2.5;
		datapan = 255/2.6667;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 8)
	{				
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 9)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0x00;
		datapan = 1/2.6667;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 10)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		datatilt = 0*2.5;
		LED_R_PWM = 0x00;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0xFF;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 11)
	{				
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0x00;
		LED_G_PWM = 0x00;
		LED_B_PWM = 0xFF;
		datapan = 255/2.6667;
		step_prog_1++;
	}
	
	else if (step_prog_1 == 12)
	{
		TCCR5A = 0b00000011;
		PORTL |= (1<<PL4);  
		LED_R_PWM = 0xFF;
		LED_G_PWM = 0xFF;
		LED_B_PWM = 0x00;
		step_prog_1 = 1;
	}

}
