/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "graphics/primitives/TextBox.h"

namespace Roseguarden
{

class TextView
{
public:
	enum TextLines_t
	{
		HEADER,
		CENTER_1,
		CENTER_2,
		BOTTOM_1,
		BOTTOM_2,
		BOTTOM_3
	};
public:
	TextView();
	void setLineText(const TextLines_t&, std::string_view);
private:
	Graphics::TextBox_t header;
	Graphics::TextBox_t centerLine1;
	Graphics::TextBox_t centerLine2;
	Graphics::TextBox_t bottomLine1;
	Graphics::TextBox_t bottomLine2;
	Graphics::TextBox_t bottomLine3;
};

}

 /* MAIN_ROSEGUARDEN_TEXTVIEW_H_ */
