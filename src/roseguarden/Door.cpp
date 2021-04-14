/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */

#include <drivers/Relay.h>
#include "Door.h"

#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

const char *DOOR_LOG_TAG = "Door";

namespace Roseguarden
{

	uint32_t Door::closeTimeout;
	EventGroupHandle_t Door::eventGroup;
	bool Door::initialized = false;

	const uint32_t openDoorBit = BIT0;

	void Door::init(const Settings_t &settings)
	{
		closeTimeout = settings.closeTimeoutInSeconds * 1000 / portTICK_PERIOD_MS;
		eventGroup = xEventGroupCreate();

		Drivers::Relay::init();

		const uint32_t stackSizeInBytes = 2048;
		const uint32_t threadPriority = 12;

		xTaskCreate(run, DOOR_LOG_TAG, stackSizeInBytes, nullptr, threadPriority, NULL);

		initialized = true;
	}

	void Door::open()
	{
		if (initialized)
		{
			xEventGroupSetBits(eventGroup, openDoorBit);
		}
		else
		{
			ESP_LOGE(DOOR_LOG_TAG, "Can't open door, not initialized.");
		}
	}

	void Door::close()
	{
		if (initialized)
		{
			Drivers::Relay::off();
		}
		else
		{
			ESP_LOGE(DOOR_LOG_TAG, "Can't close door, not initialized.");
		}
	}

	bool Door::isOpen()
	{
		return Drivers::Relay::isOn();
	}

	void Door::run(void *)
	{
		while (1)
		{
			xEventGroupWaitBits(eventGroup, openDoorBit, pdTRUE, pdTRUE, portMAX_DELAY);

			ESP_LOGD(DOOR_LOG_TAG, "Opening Door.");
			Drivers::Relay::on();
			ESP_LOGD(DOOR_LOG_TAG, "Open door timeout.");
			vTaskDelay(closeTimeout);
			ESP_LOGD(DOOR_LOG_TAG, "Closing Door.");
			Drivers::Relay::off();
		}
	}

}
