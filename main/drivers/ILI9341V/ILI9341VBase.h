/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */

#pragma once

#include <inttypes.h>
#include "types.h"
#include "BitBuffer.h"

namespace Drivers::ILI9341V
{

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
class ILI9341VBase
{
public:
	using FrameBuffer_t = BitBuffer_t<DIMX,DIMY>;

public:
	static void init();
	static void writeFrame(const FrameBuffer_t&);
	static void writePixel(uint32_t x, uint32_t y);

protected:
	static void setOn(bool);
	static void setSleepMode(bool);

	static void setPowerControlA();
	static void setPowerControlB();
	static void setPowerOnSequenceControl();
	static void setDriverTimingControlA();
	static void setDriverTimingControlC();
	static void setPumpRatio();

	static void setPowerControl1();
	static void setPowerControl2();

	static void setVCOMControl1();
	static void setVCOMControl2();

	static void setMemoryAccessControl();
	static void setVerticalScrollingStartAddress();
	static void setPixelFormat();

	static void setFramerateControl1();

	static void setDisplayFunctionControl();

	static void set3GammaControl();
	static void setGamma();
	static void setPositiveGammaCorrection();
	static void setNegativeGammaCorrection();

	static void setColumnAddress(uint16_t start, uint16_t end);
	static void setPageAddress(uint16_t start, uint16_t end);
	static void startMemoryWrite();

	static void sendEmptyCommand();

protected:
	static const uint8_t MAX_NUMB_COLUMNS = 128;
	static const uint8_t MAX_NUMB_LINES = 64;
	static const uint8_t MAX_NUMB_PAGES = MAX_NUMB_LINES/8;

public:
	enum DataMode_t {DATA, COMMAND};

private:
	static void sendCommand(uint8_t);
	static void sendData(uint8_t);

private:
	static bool initialized;
};

}

#include "ILI9341VBase.hpp"

