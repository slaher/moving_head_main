#include "main.h"

volatile int external_dmx_address_count = 0;		
volatile int internal_dmx_address_count = 0;
enum {IDLE, BREAK, STARTB, STARTADR};  //DMX states 
volatile uint8_t gDmxState = IDLE; 
volatile uint8_t dmx_state;
volatile uint8_t data_dmx_input;

volatile uint8_t DmxState;

uint8_t eeprom_val __attribute__((section(".eeprom")));
volatile int i=0;
char ver[] __attribute__((section(".eeprom"))) = "Wersja z " __DATE__ " " __TIME__ "\0";

volatile int gg=0;
volatile uint16_t prv=0;
volatile uint16_t prvstrobe2=0;

volatile uint8_t led_R_previous_value=0;
volatile uint8_t led_G_previous_value=0;
volatile uint8_t led_B_previous_value=0;
volatile uint8_t eth_msg_nr=0;
volatile uint8_t data_eth_input;


int main(void)
{
	PositionTable();

	address_dmx=eeprom_read_word 	( 	(uint16_t *)  140	);
	if (address_dmx<1 || address_dmx>512)
		address_dmx=1;
	
	// LEDs on display
	DDRD|=(1<<LED_GREEN);		// output
	DDRD|=(1<<LED_RED);		// output
	DDRD|=(1<<LED_AMBER);		// output
	
	PORTD&=!(1<<LED_GREEN);	// ENABLE green LED
	PORTD|=(1<<LED_RED);		// DISABLE RED LED
	PORTD|=(1<<LED_AMBER);		// DISABLE AMBER LED
	
	//	RGB LEDs
	DDRH|=(1<<PH3);	// output for RED LED
	DDRH|=(1<<PH5);	// output for GREEN LED
	DDRH|=(1<<PH4);	// output for BLUE LED
	
	// stepper motor
	DDRB = 0xFF;	//	output for stepper motor
	PORTB = 0x00;
	
	DDRC = 0xFF;
	PORTC = 0x00;
	DDRK=0xFF;
	
	DDRL = 0xFF;
	PORTL = 0x00;
		
	DDRA=(1<<0)|(1<<1)|(1<<2);
	DDRA&=~(1<<4)|~(1<<5)|~(1<<6)|~(1<<7);
	PORTA=(1<<0)|(1<<1)|(1<<2)|(1<<4)|(1<<5)|(1<<6)|(1<<7);

	DDRD&=~(1<<PD3);
	PORTD|=(1<<PD3);
	
	//	INT 3 interrupt enable for sound
	EIMSK|=(1<<INT3);		//	INT3 interrupt enable - sound
	EICRA|=(1<<ISC31);		//	The rising edge of INTn generates asynchronously an interrupt request
	EICRA|=(1<<ISC30);		//	The rising edge of INTn generates asynchronously an interrupt request

	

	//    TIMER  //	
	TCCR2B |= 0b00011101;	//	prescaler 128, fast PWM, TOP: OCRA, Update of OCRx at: BOTTOM, TOV Flag Set on: TOP
	TCCR2A |= 0b00000011; 	//	prescaler 128, fast PWM, TOP: OCRA, Update of OCRx at: BOTTOM, TOV Flag Set on: TOP
	OCR2A=255;				//	initialize with 0xFF
	TIMSK2 |= (1<<OCIE2A);	//	interrupt timer enabled
				
	TCCR1B=0b00011101;		//prescaler 1024, fast PWM, TOP: OCRnA, Update of OCRx at: BOTTOM, TOV Flag Set on: TOP
	TCCR1A=0b00000011;		//prescaler 1024, fast PWM, TOP: OCRnA, Update of OCRx at: BOTTOM, TOV Flag Set on: TOP
	OCR1A=1000;
	OCR1B=1000;
	
	TCCR0B |= 0b00000101;
	TCCR0A |= 0b00000010; 
	OCR0A=100;

	TIMSK0 |= (1<<OCIE0A);
	
	
	TCCR3B |= 0b00011101;  
	TCCR3A |= 0b00000011; 
	OCR3A=150;
	TIMSK3 |= (1<<OCIE3A);
	
	TCCR4A|=0b10101001;
	TCCR4B|=0b00001011;
	LED_R_PWM=140;
	LED_G_PWM=0;
	LED_B_PWM=255;
	
	TCCR5A=0b00000011;
	
	PORTL|=(1<<PL4);	// strobe (PWM)
	
	TCCR5B|=0b00011101;

	Init_Ports();								//Call the Init_Ports() function.
	USART_DMX_Init(3);								//USART init (250Kbps, 8 databits, 2 stopbits)
	USART_Ethernet_Init(3);										//Calculate the USART_Init parameter:
												//=(F_CPU)/(16*Baudrate)-1.. For 16Mhz crystal and 250000bps => 3
	wdt_disable();	// watchdog disabled				
	sei();	// enable global interrupts
	
	Convert_address_to_display(address_dmx);				
		
	while(1){
		if(!(PINA & (1<<BUTTON_MENU))){
			UCSR0B = (0<<RXEN0)|(0<<RXCIE0);
			TIMSK2 &= !(1<<OCIE2A);
			LED_R_PWM=0xFF;
			LED_G_PWM=0xFF;
			LED_B_PWM=0xFF;
			
			Update_display_variable(data_A, data_d, data_r);

			UCSR0B = (0<<TXEN0);
		
			_delay_ms(300); 

			while(1){
				if(!(PINA & (1<<BUTTON_UP))){
					menu_entry_nr++;
					if (menu_entry_nr==5) 
						menu_entry_nr=1;
					
					Menu_level_1_entries_display_update(menu_entry_nr);		
				}
				
				
				else if(!(PINA & (1<<BUTTON_DOWN))){
					menu_entry_nr--;
					if(menu_entry_nr==0) 
						menu_entry_nr=4;
					
					Menu_level_1_entries_display_update(menu_entry_nr);	
				}
				
				else if(!(PINA & (1<<BUTTON_MENU))){
					Convert_address_to_display(address_dmx);				
					eeprom_write_word((uint16_t *)140,address_dmx);										
					UCSR0B = (1<<RXEN0)|(1<<RXCIE0)|(1<<TXEN0);
					menu_entry_nr=1;
					TIMSK2 |= (1<<OCIE2A);
					_delay_ms(300); 
					break;
				}
				
				
				else if (!(PINA & (1<<BUTTON_SELECT))){
					switch(menu_entry_nr){
						case 1:		// DMX ADDRESS
							Menu_dmx_address();
							break;
					
						case 2:		// DISPLAY  normal/invert
							Menu_display();
							break;		
							
						case 3:		// PROGRAM
							Menu_program();
							break;
						
						case 4:		// RESTART PROCESSOR
							Menu_restart_microcontroller();
							break;
					}				
				}
				else {};
			}
			_delay_ms(90);
		}
		else{};
	
		PORTD|=(1<<LED_RED);
	}
	return 0;
}

