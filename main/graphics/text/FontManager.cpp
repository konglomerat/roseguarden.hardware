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
#include "fonts/xenon_10.h"
#include "fonts/xenon_12.h"
#include "fonts/xenon_14.h"
#include "fonts/red_alert_17.h"
#include "fonts/red_alert_20.h"
#include "fonts/red_alert_24.h"
#include "fonts/silkscreen_24.h"

namespace Graphics
{

const IFont& getFont(const FontProperties_t& properties)
{
	if (properties.size == FontProperties_t::SMALL)
	{
		return Red_Alert_Inet_20;
	}
	else
	{
		return Red_Alert_Inet_24;
	}
}

}

