/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */

#include "Wifi.h"

//#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"
#include "esp_wifi.h"

#include <cstring>
#include <string>

namespace Drivers
{

static const char *TAG = "Wifi";

bool Wifi::isInitialized = false;
Wifi::State_t Wifi::state = DISCONNECTED;

esp_event_handler_instance_t Wifi::wifiEventHandler;
esp_event_handler_instance_t Wifi::ipEventHandler;

void Wifi::init()
{
	if (!isInitialized)
	{
		/*
		 * we have to use the default loop as the netif driver registers its event handlers there.
		 * so far there is now way to check wether the default event loop has already been created.
		 * this call will fail if another process already created the default loop.
		 */
		ESP_ERROR_CHECK(esp_event_loop_create_default());


		//setup wifi peripheral
		wifi_init_config_t wifiInitConig;
		wifiInitConig = WIFI_INIT_CONFIG_DEFAULT();

		ESP_ERROR_CHECK(esp_wifi_init(&wifiInitConig));
		ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

		//setup tcp/ip stack
		ESP_ERROR_CHECK(esp_netif_init());
		esp_netif_create_default_wifi_sta();

		ESP_LOGV(TAG, "Register Event Handlers.");
		ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &eventHandler, NULL, &wifiEventHandler));
		ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &eventHandler, NULL, &ipEventHandler));

		isInitialized = true;
	}
	else
	{
		ESP_LOGE(TAG, "Already initialized.");
	}
}

void Wifi::connectToAP(const std::string_view ssid,const std::string_view password)
{
	if(isInitialized)
	{
		ESP_LOGV(TAG, "Set config.");
		wifi_config_t wifiConfig;
		std::memset(&wifiConfig, 0, sizeof(wifiConfig));

		sprintf(reinterpret_cast<char*>(wifiConfig.sta.ssid), ssid.data());
		sprintf(reinterpret_cast<char*>(wifiConfig.sta.password), password.data());
		if(password.empty())
		{
			ESP_LOGV(TAG, "No password given, initializing with open authentification mode.");
			wifiConfig.sta.threshold.authmode = WIFI_AUTH_OPEN;
		}
		else
		{
			ESP_LOGV(TAG, "Password given, initializing with WPA2 authentification mode.");
			wifiConfig.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;
		}
		wifiConfig.sta.pmf_cfg.capable = true;
		wifiConfig.sta.pmf_cfg.required = false;
		ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifiConfig));

		ESP_LOGV(TAG, "Start.");
		ESP_ERROR_CHECK(esp_wifi_start());
	}
	else
	{
		ESP_LOGE(TAG, "Can't connect to Wifi, driver not initialized.");
	}
}

Wifi::State_t Wifi::getState()
{
	return state;
}

void Wifi::eventHandler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
	if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
	{
		esp_wifi_connect();
	}
	else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
	{
		state = DISCONNECTED;
		
		vTaskDelay(1000 / portTICK_PERIOD_MS);

		esp_wifi_connect();
		ESP_LOGV(TAG, "Retry to connect to the AP.");

	}
	else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_CONNECTED)
	{
		state = ASSOCIATED;
		ESP_LOGV(TAG,"Connected to the AP.");
	}
	else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
	{
		state = CONNECTED;
		ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
		ESP_LOGV(TAG, "Got ip:" IPSTR, IP2STR(&event->ip_info.ip));
	}
}


}
