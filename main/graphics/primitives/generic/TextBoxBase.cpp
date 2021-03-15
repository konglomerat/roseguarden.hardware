/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */

#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

#include "TextBoxBase.h"

const char* TEXTBOXBASE_LOG_TAG = "TextBxxBase";


namespace Graphics
{

TextBoxBase_t::TextBoxBase_t(Coordinate_t org, Color_t textC, Color_t backgroundC, const FontProperties_t& fontProp)
	: Primitive_t(org),
	  textColor(textC),
	  backgroundColor(backgroundC),
	  font(getFont(fontProp))
{
};

void TextBoxBase_t::renderString(std::string_view buffer, Coordinate_t startPos)
{
	// iterate through chars
	for (auto& character : buffer)
	{
		// stop when string is terminated
		if (character == 0) return;

		// add char at current position
		startPos.x += renderChar(character, startPos);
	}
}

Coordinate_t::Component_t TextBoxBase_t::renderChar(char c, const Coordinate_t & pos)
{
	auto thisChar = font.getCharInfo(c);

	if (thisChar)
	{
		Coordinate_t destinationOrigin = pos + Coordinate_t {thisChar->offset.x, thisChar->offset.y};

		for (uint32_t x=0; x < thisChar->boundingBox.dx; x++)
		{
			for (uint32_t y=0; y < thisChar->boundingBox.dy; y++)
			{
				definePixel(
						destinationOrigin + Coordinate_t{Coordinate_t::Component_t(x), Coordinate_t::Component_t(y)},
						font.getPixelValue(thisChar->boundingBox.x + x, thisChar->boundingBox.y + y) ? textColor : backgroundColor
				);
			}
		}

		// define how much to move forward
		return thisChar->width;
	}
	else
	{
		ESP_LOGE(TEXTBOXBASE_LOG_TAG, "Character '%c' not in font", c);
		return 0;
	}
}

}
