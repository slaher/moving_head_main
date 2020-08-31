#include "avr/io.h"
#include "stdio.h"
#include "util/delay.h"
#include "avr/interrupt.h"
#include "usart.h"
#include "avr/wdt.h"
#include "avr/eeprom.h"
#include "stepper_motor_position.h"
#include "position_table.h"
#include "stdbool.h"
#include "update_display_variable.h"
#include "menu_level_1_entries_display_update.h"
#include "convert_address_to_display.h"
#include "update_display.h"
#include "invert_entry_display_update.h"
#include "program_1.h"
#include "program_2.h"
#include "input_output_defines.h"
#include "menu_display.h"
#include "menu_program.h"
#include "menu_restart_microcontroller.h"
#include "menu_dmx_address.h"
#include "led_rgb_methods.h"


void Init_Ports(void);