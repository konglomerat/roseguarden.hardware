/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "Renderer.h"
#include "../drivers/Display.h"

namespace Graphics
{

void Renderer::_impl_initDriver()
{
	Drivers::Display::init();
}

void Renderer::_impl_writeFrame(const NativeFrame_t& frame)
{
	Drivers::Display::writeFrame(frame);
}

}
