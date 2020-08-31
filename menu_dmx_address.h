#include "convert_address_to_display.h"
#include "avr/io.h"
#include "input_output_defines.h"
#include "util/delay.h"
#include "chars_define.h"
#include "update_display_variable.h"
#include "avr/eeprom.h"

extern int address_dmx;

void Menu_dmx_address(void);