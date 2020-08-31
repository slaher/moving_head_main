#ifndef INPUT_OUTPUT_DEFINES_H_
#define INPUT_OUTPUT_DEFINES_H_

#include "avr/io.h"

#define LED_GREEN PD7
#define LED_RED PD6
#define LED_AMBER PD5

#define LED_R_PWM OCR4A
#define LED_G_PWM OCR4B
#define LED_B_PWM OCR4C

#define BUTTON_UP PA5
#define BUTTON_DOWN PA6
#define BUTTON_MENU PA4
#define BUTTON_SELECT PA7

#endif /* INPUT_OUTPUT_DEFINES_H_ */