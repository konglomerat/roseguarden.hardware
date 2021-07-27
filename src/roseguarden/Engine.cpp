/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */

#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

#include "Engine.h"
#include "UI.h"
#include "Door.h"

#include "drivers/Wifi.h"
#include "drivers/MOD_RFID1356.h"
#include "drivers/Button.h"
#include "network/RoseguardenNodeClient.h"
#include "network/JSONHttpClient.h"
using namespace Network;

#include <string>
#include <cstdio>

static const char *TAG = "Engine";

namespace Roseguarden
{

	const char *DummyPin = "123456";

	std::string Engine::nodeName;
	std::string Engine::assignCodeString = "";
	Engine::State_t Engine::currentState;
	bool Engine::connected;
	bool Engine::doorOpen;
	bool Engine::cardPresented;
	std::optional<Engine::CardID_t> Engine::lastCard;
	Engine::Mode_t Engine::currentMode;
	TimerHandle_t Engine::updateTimerHandle;
	QueueHandle_t Engine::eventQueue;

	std::string_view Engine::getAssignCodeString()
	{
		return assignCodeString;
	}

	bool Engine::isDoorLocked()
	{
		return (!Door::isOpen());
	}

	bool Engine::hasConnectedServerAnError()
	{
		return Network::JSONHttpClient::getState() == Network::JSONHttpClient::State_t::ERROR || !Engine::isConnectedToWifi();
	}

	bool Engine::isConnectedToServer()
	{
		return Network::JSONHttpClient::getState() == Network::JSONHttpClient::State_t::CONNECTED;
	}

	bool Engine::isConnectedToWifi()
	{
		return Drivers::Wifi::getState() == Drivers::Wifi::State_t::CONNECTED;
	}

	bool Engine::isCardPresented()
	{
		return cardPresented;
	}

	std::string_view Engine::getNodeName()
	{
		return nodeName;
	}

	void Engine::initUI()
	{
		Graphics::Renderer::Init_t rendererSettings;
		rendererSettings.stackSizeInBytes = 3072;
		rendererSettings.threadPriority = 12;
		rendererSettings.updateFrequencyInHz = 100;

		UI::Settings_t uiSettings;
		uiSettings.rendererSettings = rendererSettings;
		uiSettings.uiThreadPriority = 12;
		uiSettings.uiStackSizeInBytes = 2048;
		uiSettings.uiUpdateFrequencyInHz = 100;

		UI::init(uiSettings);
	}

	void Engine::initDoor()
	{
		Door::Settings_t doorSettings;
		doorSettings.closeTimeoutInSeconds = 3;
		Door::init(doorSettings);

		Door::close();
	}

	void Engine::initWifi()
	{
		Drivers::Wifi::init();
		const char *ssid = CONFIG_ROSEGUARDEN_WIFI_SSID;
		const char *password = CONFIG_ROSEGUARDEN_WIFI_PASSWORD;
		Drivers::Wifi::connectToAP(ssid, password);
	}

	void Engine::initNodeClient()
	{
		RoseguardenNodeClient::Settings_t settings;
		settings.nodeName = nodeName;
		settings.fingerprint = CONFIG_ROSEGUARDEN_NODE_FINGERPRINT;
		settings.authentification = CONFIG_ROSEGUARDEN_NODE_AUTHENTIFICATION;
		settings.version = "1.0.0";
		settings.serverURL = CONFIG_ROSEGUARDEN_SERVER_URL;

		RoseguardenNodeClient::init(settings);
	}

	void Engine::initRFID()
	{
		Drivers::MOD_RFID1356::init();
	}

	void Engine::initUpdateTimer()
	{
		updateTimerHandle = xTimerCreate("UpdateTimer", pdMS_TO_TICKS(updatePeriodInMilliseconds), pdTRUE, (void *)0, &updateTimerCallback);

		if (updateTimerHandle != NULL)
		{
			auto result = xTimerStart(updateTimerHandle, 0);
			if (result != pdPASS)
			{
				ESP_LOGE(TAG, "Couldn't start update timer.");
			}
		}
		else
		{
			ESP_LOGE(TAG, "Couldn't create update timer.");
		}
	}

