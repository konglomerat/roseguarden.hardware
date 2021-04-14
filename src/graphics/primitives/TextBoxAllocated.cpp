/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "TextBoxAllocated.h"


namespace Graphics
{

TextBoxAllocated_t::TextBoxAllocated_t(Coordinate_t org, std::size_t chars, Color_t textC, Color_t backgroundC, const FontProperties_t& fontProp)
	: TextBoxBase_t(org, textC, backgroundC, fontProp),
	  buffer(new char[chars]),
	  BufferSize(chars)
{
	buffer[0] = 0;
};

TextBoxAllocated_t::~TextBoxAllocated_t()
{
	delete buffer;
}

void TextBoxAllocated_t::render()
{
	TextBoxBase_t::renderString(std::string_view(buffer, BufferSize));
}


}
