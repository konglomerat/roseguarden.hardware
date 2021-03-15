/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */

#include "FontManager.h"

#include "fonts/xenon_5.h"
#include "fonts/xenon_8.h"

namespace Graphics
{

const IFont& getFont(const FontProperties_t& properties)
{
	if (properties.size == FontProperties_t::SMALL)
	{
		return Font_xenon2_5;
	}
	else
	{
		return Font_xenon2_8;
	}
}

}