	const char *Engine::getDescription(Event_t event)
	{
		switch (event)
		{
		case Event_t::CONNECTED:
			return "CONNECTED";
		case Event_t::DISCONNECTED:
			return "DISCONNECTED";
		case Event_t::DOOR_CLOSED:
			return "DOOR_CLOSED";
		case Event_t::CARD_PRESENTED:
			return "CARD_PRESENTED";
		case Event_t::CARD_REMOVED:
			return "CARD_REMOVED";
		case Event_t::UPDATE:
			return "UPDATE";
		default:
			return "INVALID EVENT";
		};
	}

	const char *Engine::getDescription(State_t state)
	{
		switch (state)
		{
		case State_t::INIT:
			return "INIT";
		case State_t::READY:
			return "READY";
		case State_t::WAIT_AUTH:
			return "WAIT_AUTH";
		case State_t::OPEN:
			return "OPEN";
		case State_t::ACCESS_DENIED:
			return "ACCESS_DENIED";
		case State_t::SHOW_ASSIGN_INFO:
			return "SHOW_ASSIGN_INFO";
		default:
			return "INVALID STATE";
		};
	}

	void Engine::proceedToState(State_t newState)
	{
		if (newState != currentState)
		{
			ESP_LOGD(TAG, "State %s -> %s", getDescription(currentState), getDescription(newState));
			currentState = newState;
		}
	}

	void Engine::init()
	{
		nodeName = CONFIG_ROSEGUARDEN_NODE_NAME;

		Drivers::Button::init();
		if (CONFIG_ROSEGUARDEN_SET_DEVICE_AS_REGISTRATION_TERMINAL || Drivers::Button::isPressed())
		{
			ESP_LOGI(TAG, "Running as registration terminal");
			currentMode = Mode_t::REGISTRATION_TERMINAL;
		}
		else
		{
			ESP_LOGI(TAG, "Running as door node");
			currentMode = Mode_t::DOOR;
		}

		if (nodeName.empty())
		{
			ESP_LOGE(TAG, "No node name set. This will lead to errors in the communication with the server.");
		}

		initUI();
		initDoor();
		initWifi();
		initNodeClient();
		initRFID();
		initUpdateTimer();

		const uint32_t numberOfItemsInQueue = 4;
		eventQueue = xQueueCreate(numberOfItemsInQueue, sizeof(Event_t));
		assert(eventQueue != NULL);

		const uint32_t stackSizeInBytes = 8200;
		const uint32_t threadPriority = 12;
		xTaskCreate(thread, TAG, stackSizeInBytes, nullptr, threadPriority, NULL);
	}

	Engine::State_t Engine::getState()
	{
		return currentState;
	}

	void Engine::run()
	{
		while (true)
		{

			//if (auto newConnected = isConnectedToWifiAP(); newConnected != connected)
			if (auto newConnected = isConnectedToWifi(); newConnected != connected)
			{
				connected = newConnected;
				if (newConnected)
				{
					Event_t event = Event_t::CONNECTED;
					xQueueSendToBack(eventQueue, &event, portMAX_DELAY);
				}
				else
				{
					Event_t event = Event_t::DISCONNECTED;
					xQueueSendToBack(eventQueue, &event, portMAX_DELAY);
				}
			}

			if (auto newOpen = !isDoorLocked(); newOpen != doorOpen)
			{
				doorOpen = newOpen;
				if (!newOpen)
				{
					Event_t event = Event_t::DOOR_CLOSED;
					xQueueSendToBack(eventQueue, &event, portMAX_DELAY);
				}
			}

			if (auto newCard = Drivers::MOD_RFID1356::getCardID(); newCard != lastCard)
			{
				lastCard = newCard;
				if (newCard)
				{
					cardPresented = true;
					Event_t event = Event_t::CARD_PRESENTED;
					xQueueSendToBack(eventQueue, &event, portMAX_DELAY);
				}
				else
				{
					cardPresented = false;
					Event_t event = Event_t::CARD_REMOVED;
					xQueueSendToBack(eventQueue, &event, portMAX_DELAY);
				}
			}

			vTaskDelay(200 / portTICK_PERIOD_MS);
		}
	}

