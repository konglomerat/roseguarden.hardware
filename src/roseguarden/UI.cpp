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
#include <time.h>

const char *UI_LOG_TAG = "UI";

namespace Roseguarden
{

	uint32_t UI::ticksToWait;
	bool UI::initialized = false;

	std::string UI::headerTitle = "Device: ";

	const char *connectedServer = "Server: OK";
	const char *connectedServerError = "Server: Error";
	const char *notConnectedServer = "Server:";

	const char *connectedWifi = "Wifi: OK";
	const char *notConnectedWifi = "Wifi: ";

	uint32_t UI::loadingSpinnerIndex = 0;
	std::string UI::notConectedWifiOutput = "";
	const char *loadingSpinner[3] = {".", "..", "..."};

	timeval currentTime;
	int64_t clock_millis_start;
	int64_t clock_millis_current;
	int64_t clock_millis_diff;

	const char *doorOpen = "Door: OPEN";
	const char *doorLocked = "Door: LOCKED";

	const char *cardPresented = "Card: DETECTED";
	const char *noCardPresented = "Card: MISSING";

	void UI::init(const Settings_t &settings)
	{
		if (!initialized)
		{

			// set starttime for wifi spinner
			gettimeofday(&currentTime, NULL);
			clock_millis_start = (int64_t)currentTime.tv_sec * 1000000L + (int64_t)currentTime.tv_usec;

			Graphics::Renderer::start(settings.rendererSettings);

			ticksToWait = (2000 / settings.uiUpdateFrequencyInHz) / portTICK_PERIOD_MS;

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

		while (1)
		{
			// set currenttime for wifi spinner
			gettimeofday(&currentTime, NULL);
			clock_millis_current = (int64_t)currentTime.tv_sec * 1000000L + (int64_t)currentTime.tv_usec;
			clock_millis_diff = clock_millis_current - clock_millis_start;

			std::string currentHeader;

			currentHeader.append(headerTitle).append(Engine::getNodeName());

			textView.setLineText(TextView::HEADER, currentHeader);

			if (Engine::hasConnectedServerAnError())
			{
				textView.setLineText(TextView::BOTTOM_5, connectedServerError);
			}
			else if (Engine::isConnectedToServer())
			{
				textView.setLineText(TextView::BOTTOM_5, connectedServer);
			}
			else
			{
				textView.setLineText(TextView::BOTTOM_5, notConnectedServer);
			}

			if (Engine::isConnectedToWifi())
			{
				textView.setLineText(TextView::BOTTOM_4, connectedWifi);
			}
			else
			{

				// wait 500ms and iterate thought loadingSpinnerArray
				if (clock_millis_diff >= 500000)
				{
					if (loadingSpinnerIndex <= 2)
					{
						notConectedWifiOutput = notConnectedWifi;
						notConectedWifiOutput += loadingSpinner[loadingSpinnerIndex];
						loadingSpinnerIndex++;
					}
					else
					{
						loadingSpinnerIndex = 0;
						notConectedWifiOutput = notConnectedWifi;
					}

					textView.setLineText(TextView::BOTTOM_4, notConectedWifiOutput);

					// reset currenttime for spinner
					gettimeofday(&currentTime, NULL);
					clock_millis_start = (int64_t)currentTime.tv_sec * 1000000L + (int64_t)currentTime.tv_usec;
				}
			}

			if (Engine::isDoorLocked())
			{
				textView.setLineText(TextView::BOTTOM_2, doorLocked);
			}
			else
			{
				textView.setLineText(TextView::BOTTOM_2, doorOpen);
			}

			if (Engine::isCardPresented())
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

	std::string_view UI::getStateString(Engine::State_t &state)
	{
		switch (state)
		{
		case Engine::State_t::INIT:
			return "INITIALISATION";
		case Engine::State_t::READY:
			return "PRESENT CARD";
		case Engine::State_t::WAIT_AUTH:
			return "NOT AUTHORIZED";
		case Engine::State_t::OPEN:
			return "ACCESS GRANTED";
		case Engine::State_t::ACCESS_DENIED:
			return "ACCESS DENIED";
		case Engine::State_t::SHOW_ASSIGN_INFO:
			return "GET AUTH CODE";
		case Engine::State_t::ERROR:
			return "ERROR...RESTARTING...";
		default:
			return "INVALID STATE";
		}
	}

}
