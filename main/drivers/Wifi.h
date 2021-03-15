/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include <stdint.h>
#include <string_view>

#include "esp_event_base.h"

namespace Drivers
{

class Wifi
{
public:
	enum State_t
	{
		DISCONNECTED,
		ASSOCIATED,
		CONNECTED
	};
public:
	static void init();
	static State_t getState();
	static void connectToAP(const std::string_view ssid, const std::string_view password);

private:
	static bool isInitialized;
	static State_t state;
	static uint32_t numberOfConnectionAttempts;

private:
	static esp_event_handler_instance_t wifiEventHandler;
	static esp_event_handler_instance_t ipEventHandler;
	static void eventHandler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);
};


}

