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

class TextBoxAllocated_t : public TextBoxBase_t
{
public:
	TextBoxAllocated_t(Coordinate_t origin, std::size_t numbChars, Color_t textColor = DefaultForegroundColor, Color_t backgroundColor = DefaultForegroundColor, const FontProperties_t& = DefaultFontProperties);
	~TextBoxAllocated_t();

	void printf(const char* string)
	{
		snprintf (buffer, BufferSize, "%s", string);
	}

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wformat-nonliteral"
	template <typename ...Args>
	void printf(const char* format, Args...args)
	{
		snprintf (buffer, BufferSize, format, args...);
	}
	#pragma GCC diagnostic pop

	void render() override;

private:
	char* buffer;
	std::size_t BufferSize;
};

}
