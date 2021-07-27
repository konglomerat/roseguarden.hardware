/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include <string_view>
#include <functional>
#include <optional>

#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

#include "drivers/MOD_RFID1356.h"

namespace Roseguarden
{

class Engine
{
public:
	using CardID_t = Drivers::MOD_RFID1356::CardID_t;
	enum class State_t {INIT, READY, WAIT_AUTH, OPEN, ACCESS_DENIED, SHOW_ASSIGN_INFO, ERROR};

public:
	static void init();
	static void run();

	static State_t getState();

	static std::string_view getAssignCodeString();
	static bool isDoorLocked();
	static bool isConnectedToServer();
	static bool hasConnectedServerAnError();
	static bool isConnectedToWifi();
	static bool isCardPresented();
	static std::string_view getNodeName();

private:
	static void initUI();
	static void initDoor();
	static void initWifi();
	static void initNodeClient();
	static void initRFID();
	static void initUpdateTimer();

public:
	enum class Mode_t {DOOR, REGISTRATION_TERMINAL};
	enum class Event_t {CONNECTED, DISCONNECTED, DOOR_CLOSED, CARD_PRESENTED, CARD_REMOVED, UPDATE};

private:
	static std::string getHexStringFromCardID(CardID_t);

private:
	static void runStateMachine(Event_t);
	static void proceedToState(State_t);

	static const char* getDescription(Event_t);
	static const char* getDescription(State_t);

	static State_t currentState;
	static Mode_t currentMode;

private:
	static TimerHandle_t updateTimerHandle;
	static void updateTimerCallback(TimerHandle_t);
	static const uint64_t updatePeriodInMilliseconds = 60 * 1000;

private:
	static QueueHandle_t eventQueue;
	static void thread(void*);

private:
	static bool connected;
	static bool doorOpen;
	static bool cardPresented;
	static std::optional<CardID_t> lastCard;

	static std::string nodeName;
	static std::string assignCodeString;
};

}
