/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

namespace Graphics
{

template <uint32_t numbChars, uint32_t bitmapSizeX, uint32_t bitmapSizeY>
const std::optional<Char_t> Font_t<numbChars,bitmapSizeX,bitmapSizeY>::getCharInfo(char c) const
{
	for (auto& currentCharInfo : availableChars)
	{
		const char& thisCharIndex = currentCharInfo.character;

		if (thisCharIndex == c)
		{
			return currentCharInfo;
		}
		if (thisCharIndex > c)
		{
			// assumes table is sorted
			break;
		}
	}
	return std::nullopt;
}

template <uint32_t numbChars, uint32_t bitmapSizeX, uint32_t bitmapSizeY>
bool Font_t<numbChars,bitmapSizeX,bitmapSizeY>::getPixelValue(uint32_t x, uint32_t y) const
{
	const uint32_t byteIndex = y * numbBytesPerRow + x/8;
	const uint32_t bitIndex = x % 8;
	return bits[byteIndex] & (1<<bitIndex);
}

template <uint32_t numbChars, uint32_t bitmapSizeX, uint32_t bitmapSizeY>
uint32_t Font_t<numbChars,bitmapSizeX,bitmapSizeY>::getLineHeight() const
{
	return lineHeight;
}


template <uint32_t numbChars, uint32_t bitmapSizeX, uint32_t bitmapSizeY>
constexpr uint32_t Font_t<numbChars,bitmapSizeX,bitmapSizeY>::numbBitsToNumbBytes(uint32_t numbBits)
{
	return numbBits % 8 ? numbBits/8 + 1 : numbBits/8;
}

}
