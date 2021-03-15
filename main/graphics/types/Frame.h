/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include <inttypes.h>
#include <array>

namespace Graphics
{

template <uint32_t SIZEX, uint32_t SIZEY, typename VALUE>
class Frame_t : public std::array<std::array<VALUE,SIZEX>,SIZEY>
{
public:
	void setPixel(uint32_t x, uint32_t y, VALUE val);
	void clear();
	void fill(const VALUE&);

private:
	using std::array<std::array<VALUE,SIZEX>,SIZEY>::data;
};

}
