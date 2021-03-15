/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once


#include "types/Font.h"
#include "types/FontProperties.h"

namespace Graphics
{

const FontProperties_t DefaultFontProperties
{
	FontProperties_t::Size_t::LARGE
};

const IFont& getFont(const FontProperties_t& properties);
}

