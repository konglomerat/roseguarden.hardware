/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "Coordinate.h"

namespace Graphics
{

class Moveable_t
{
public:
	Moveable_t(Coordinate_t origin);
	virtual ~Moveable_t() = default;

	const Coordinate_t& getOrigin() const;
	void moveOrigin(const Coordinate_t&);

protected:
	Coordinate_t origin;
};

}
