/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "Moveable.h"

namespace Graphics
{

Moveable_t::Moveable_t(Coordinate_t orig)
	: origin(orig)
{
}

const Coordinate_t& Moveable_t::getOrigin() const
{
	return origin;
}
void Moveable_t::moveOrigin(const Coordinate_t& vector)
{
	origin += vector;
}

}