	std::string Engine::getHexStringFromCardID(CardID_t cardID)
	{
		std::string hexString;
		const uint32_t numberOfCharactersInCardIDString = 8;
		hexString.resize(numberOfCharactersInCardIDString);
		std::sprintf(hexString.data(), "%08X", cardID);

		return hexString;
	}

	void Engine::updateTimerCallback(TimerHandle_t timerHandle)
	{
		ESP_LOGD(TAG, "Update due.");
		Event_t event = Event_t::UPDATE;
		xQueueSendToBack(eventQueue, &event, portMAX_DELAY);
	}

	void Engine::runStateMachine(Event_t event)
	{
		ESP_LOGD(TAG, "Handle %s in %s", getDescription(event), getDescription(currentState));

		switch (currentState)
		{
		case State_t::INIT:
		{
			if (event == Event_t::CONNECTED)
			{
				ESP_LOGD(TAG, "Send startupRequest to server");

				auto response = RoseguardenNodeClient::sendStartupRequest();

				if (std::holds_alternative<RoseguardenNodeClient::Action_t>(response))
				{
					auto action = std::get<RoseguardenNodeClient::Action_t>(response);
					if (std::holds_alternative<RoseguardenNodeClient::SendIdentification>(action))
					{
						ESP_LOGD(TAG, "Server requests node identification");
						ESP_LOGD(TAG, "Send node identification to server");

						auto response = RoseguardenNodeClient::sendNodeIdentification();

						if (std::holds_alternative<RoseguardenNodeClient::Error_t>(response))
						{
							auto error = std::get<RoseguardenNodeClient::Error_t>(response);
							if (error == RoseguardenNodeClient::Error_t::NO_RESPONSE)
							{
								ESP_LOGD(TAG, "Node identification sent");

								proceedToState(State_t::WAIT_AUTH);
								break;
							}
							else
							{
								ESP_LOGE(TAG, "Server responded with an unexpected error type.");
							}
						}
						else
						{
							ESP_LOGE(TAG, "Server didn't respond with error type.");
						}

						ESP_LOGE(TAG, "Sending node identification failed");
					}
					else if (std::holds_alternative<RoseguardenNodeClient::EmptyAction>(action))
					{
						ESP_LOGD(TAG, "Startup registered");

						if (currentMode == Mode_t::DOOR)
						{
							proceedToState(State_t::READY);
						}
						else
						{
							proceedToState(State_t::SHOW_ASSIGN_INFO);
						}
						break;
					}
					else
					{
						ESP_LOGE(TAG, "Server responded with an unexpected action type.");
					}
				}
				else
				{
					ESP_LOGE(TAG, "Server didn't respond with an action type.");
				}

				ESP_LOGE(TAG, "Sending node startUp failed");

				proceedToState(State_t::ERROR);
			}
			break;
		}

		case State_t::READY:
		{
			if (event == Event_t::CARD_PRESENTED)
			{
				auto cardID = Drivers::MOD_RFID1356::getCardID();
				if (cardID)
				{
					ESP_LOGD(TAG, "Request access for card with ID: %08X", *cardID);

					auto hexString = getHexStringFromCardID(*cardID);

					auto response = RoseguardenNodeClient::sendRequestUserAccess(hexString, DummyPin);

					if (std::holds_alternative<RoseguardenNodeClient::Action_t>(response))
					{
						auto action = std::get<RoseguardenNodeClient::Action_t>(response);
						if (std::holds_alternative<RoseguardenNodeClient::GrandAccess>(action))
						{
							ESP_LOGD(TAG, "Server grands access");

							proceedToState(State_t::OPEN);

							ESP_LOGD(TAG, "Opening door");

							Door::open();
							break;
						}
						else if (std::holds_alternative<RoseguardenNodeClient::DenyAccess>(action))
						{
							ESP_LOGD(TAG, "Server denies access");

							proceedToState(State_t::ACCESS_DENIED);
							break;
						}
						else
						{
							ESP_LOGE(TAG, "Server responded with an unexpected action.");
						}
					}
					else
					{
						ESP_LOGE(TAG, "Server didn't respond with a known action.");
					}
				}
			}
			else if (event == Event_t::UPDATE)
			{
				ESP_LOGD(TAG, "Send nodeUpdate to server");

				auto response = RoseguardenNodeClient::sendUpdate();

				if (std::holds_alternative<RoseguardenNodeClient::Action_t>(response))
				{
					auto action = std::get<RoseguardenNodeClient::Action_t>(response);

					if (std::holds_alternative<RoseguardenNodeClient::EmptyAction>(action))
					{
						ESP_LOGD(TAG, "nodeUpdate ok");
						break;
					}
					else
					{
						ESP_LOGE(TAG, "Server responded with an unexpected action.");
					}
				}
				else
				{
					ESP_LOGE(TAG, "Server didn't respond with a known action.");
				}

				proceedToState(State_t::ERROR);
			}
			break;
		}

		case State_t::SHOW_ASSIGN_INFO:
		{
			if (event == Event_t::CARD_PRESENTED)
			{
				auto cardID = Drivers::MOD_RFID1356::getCardID();
				if (cardID)
				{
					ESP_LOGD(TAG, "Request auth. token for card with ID: %08X", *cardID);
					auto hexString = getHexStringFromCardID(*cardID);

					auto response = RoseguardenNodeClient::sendRequestAssignCode(hexString);

					if (std::holds_alternative<RoseguardenNodeClient::Action_t>(response))
					{
						auto action = std::get<RoseguardenNodeClient::Action_t>(response);
						if (std::holds_alternative<RoseguardenNodeClient::UpdateAssignInfo>(action))
						{
							auto assignInfo = std::get<RoseguardenNodeClient::UpdateAssignInfo>(action);

							if (assignInfo.valid)
							{
								assignCodeString = assignInfo.code;

								ESP_LOGD(TAG, "Updated assign info: %s", assignCodeString.c_str());
							}
							else
							{
								ESP_LOGW(TAG, "Ignoring invalid assign code");

								assignCodeString = "code not valid";
							}

							break;
						}
						else
						{
							ESP_LOGE(TAG, "Server responded with an unexpected action.");
						}
					}
					else
					{
						ESP_LOGE(TAG, "Server didn't respond with a known action.");
					}
				}
			}
			else if (event == Event_t::CARD_REMOVED)
			{
				assignCodeString = "";
			}
			break;
		}

		case State_t::WAIT_AUTH:
		{
			// do nothing
			// UI should show information
			break;
		}

		case State_t::OPEN:
		{
			if (event == Event_t::DOOR_CLOSED)
			{
				proceedToState(State_t::READY);
			}
			break;
		}

		case State_t::ACCESS_DENIED:
		{
			if (event == Event_t::CARD_REMOVED)
			{
				proceedToState(State_t::READY);
			}
			break;
		}

		case State_t::ERROR:
		{
			const uint32_t restartTimeOutInMilliseconds = 5000;
			vTaskDelay(pdMS_TO_TICKS(restartTimeOutInMilliseconds));
			abort();
			break;
		}
		}
	}

	void Engine::thread(void *)
	{
		while (1)
		{
			Event_t event;
			xQueueReceive(eventQueue, &event, portMAX_DELAY);
			runStateMachine(event);
		};
	}

}
