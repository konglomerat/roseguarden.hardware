/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "stdint.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

namespace Roseguarden
{

class Door
{
public:
	struct Settings_t {
		uint32_t closeTimeoutInSeconds;
	};

public:
	static void init(const Settings_t&);
	static void open();
	static void close();
	static bool isOpen();

private:
	static void run(void*);

private:
	static bool initialized;
	static uint32_t closeTimeout;
	static EventGroupHandle_t eventGroup;
};


}

