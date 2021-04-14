/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

namespace Drivers
{

class Relay
{
public:
	static void init();

	static void on();
	static void off();

	static bool isOn();
};


}
