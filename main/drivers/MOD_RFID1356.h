/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include <string>
#include <optional>

namespace Drivers
{

class MOD_RFID1356
{
public:
	static bool init();

	using CardID_t = uint32_t;
	static std::optional<CardID_t> getCardID();

private:
	static void initUART();
	static uint32_t getNumberOfBytesInUARTRXBuffer();


private:
	using Response_t = std::string;
	using Command_t = std::string;

private:
	static void resetCommandInterface();
	static Response_t readFirmwareInformation();
	static void setScanInterval(uint32_t);

private:
	static Response_t sendCommand(const Command_t&);

private:
	static std::string cardIDBuffer;
	static std::optional<size_t> searchCardIDIdentifier(const std::string&);
};
}
