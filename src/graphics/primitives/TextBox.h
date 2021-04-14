/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "generic/TextBoxBase.h"


namespace Graphics
{

class TextBox_t : public TextBoxBase_t
{
public:
	TextBox_t(Coordinate_t origin, std::string_view, Color_t textColor = DefaultForegroundColor, Color_t backgroundColor = DefaultBackGroundColor, const FontProperties_t& = DefaultFontProperties);
	TextBox_t(Coordinate_t origin, Color_t textColor = DefaultForegroundColor, Color_t backgroundColor = DefaultBackGroundColor, const FontProperties_t& = DefaultFontProperties);

	void setText(std::string_view);

private:
	void render() override;
	std::string_view buffer;
};

}

