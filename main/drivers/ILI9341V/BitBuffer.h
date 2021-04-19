/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */

#pragma once

#include <array>
#include <cassert>

namespace Drivers::ILI9341V
{

template<uint32_t DIMX, uint32_t DIMY>
class BitBuffer_t
{
public:
	static const uint32_t SIZE_X = DIMX;
	static const uint32_t SIZE_Y = DIMY;

	void set(uint32_t x, uint32_t y, bool val)
	{
		if (x < SIZE_X && y < SIZE_Y)
		{
			auto absolutePixelIndex = x + SIZE_X * (SIZE_Y - 1 - y);

			data[absolutePixelIndex] = val;
		}
	}

	void clear()
	{
		data.fill(false);
	}

	const uint8_t* getByteBuffer() const
	{
		return data.data();
	}

	static std::size_t getSizeInBytes()
	{
		return sizeof(data);
	}

	std::size_t getNumberOfElements() const
	{
		return data.size();
	}

	bool getPixelByIndex(uint32_t index) const
	{
		assert(index < data.size());
		return data[index];
	}

private:
	std::array<bool,SIZE_X*SIZE_Y> data;
};

}



