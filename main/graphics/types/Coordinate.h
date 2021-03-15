/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include <inttypes.h>

namespace Graphics
{

class Coordinate_t
{
public:

	using Component_t = int32_t;

	Component_t x;
	Component_t y;

	Coordinate_t& operator+=(const Coordinate_t& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Coordinate_t& operator-=(const Coordinate_t& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Coordinate_t operator+(const Coordinate_t& other) const
	{
		Coordinate_t result;
		result.x = x + other.x;
		result.y = y + other.y;
		return result;
	}
	Coordinate_t operator-(const Coordinate_t& other) const
	{
		Coordinate_t result;
		result.x = x - other.x;
		result.y = y - other.y;
		return result;
	}
};

}

