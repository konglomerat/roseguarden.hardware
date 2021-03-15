/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "../../types/Primitive.h"
#include "../../text/FontManager.h"

#include <string_view>

namespace Graphics
{

class TextBoxBase_t : public Primitive_t
{
public:
	TextBoxBase_t(Coordinate_t origin, Color_t textColor, Color_t backgroundColor, const FontProperties_t& = DefaultFontProperties);

	Color_t textColor;
	Color_t backgroundColor;

protected:
	const IFont& font;
	void renderString(std::string_view, Coordinate_t={0,0});

private:
	Coordinate_t::Component_t renderChar(char c, const Coordinate_t & pos);
};
}

