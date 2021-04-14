/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */



#include "Primitive.h"

namespace Graphics
{

Primitive_t::Primitive_t(Coordinate_t org) : Moveable_t(org)
{
	Renderer::registerShape(this);
}

Primitive_t::~Primitive_t()
{
	Renderer::unregisterShape(this);
}

void Primitive_t::definePixel(const Coordinate_t& pos, Color_t val)
{
	if (val != TRANSPARENT)
	{
		Renderer::frame->set(origin.x + pos.x, origin.y + pos.y, (uint8_t)val);
	}
}

}
