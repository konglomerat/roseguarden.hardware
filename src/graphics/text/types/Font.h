/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "IFont.h"

#include <array>

namespace Graphics
{



template <uint32_t numbChars, uint32_t bitmapSizeX, uint32_t bitmapSizeY>
class Font_t : public IFont
{
private:
	static constexpr uint32_t numbBitsToNumbBytes(uint32_t numbBits);
	static constexpr uint32_t numbBytesPerRow = numbBitsToNumbBytes(bitmapSizeX);
	static constexpr uint32_t numbBytesTotal = bitmapSizeY*numbBytesPerRow;

	using CharDef_t = std::array<Char_t,numbChars>;
	using Data_t = std::array<uint8_t,numbBytesTotal>;

public:
	constexpr Font_t(const CharDef_t& c, const Data_t& d, uint32_t h) : availableChars(c), bits(d), lineHeight(h)
	{
	}
	const CharDef_t availableChars;
	const Data_t bits;
	const uint32_t lineHeight;

public:
	const std::optional<Char_t> getCharInfo(char c) const override;
	bool getPixelValue(uint32_t x, uint32_t y) const override;
	uint32_t getLineHeight() const override;
};

}

#include "Font.hpp"



