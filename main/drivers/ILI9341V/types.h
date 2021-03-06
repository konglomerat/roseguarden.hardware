/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

namespace Drivers::ILI9341V
{

enum Command_t
{
	SET_DISPLAY_OFF = 0x28,
	SET_DISPLAY_ON = 0x29,

	SET_POWER_CONTROL_A = 0xCB,
	SET_POWER_CONTROL_B = 0xCF,
	SET_POWER_ON_SEQUENCE_CONTROL = 0xED,
	SET_DRIVER_TIMING_CONTROL_A = 0xE8,
	SET_DRIVER_TIMING_CONTROL_C = 0xEA,

	SET_PUMP_RATIO = 0xF7,

	SET_POWER_CONTROL_1 = 0xC0,
	SET_POWER_CONTROL_2 = 0xC1,
	SET_VCOM_CONTROL_1 = 0xC5,
	SET_VCOM_CONTROL_2 = 0xC7,

	SET_MEMORY_ACCESS_CONTROL = 0x36,
	SET_VERTICAL_SCROLLING_START_ADDRESS = 0x37,
	SET_PIXEL_FORMAT = 0x3A,

	SET_FRAMERATE_CONTROL_1 = 0xB1,
	SET_FRAMERATE_CONTROL_2 = 0xB2,
	SET_FRAMERATE_CONTROL_3 = 0xB3,

	SET_DISPLAY_FUNCTION_CONTROL = 0xB6,

	SET_3_GAMMA_CONTROL = 0xF2,
	SET_GAMMA = 0x26,
	SET_POSITIVE_GAMMA_CORRECTION = 0xE0,
	SET_NEGATIVE_GAMMA_CORRECTION = 0xE1,

	SET_SLEEP_MODE_ON = 0x10,
	SET_SLEEP_MODE_OFF = 0x11,

	START_MEMORY_WRITE = 0x2C,
	SET_COLUMN_ADDRESS = 0x2A,
	SET_PAGE_ADDRESS = 0x2B,

	EMPTY_COMMAND = 0x00,
};

}