//Functions
void Init_Ports()
{					
}


// DMX USART interrupt
ISR(USART0_RX_vect){
	dmx_state = UCSR0A;				//Read the status from the UCSRA register
	data_dmx_input = UDR0;
	dmx_state = UCSR0A;				// odczyt UCSR0A
	DmxState = gDmxState;			// sprawdzenie stanu
	data_dmx_input = UDR0;
	Update_display_variable(address_dmx_tab[0], address_dmx_tab[1], address_dmx_tab[2]);

	TCNT2=1;
	EICRA=0x00;
	EIMSK=0x00;

	PORTD&=~(1<<LED_RED);
	PORTD|=(1<<LED_AMBER);
	
	if (dmx_state & (1<<FE0)){				//If we detect a frame error=> RX_line low for longer then 8 bits (Break condition)
		UCSR0A |= (0<<FE0);			// kasowanie FE0
		gDmxState = BREAK;
		external_dmx_address_count = 0;	
		internal_dmx_address_count = 0;
		
		return;				//Reset the Channel Counter
	}

	else if (DmxState == BREAK){		// jesli dmx_state = break
		if(external_dmx_address_count==address_dmx){				
			internal_dmx_address_count ++;
				if (internal_dmx_address_count == 1)
					datapan=data_dmx_input/2.6667;
				
				else if (internal_dmx_address_count == 2)
					datatilt=data_dmx_input*2.5;
									
				else if (internal_dmx_address_count == 3){
					data_dmx_input = UDR0;
					if (data_dmx_input!=led_R_previous_value){
						LED_R_PWM=255-data_dmx_input;
						led_R_previous_value=data_dmx_input;
					}
					else {};
				}
					
				else if (internal_dmx_address_count == 4){
					data_dmx_input = UDR0;
					if (data_dmx_input!=led_G_previous_value){
						LED_G_PWM=255-data_dmx_input;
						led_G_previous_value=data_dmx_input;	
					}
					else {};
				}
					
				else if (internal_dmx_address_count == 5){	
					data_dmx_input = UDR0;
					if (data_dmx_input!=led_B_previous_value){
						LED_B_PWM=255-data_dmx_input;
						led_B_previous_value=data_dmx_input;		
					}
					else {};	
				}
					
				else if (internal_dmx_address_count == 6){
					Strobe_method(data_dmx_input);
				}

				else if (internal_dmx_address_count == 7)
					gDmxState = IDLE;
				return;
			}
			external_dmx_address_count++;
		}
	PORTD|=(1<<LED_RED);
}
	
	
ISR(TIMER1_COMPA_vect){
	if(gg==0){
		TIMSK0 &= ~(1<<OCIE0A); 
		PORTA &= ~(1 << 2); 
		PORTA &= ~(1 << 1);
		PORTA &= ~(1 << 0);

		gg++;
	}

	else{
		TIMSK0 |= (1<<OCIE0A);
		gg=0;
	} 
}


