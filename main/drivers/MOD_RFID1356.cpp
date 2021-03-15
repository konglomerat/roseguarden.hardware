/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#include "MOD_RFID1356.h"

#include "driver/uart.h"
#include "driver/gpio.h"

#include <cassert>
#include <string>

//#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

namespace Drivers
{

static const char* TAG = "MOD_RFID1356";

#define UART_PERIPHERAL				UART_NUM_1
#define UART_TX_PIN					GPIO_NUM_4
#define UART_RX_PIN					GPIO_NUM_36
#define UART_RTS_PIN  				UART_PIN_NO_CHANGE
#define UART_CTS_PIN  				UART_PIN_NO_CHANGE

const uint32_t BAUD_RATE = 38400;

//TODO: this buffer has to be big enough to store any response of the card reader
const std::size_t RX_BUF_SIZE = 2048;

const std::size_t RESPONSE_TIME_IN_TICKS = (150/portTICK_RATE_MS);
const std::size_t UART_SEND_BYTE_DELAY_IN_TICKS	= (10/portTICK_RATE_MS);
const std::size_t UART_READ_TIMEOUT_IN_TICKS = (10/portTICK_RATE_MS);

const std::size_t MAXIMUM_NUMBER_OF_BLOCKS_IN_CARD = 64;

const char* DeviceIdentifier = "https://www.olimex.com/wiki/MOD-RFID1356MIFARE";
const uint32_t ScanIntervallInMilliseconds = 100;
const char* CardIDIdentifier = "-";
const uint32_t CardIDSizeInCharacters = 8;

std::string MOD_RFID1356::cardIDBuffer;


bool MOD_RFID1356::init()
{
	cardIDBuffer.clear();

	ESP_LOGD(TAG, "InitUART");
	initUART();

	resetCommandInterface();

	auto firmwareInformation = readFirmwareInformation();

	if (firmwareInformation.size() > 0)
	{
		if (firmwareInformation.find(DeviceIdentifier) != std::string::npos)
		{
			ESP_LOGD(TAG, "Found reader");

			setScanInterval(ScanIntervallInMilliseconds);

			return true;
		}
		else
		{
			ESP_LOGE(TAG, "Incompatible device connected:\n%s", firmwareInformation.c_str());
		}
	}
	else
	{
		ESP_LOGE(TAG, "Cannot read firmware information");
	}

	return false;
}

void MOD_RFID1356::resetCommandInterface()
{
	ESP_LOGD(TAG, "Reset command interface");

	const Command_t emptyCommand = "";
	sendCommand(emptyCommand);

	uart_flush_input(UART_PERIPHERAL);
}

MOD_RFID1356::Response_t MOD_RFID1356::readFirmwareInformation()
{
	ESP_LOGD(TAG, "Get firmware information");

	const Command_t firmwareCommand = "i";
	Response_t response = sendCommand(firmwareCommand);

	return response;
}

void MOD_RFID1356::setScanInterval(uint32_t interval)
{
	ESP_LOGD(TAG, "Set scan intervall to %u ms", interval);

	std::string scanIntervall = std::to_string(ScanIntervallInMilliseconds);

	const Command_t scanIntervallCommand = "mt" + scanIntervall;
	sendCommand(scanIntervallCommand);
}


std::optional<MOD_RFID1356::CardID_t> MOD_RFID1356::getCardID()
{
	std::optional<CardID_t> cardID;

	uint32_t numberOfBytesToReceive = CardIDSizeInCharacters * 4;

	Response_t response;
	response.assign(numberOfBytesToReceive, '=');
	uart_flush_input(UART_PERIPHERAL);
	ESP_LOGD(TAG, "Try to receive %u bytes", numberOfBytesToReceive);
	uint32_t numberOfBytesReceived = uart_read_bytes(UART_PERIPHERAL,(uint8_t*) response.data(), numberOfBytesToReceive, 400 / portTICK_PERIOD_MS);

	if(numberOfBytesReceived > 0)
	{
		ESP_LOGD(TAG, "Received %u bytes", numberOfBytesReceived);
		response.resize(numberOfBytesReceived);

		if (auto cardIdentifierPosition = searchCardIDIdentifier(response))
		{
			ESP_LOGD(TAG, "Found card identifier at position %u.", cardIdentifierPosition.value());
			uint32_t bytesInResponseAfterIdentifier = response.size() - (cardIdentifierPosition.value() + 1);

			auto numbBytesToCopy = std::min(bytesInResponseAfterIdentifier, CardIDSizeInCharacters);

			cardIDBuffer.append(response, cardIdentifierPosition.value() + 1, numbBytesToCopy);
		}

		if (cardIDBuffer.size() == CardIDSizeInCharacters)
		{
			cardID = std::stoul(cardIDBuffer, nullptr, 16);
		}

		cardIDBuffer.clear();
	}

	return cardID;
}

std::optional<size_t> MOD_RFID1356::searchCardIDIdentifier(const std::string& string)
{
	if(string.find(CardIDIdentifier) != std::string::npos)
	{
		return string.find(CardIDIdentifier);
	}

	return std::nullopt;
}


void MOD_RFID1356::initUART()
{
	uart_config_t uart_config =
	{
			.baud_rate = BAUD_RATE,
			.data_bits = UART_DATA_8_BITS,
			.parity    = UART_PARITY_DISABLE,
			.stop_bits = UART_STOP_BITS_1,
			.flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
			.rx_flow_ctrl_thresh = 0,
			UART_SCLK_APB
	};

	if (auto configResult = uart_param_config(UART_PERIPHERAL, &uart_config); configResult == ESP_OK)
	{
		if (auto setPinResult = uart_set_pin(UART_PERIPHERAL, UART_TX_PIN, UART_RX_PIN, UART_RTS_PIN, UART_CTS_PIN); setPinResult == ESP_OK)
		{
			if (auto driverResult = uart_driver_install(UART_NUM_1, RX_BUF_SIZE, 0, 0, NULL, 0); driverResult == ESP_OK)
			{
				ESP_LOGD(TAG, "UART Initialized");
			}
			else
			{
				ESP_LOGE(TAG, "Cannot start UART driver");
			}
		}
		else
		{
			ESP_LOGE(TAG, "Cannot set UART Pin");
		}
	}
	else
	{
		ESP_LOGE(TAG, "Cannot configure UART");
	}
}

uint32_t MOD_RFID1356::getNumberOfBytesInUARTRXBuffer()
{
	uint32_t numberOfBytesInBuffer;
	uart_get_buffered_data_len(UART_PERIPHERAL, &numberOfBytesInBuffer);

	return numberOfBytesInBuffer;
}

MOD_RFID1356::Response_t MOD_RFID1356::sendCommand(const Command_t& command)
{
	/*
	 * The card reader is slow. Sending those bytes right after each other results in transmissions erros. Sending them one by one with a delay fixes that.
	 */
	for (uint32_t characterIndex = 0; characterIndex < command.size(); characterIndex++)
	{
		uart_write_bytes(UART_PERIPHERAL, &(command[characterIndex]), 1);
		vTaskDelay(UART_SEND_BYTE_DELAY_IN_TICKS);
	}

	// send end of line to terminate command string
	uart_write_bytes(UART_PERIPHERAL, "\r", 1);
	vTaskDelay(UART_SEND_BYTE_DELAY_IN_TICKS);

	vTaskDelay(RESPONSE_TIME_IN_TICKS);

	uint32_t numberOfReceivedBytes;
	uart_get_buffered_data_len(UART_PERIPHERAL, &numberOfReceivedBytes);
	ESP_LOGD(TAG, "Response contains %u bytes", numberOfReceivedBytes);

	Response_t response;
	response.assign(numberOfReceivedBytes, '=');
	uart_read_bytes(UART_PERIPHERAL,(uint8_t*) response.data(), numberOfReceivedBytes, UART_READ_TIMEOUT_IN_TICKS);
	ESP_LOGD(TAG, "Response:\n %s", response.c_str());

	return response;
}

}


