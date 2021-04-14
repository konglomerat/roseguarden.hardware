/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

#include "Renderer.h"
#include "types/Primitive.h"

#include "esp_heap_caps.h"

const char* RENDERER_LOG_TAG = "Renderer";

namespace Graphics
{

Renderer::NativeFrame_t *Renderer::frame = nullptr;
std::vector<Primitive_t*> Renderer::shapes;
uint32_t Renderer::ticksToWait;

SemaphoreHandle_t Renderer::activeShapesMutex = xSemaphoreCreateMutex();

void Renderer::registerShape(Primitive_t * shape)
{
	xSemaphoreTake(activeShapesMutex, portMAX_DELAY);

	for (auto& s : shapes)
	{
		if (s == shape)
		{
			ESP_LOGE(RENDERER_LOG_TAG, "Shape already registered.");
			return;
		}
	}

	ESP_LOGV(RENDERER_LOG_TAG, "Registering Shape");

	shapes.push_back(shape);

	xSemaphoreGive(activeShapesMutex);
}

void Renderer::unregisterShape(Primitive_t * shape)
{
	xSemaphoreTake(activeShapesMutex, portMAX_DELAY);

	for (auto it=shapes.begin(); it<shapes.end(); )
	{
		if (*it == shape)
		{
			shapes.erase(it);

			ESP_LOGV(RENDERER_LOG_TAG, "Unregister Shape");

			return;
		}
		else
		{
			it++;
		}
	}

	ESP_LOGE(RENDERER_LOG_TAG, "Shape to unregister not found");

	xSemaphoreGive(activeShapesMutex);
}

void Renderer::start(const Init_t& settings)
{
	frame = (NativeFrame_t*) malloc(NativeFrame_t::getSizeInBytes());

	assert(frame != nullptr);

	ticksToWait = (1000 / settings.updateFrequencyInHz) / portTICK_PERIOD_MS;

	xTaskCreate(run, RENDERER_LOG_TAG, settings.stackSizeInBytes, nullptr, settings.threadPriority, NULL);
}

void Renderer::stop()
{
	ESP_LOGE(RENDERER_LOG_TAG, "Can't stop thread yet.");
}

void Renderer::run(void*)
{
	_impl_initDriver();

	while (true)
	{
		vTaskDelay(ticksToWait);
		renderAll();
		_impl_writeFrame(*frame);
	}
	return;
}

void Renderer::renderAll()
{
	assert(frame != nullptr);

	ESP_LOGV(RENDERER_LOG_TAG, "Clearing frame.");
	frame->clear();

	ESP_LOGV(RENDERER_LOG_TAG, "Rendering shapes.");
	xSemaphoreTake(activeShapesMutex, portMAX_DELAY);

	for (auto& s : shapes)
	{
		s->render();
	}

	xSemaphoreGive(activeShapesMutex);
	ESP_LOGV(RENDERER_LOG_TAG, "Finished rendering shapes.");
}

}
