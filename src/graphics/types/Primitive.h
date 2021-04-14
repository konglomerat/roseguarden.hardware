/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "../Renderer.h"
#include "Moveable.h"
#include "Color.h"

namespace Graphics
{

class Primitive_t : public Moveable_t
{
public:
	Primitive_t(Coordinate_t origin);
	virtual ~Primitive_t();

protected:
	void definePixel(const Coordinate_t& coordinate, Color_t val);

private:
	friend Renderer;
	virtual void render() = 0;
};

}