ISR(TIMER3_COMPA_vect)
{
	MotorPosition();
}


ISR(INT3_vect)
{
	PORTD&=~(1<<LED_AMBER);
	PORTD|=(1<<LED_RED);

	if(program_nr == 1)
		Program_1();
						
	if(program_nr == 2){
		Program_2();

	}
	_delay_ms(25);
	PORTD|=(1<<LED_AMBER);
}


// TIMER interrupt for switching display segments
ISR(TIMER0_COMPA_vect)
{
	Update_display(invert);
}


// Ethernet USART interrupt
ISR(USART1_RX_vect)
{
	//Ethernet();
	PORTD&=~(1<<LED_RED);
	PORTD|=(1<<LED_AMBER);
	eth_msg_nr++;
	data_eth_input = UDR1;
	
	TCNT2=1;
	EICRA=0x00;
	EIMSK=0x00;
	
	
	if(eth_msg_nr==1){
		TCNT2=0;
		datatilt=data_eth_input*2.5;
	}
	
	
	if(eth_msg_nr==2){///PORTA=0xff;
		TCNT2=0;
		datapan=data_eth_input/2.6667;
	}
	
	if(eth_msg_nr==3){///PORTA=0xff;
		TCNT2=0;
		if (data_eth_input!=led_R_previous_value){
			LED_R_PWM=255-data_eth_input;
			led_R_previous_value=data_eth_input;		
		}
	}
	
	if(eth_msg_nr==4){
		TCNT2=0;
		if (data_eth_input!=led_G_previous_value){
			LED_G_PWM=255-data_eth_input;
			led_G_previous_value=data_eth_input;
		}		
	}
	
	if(eth_msg_nr==5){
		eth_msg_nr=0;
		TCNT2=0;
		if (data_eth_input!=led_B_previous_value){
			LED_B_PWM=255-data_eth_input;
			led_B_previous_value=data_eth_input;
		}
	}
	PORTD|=(1<<LED_RED);
}

ISR(TIMER2_COMPA_vect)
{
	TCNT2=1;
	EICRA|=(1<<ISC31);
	EICRA|=(1<<ISC30);
	EIMSK|=(1<<INT3);
	Update_display_variable(data_S, data_n, data_d);
	eth_msg_nr=0;
}


