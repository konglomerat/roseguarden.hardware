/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include <drivers/Relay.h>
#include "driver/gpio.h"

#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

namespace Drivers
{

static const char *TAG = "Relay";

#define RELAY_GPIO			GPIO_NUM_32
#define RELAY_ON_LEVEL		1
#define RELAY_OFF_LEVEL		0


void Relay::init()
{
    gpio_pad_select_gpio(RELAY_GPIO);

    // direction has to be set to input and output in order to read the logic level of the pin
    gpio_set_direction(RELAY_GPIO, GPIO_MODE_INPUT_OUTPUT);

    off();
}

void Relay::on()
{
	ESP_LOGD(TAG, "Switching on.");
	gpio_set_level(RELAY_GPIO, RELAY_ON_LEVEL);
}

void Relay::off()
{
	ESP_LOGD(TAG, "Switching off.");
	gpio_set_level(RELAY_GPIO, RELAY_OFF_LEVEL);
}

bool Relay::isOn()
{
	return (gpio_get_level(RELAY_GPIO) == RELAY_ON_LEVEL);
}

}
