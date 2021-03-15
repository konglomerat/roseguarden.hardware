/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "graphics/primitives/TextBox.h"
#include "graphics/Renderer.h"

#include "Engine.h"

#include <string_view>

namespace Roseguarden
{

class UI
{
public:
	struct Settings_t {
		Graphics::Renderer::Init_t rendererSettings;
		uint32_t uiStackSizeInBytes;
		uint32_t uiThreadPriority;
		uint32_t uiUpdateFrequencyInHz;
	};
public:
	static void init(const Settings_t&);

private:
	static void update(void*);

private:
	static uint32_t ticksToWait;
	static bool initialized;

private:
	static std::string_view getStateString(Engine::State_t&);
};

}

