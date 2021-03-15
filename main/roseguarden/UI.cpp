/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

#include "UI.h"
#include "TextView.h"

const char* UI_LOG_TAG = "UI";

namespace Roseguarden
{

uint32_t UI::ticksToWait;
bool UI::initialized = false;

const char* connected = "CONNECTED TO AP";
const char* notConnected = "NOT CONNECTED TO AP";

const char* doorOpen = "DOOR OPEN";
const char* doorLocked = "DOOR LOCKED";

const char* cardPresented = "CARD DETECTED";
const char* noCardPresented = "NO CARD DETECTED";

void UI::init(const Settings_t& settings)
{
	if (!initialized)
	{
		Graphics::Renderer::start(settings.rendererSettings);

		ticksToWait = (1000 / settings.uiUpdateFrequencyInHz) / portTICK_PERIOD_MS;

		xTaskCreate(update, UI_LOG_TAG, settings.uiStackSizeInBytes, nullptr, settings.uiThreadPriority, NULL);

		initialized = true;
	}
	else
	{
		ESP_LOGE(UI_LOG_TAG, "Already initialized.");
	}

}

void UI::update(void *)
{
	TextView textView;

	while(1)
	{
		textView.setLineText(TextView::HEADER, Engine::getNodeName());

		if(Engine::isConnectedToWifiAP())
		{
			textView.setLineText(TextView::BOTTOM_3, connected);
		}
		else
		{
			textView.setLineText(TextView::BOTTOM_3, notConnected);
		}

		if(Engine::isDoorLocked())
		{
			textView.setLineText(TextView::BOTTOM_2, doorLocked);
		}
		else
		{
			textView.setLineText(TextView::BOTTOM_2, doorOpen);
		}

		if(Engine::isCardPresented())
		{
			textView.setLineText(TextView::BOTTOM_1, cardPresented);
		}
		else
		{
			textView.setLineText(TextView::BOTTOM_1, noCardPresented);
		}

		auto state = Engine::getState();

		textView.setLineText(TextView::CENTER_1, getStateString(state));

		if (state == Engine::State_t::SHOW_ASSIGN_INFO)
		{
			textView.setLineText(TextView::CENTER_2, Engine::getAssignCodeString());
		}
		else
		{
			textView.setLineText(TextView::CENTER_2, "");
		}

		vTaskDelay(ticksToWait);
	}
}

std::string_view UI::getStateString(Engine::State_t& state)
{
	switch (state)
	{
	case Engine::State_t::INIT:
		return "INITIALISATION";
	case Engine::State_t::READY:
		return "PRESENT CARD TO ENTER";
	case Engine::State_t::WAIT_AUTH:
		return "NODE NOT AUTHORIZED";
	case Engine::State_t::OPEN:
		return "ACCESS GRANTED";
	case Engine::State_t::ACCESS_DENIED:
		return "ACCESS DENIED";
	case Engine::State_t::SHOW_ASSIGN_INFO:
		return "GET CARD AUTH CODE";
	case Engine::State_t::ERROR:
		return "ERROR...RESTARTING...";
	default:
		return "INVALID STATE";
	}
}

}


