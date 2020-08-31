#include "update_rgb_led_values.h"

void Update_rgb_led_values(uint8_t data_dmx_inputi, int led, uint8_t led_previous_value)
{
	if (data_dmx_inputi!=led_previous_value){
		led = 255-data_dmx_inputi;
		led_previous_value = data_dmx_inputi;
	}
}