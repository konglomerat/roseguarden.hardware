/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "esp_log.h"

namespace Drivers::ILI9341V
{

static const char* LOG_TAG = "ILI9341V";

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
bool ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::initialized = false;


template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::init()
{
	if (!initialized)
	{
		ESP_LOGD(LOG_TAG, "%s: Initializing", IMPLEMENTATION::name);

		IMPLEMENTATION::initHardware();
		IMPLEMENTATION::doReset();
		IMPLEMENTATION::initDisplay();
		initialized = true;
	}
	else
	{
		ESP_LOGE(LOG_TAG, "%s: already initialized", IMPLEMENTATION::name);
	}
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::sendCommand(uint8_t cmd)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Send Command 0x%02x", cmd);


	IMPLEMENTATION::send(DataMode_t::COMMAND, cmd);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::sendData(uint8_t data)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Send Data 0x%02x", data);

	IMPLEMENTATION::send(DataMode_t::DATA, data);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::writeFrame(const FrameBuffer_t& frame)
{
	setColumnAddress(0, DIMX - 1);
	setPageAddress(0, DIMY - 1);

	startMemoryWrite();

	const uint32_t maximumPixelsPerTransmission = 512;
	const uint32_t bytesPerPixel = 2;
	const uint32_t maximumBytesPerTransmission = maximumPixelsPerTransmission * bytesPerPixel;
	std::array<uint8_t, maximumBytesPerTransmission> sendBuffer;

	uint32_t pixelsToBeSent = frame.getNumberOfElements();
	uint32_t indexOffset = 0;

	while(pixelsToBeSent > 0)
	{
		for(uint32_t index = 0; index < std::min(maximumPixelsPerTransmission, pixelsToBeSent); index++)
		{
			if(frame.getPixelByIndex(index + indexOffset) == true)
			{
				sendBuffer[index * 2] = 0xFF;
				sendBuffer[index * 2 + 1] = 0xFF;
			}
			else
			{
				sendBuffer[index * 2] = 0x00;
				sendBuffer[index * 2 + 1] = 0x00;
			}
		}

		uint32_t transferSizeInPixel = std::min(maximumPixelsPerTransmission, pixelsToBeSent);

		IMPLEMENTATION::sendDMA(DataMode_t::DATA, sendBuffer.data(), transferSizeInPixel * bytesPerPixel);

		pixelsToBeSent -= transferSizeInPixel;
		indexOffset += transferSizeInPixel;
	}

	sendEmptyCommand();
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::writePixel(uint32_t x, uint32_t y)
{
	//set pixel to white
	uint8_t firstByte = 0xFF;
	uint8_t secondByte = 0xFF;

	setColumnAddress(x, x);
	setPageAddress(y, y);

	startMemoryWrite();

	IMPLEMENTATION::send(DataMode_t::DATA, firstByte);
	IMPLEMENTATION::send(DataMode_t::DATA, secondByte);

	sendEmptyCommand();
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setColumnAddress(uint16_t start, uint16_t end)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: set column address from %u to %u", start, end);

	sendCommand(SET_COLUMN_ADDRESS);
	sendData(start>>8);
	sendData(start);
	sendData(end>>8);
	sendData(end);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPageAddress(uint16_t start, uint16_t end)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: set page address from %u to %u", start, end);

	sendCommand(SET_PAGE_ADDRESS);
	sendData(start>>8);
	sendData(start);
	sendData(end>>8);
	sendData(end);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::startMemoryWrite(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: start memory write");

	sendCommand(START_MEMORY_WRITE);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::sendEmptyCommand(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: send empty command");

	sendCommand(EMPTY_COMMAND);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setOn(bool val)
{
	if (val)
	{
		ESP_LOGV(LOG_TAG, "ILI9341V: Set on");

		sendCommand(SET_DISPLAY_ON);
	}
	else
	{
		ESP_LOGV(LOG_TAG, "ILI9341V: Set off");

		sendCommand(SET_DISPLAY_OFF);
	}
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setSleepMode(bool val)
{
	if (val)
	{
		ESP_LOGV(LOG_TAG, "ILI9341V: Set sleep mode on");

		sendCommand(SET_SLEEP_MODE_ON);
	}
	else
	{
		ESP_LOGV(LOG_TAG, "ILI9341V: Set sleep mode  off");

		sendCommand(SET_SLEEP_MODE_OFF);
	}
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPowerControlA(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Power Control A");

	sendCommand(SET_POWER_CONTROL_A);
	sendData(0x39);
	sendData(0x2C);
	sendData(0x00);
	sendData(0x34);
	sendData(0x02);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPowerControlB(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Power Control B");

	sendCommand(SET_POWER_CONTROL_B);
	sendData(0x00);
	sendData(0xC1);
	sendData(0x30);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPowerOnSequenceControl(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Power On Sequence Control");

	sendCommand(SET_POWER_ON_SEQUENCE_CONTROL);
	sendData(0x64);
	sendData(0x03);
	sendData(0x12);
	sendData(0x81);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setDriverTimingControlA(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Driver Timing Control A");

	sendCommand(SET_DRIVER_TIMING_CONTROL_A);
	sendData(0x85);
	sendData(0x00);
	sendData(0x78);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setDriverTimingControlC(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Driver Timing Control C");

	sendCommand(SET_DRIVER_TIMING_CONTROL_C);
	sendData(0x00);
	sendData(0x00);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPumpRatio(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Pump Ratio");

	sendCommand(SET_PUMP_RATIO);
	sendData(0x20);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPowerControl1(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Power Control 1");

	sendCommand(SET_POWER_CONTROL_1);
	sendData(0x23);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPowerControl2(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Power Control 2");

	sendCommand(SET_POWER_CONTROL_2);
	sendData(0x10);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setVCOMControl1(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set VCOM Control 1");

	sendCommand(SET_VCOM_CONTROL_1);
	sendData(0x3E);
	sendData(0x28);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setVCOMControl2(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set VCOM Control 2");

	sendCommand(SET_VCOM_CONTROL_2);
	sendData(0x86);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setMemoryAccessControl(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Memory Access Control");

	sendCommand(SET_MEMORY_ACCESS_CONTROL);
	sendData(0x00);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setVerticalScrollingStartAddress(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Vertical Scrolling Start Address");

	sendCommand(SET_VERTICAL_SCROLLING_START_ADDRESS);
	sendData(0x00);
	sendData(0x00);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPixelFormat(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Pixel Format");

	sendCommand(SET_PIXEL_FORMAT);
	sendData(0x55);//16bit MCU, 16bit RGB Interface
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setFramerateControl1(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Framerate Control 1");

	sendCommand(SET_FRAMERATE_CONTROL_1);
	sendData(0x00);
	sendData(0x18);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setDisplayFunctionControl(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Display Function Control");

	sendCommand(SET_DISPLAY_FUNCTION_CONTROL);
	sendData(0x08);
	sendData(0x82);
	sendData(0x27);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::set3GammaControl(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set 3 Gamma Control");

	sendCommand(SET_3_GAMMA_CONTROL);
	sendData(0x00);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setGamma(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Gamma");

	sendCommand(SET_GAMMA);
	sendData(0x01);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setPositiveGammaCorrection(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Postive Gamma Correction");

	sendCommand(SET_POSITIVE_GAMMA_CORRECTION);

	// TODO: What is the meaning of these constants?
    sendData(0x0F);
    sendData(0x31);
    sendData(0x2B);
    sendData(0x0C);
    sendData(0x0E);
    sendData(0x08);
    sendData(0x4E);
    sendData(0xF1);
    sendData(0x37);
    sendData(0x07);
    sendData(0x10);
    sendData(0x03);
    sendData(0x0E);
    sendData(0x09);
    sendData(0x00);
}

template <typename IMPLEMENTATION, uint32_t DIMX, uint32_t DIMY>
void ILI9341VBase<IMPLEMENTATION,DIMX,DIMY>::setNegativeGammaCorrection(void)
{
	ESP_LOGV(LOG_TAG, "ILI9341V: Set Negative Gamma Correction");

	sendCommand(SET_NEGATIVE_GAMMA_CORRECTION);

	// TODO: What is the meaning of these constants?
    sendData(0x00);
    sendData(0x0E);
    sendData(0x14);
    sendData(0x03);
    sendData(0x11);
    sendData(0x07);
    sendData(0x31);
    sendData(0xC1);
    sendData(0x48);
    sendData(0x08);
    sendData(0x0F);
    sendData(0x0C);
    sendData(0x31);
    sendData(0x36);
    sendData(0x0F);
}

}
