/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "Frame.h"

#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

const char* FRAME_LOG_TAG = "Frame";

namespace Graphics
{

template <uint32_t SIZEX, uint32_t SIZEY, typename VALUE>
void Frame_t<SIZEX,SIZEY,VALUE>::setPixel(uint32_t x, uint32_t y, VALUE val)
{
	if (x < SIZEX && y < SIZEY)
	{
		this->operator[](y)[x] = val;
	}
	else
	{
		ESP_LOGE(FRAME_LOG_TAG, "Trying to draw outside (at %u,%u)",x,y);
	}
}

template <uint32_t SIZEX, uint32_t SIZEY, typename VALUE>
void Frame_t<SIZEX,SIZEY,VALUE>::clear()
{
	this->fill(0);
}

template <uint32_t SIZEX, uint32_t SIZEY, typename VALUE>
void Frame_t<SIZEX,SIZEY,VALUE>::fill(const VALUE& value)
{
	for (auto& row : data())
	{
		row.fill(value);
	}
}


}


