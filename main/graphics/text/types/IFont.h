/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include <inttypes.h>
#include <optional>

namespace Graphics
{

struct Char_t
{
	char character;
	uint16_t width;

	struct
	{
		uint16_t x;
		uint16_t y;
	}
	offset;

	struct
	{
		uint16_t x;
		uint16_t y;
		uint16_t dx;
		uint16_t dy;
	}
	boundingBox;
};

class IFont
{
public:
	virtual ~IFont() = default;
public:
	virtual const std::optional<Char_t> getCharInfo(char c) const = 0;
	virtual bool getPixelValue(uint32_t x, uint32_t y) const = 0;
	virtual uint32_t getLineHeight() const = 0;
};

}
