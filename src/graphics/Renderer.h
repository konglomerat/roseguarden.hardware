/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "types/Frame.h"

#include <vector>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "../drivers/Display.h"

namespace Graphics
{

// forward declare primitive
class Primitive_t;

class Renderer
{
public:
	struct Init_t
	{
		uint32_t updateFrequencyInHz;
		UBaseType_t threadPriority;
		uint32_t stackSizeInBytes;
	};
public:
	static void start(const Init_t&);
	static void stop();

private:
	static void run(void*);
	static uint32_t ticksToWait;

private:
	static void renderAll();

private:
	friend Primitive_t;
	static void registerShape(Primitive_t * shape);
	static void unregisterShape(Primitive_t * shape);
	static std::vector<Primitive_t*> shapes;

private:
	static SemaphoreHandle_t activeShapesMutex;

private:
	using NativeFrame_t = Drivers::Display::FrameBuffer_t;
	static NativeFrame_t *frame;

private:
	static void _impl_initDriver();
	static void _impl_writeFrame(const NativeFrame_t&);
};
}

