#include "avr/io.h"
#include "input_output_defines.h"
#include "util/delay.h"
#include "stdbool.h"

#include "invert_entry_display_update.h"
#include "update_display_variable.h"

extern bool invert;
void Menu_display(void);