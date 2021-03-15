/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "Button.h"

#include "driver/gpio.h"

#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

const char* BUTTON_LOG_TAG = "Button";

namespace Drivers
{

#define BUTTON_GPIO				GPIO_NUM_34
#define BUTTON_PRESSED_LEVEL 	0

void Button::init()
{
    gpio_pad_select_gpio(BUTTON_GPIO);
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
}

bool Button::isPressed()
{
	return (gpio_get_level(BUTTON_GPIO) == BUTTON_PRESSED_LEVEL);
}

}


