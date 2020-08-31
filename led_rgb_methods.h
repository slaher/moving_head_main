#include "avr/io.h"
#include "avr/interrupt.h"

extern uint16_t strobeB;
extern uint16_t strobeA;

void Strobe_method(uint8_t data_dmx_input);