/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "TextBox.h"


namespace Graphics
{

TextBox_t::TextBox_t(Coordinate_t orig, std::string_view buffer_, Color_t tColor, Color_t bColor, const FontProperties_t& fontProps)
	: TextBoxBase_t(orig, tColor, bColor, fontProps)
{
	setText(buffer_);
}

TextBox_t::TextBox_t(Coordinate_t orig, Color_t tColor, Color_t bColor, const FontProperties_t& fontProps)
	: TextBoxBase_t(orig, tColor, bColor, fontProps)
{
}

void TextBox_t::setText(std::string_view newBuffer)
{
	buffer = newBuffer;
}

void TextBox_t::render()
{
	renderString(buffer);
}

}
