/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

#include "TextView.h"

#include <stdint.h>

namespace Roseguarden
{

static const char *TAG = "TextView";

const uint32_t xCoordinate = 10;
const uint32_t yCoordinateHeader = 10;
const uint32_t yCoordinateCenterLine1 = 120;
const uint32_t yCoordinateCenterLine2 = 145;
const uint32_t yCoordinateBottomLine1 = 260;
const uint32_t yCoordinateBottomLine2 = 280;
const uint32_t yCoordinateBottomLine3 = 300;

TextView::TextView() : header(Graphics::Coordinate_t{xCoordinate,yCoordinateHeader}),
					centerLine1(Graphics::Coordinate_t{xCoordinate,yCoordinateCenterLine1}),
					centerLine2(Graphics::Coordinate_t{xCoordinate,yCoordinateCenterLine2}),
					bottomLine1(Graphics::Coordinate_t{xCoordinate,yCoordinateBottomLine1}, Graphics::DefaultForegroundColor, Graphics::DefaultBackGroundColor, Graphics::FontProperties_t{Graphics::FontProperties_t::Size_t::SMALL}),
					bottomLine2(Graphics::Coordinate_t{xCoordinate,yCoordinateBottomLine2}, Graphics::DefaultForegroundColor, Graphics::DefaultBackGroundColor, Graphics::FontProperties_t{Graphics::FontProperties_t::Size_t::SMALL}),
					bottomLine3(Graphics::Coordinate_t{xCoordinate,yCoordinateBottomLine3}, Graphics::DefaultForegroundColor, Graphics::DefaultBackGroundColor, Graphics::FontProperties_t{Graphics::FontProperties_t::Size_t::SMALL})
{
}

void TextView::setLineText(const TextLines_t& line, std::string_view text)
{
	switch(line)
	{
	case HEADER:
		header.setText(text);
		break;
	case CENTER_1:
		centerLine1.setText(text);
		break;
	case CENTER_2:
		centerLine2.setText(text);
		break;
	case BOTTOM_1:
		bottomLine1.setText(text);
		break;
	case BOTTOM_2:
		bottomLine2.setText(text);
		break;
	case BOTTOM_3:
		bottomLine3.setText(text);
		break;
	default:
		ESP_LOGE(TAG, "Unknown line.");
	}
}

}


