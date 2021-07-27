/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */

#pragma once

namespace Graphics
{

    enum Color_t
    {
        WHITE = 0,
        BLACK = 255,
        GREY_LIGHTER = 224,
        GREY_LIGHT = 160,
        GREY_MIDDLE = 128,
        GREY_DARK = 84,
        TRANSPARENT = -1
    };

    const Color_t DefaultForegroundColor = Color_t::BLACK;
    const Color_t DefaultBackGroundColor = Color_t::TRANSPARENT;

}
