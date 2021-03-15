/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "ILI9341V/ILI9341VBase.h"
using namespace Drivers::ILI9341V;

#include "driver/spi_master.h"

namespace Drivers
{

class Display : public ILI9341VBase<Display,240,320>
{
public:
	static constexpr char const* name = "Display";
	static const uint32_t SIZEX = 240;
	static const uint32_t SIZEY = 320;

	static void initHardware();
	static void initDisplay();
	static void doReset();

	static void send(DataMode_t, uint8_t);
	static void sendDMA(DataMode_t,const uint8_t* ptr, std::size_t length);
	static void spiPreTransferCallback(spi_transaction_t *transaction);

private:
	static void initGPIO();
	static void initSPI();

	static void setDataMode(DataMode_t);

private:
	static spi_device_handle_t spiHandle;

};


}


