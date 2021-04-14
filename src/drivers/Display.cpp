/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

#include "Display.h"

#include "freertos/task.h"
#include "driver/gpio.h"

#include <cstring>


namespace Drivers
{

#define SPI_PERIPHERAL		HSPI_HOST

#define SPI_SDCLK_GPIO      GPIO_NUM_14
#define SPI_MOSI_GPIO       GPIO_NUM_2
#define SPI_MISO_GPIO       GPIO_NUM_23
#define SPI_CS_GPIO			GPIO_NUM_17

#define SPI_FREQ            SPI_MASTER_FREQ_8M

#define DC_GPIO				GPIO_NUM_15
#define DC_GPIO_BIT_MASK	(1 << DC_GPIO)

#define DMA_CHANNEL			2

spi_device_handle_t Display::spiHandle;

const char* DISPLAY_LOG_TAG = "Display";

void Display::initHardware()
{
	initGPIO();
	initSPI();
}

void Display::initDisplay()
{
	setOn(false);

	setPowerControlB();
	setPowerOnSequenceControl();
	setDriverTimingControlA();
	setPowerControlA();
	setPumpRatio();
	setDriverTimingControlC();

	setPowerControl1();
	setPowerControl2();

	setVCOMControl1();
	setVCOMControl2();

	setPixelFormat();
	setFramerateControl1();
	setDisplayFunctionControl();
	setMemoryAccessControl();

	set3GammaControl();
	setGamma();
	setPositiveGammaCorrection();
	setNegativeGammaCorrection();

	setSleepMode(false);
	vTaskDelay(120 / portTICK_PERIOD_MS);

	setOn(true);
	vTaskDelay(120 / portTICK_PERIOD_MS);
}

void Display::initGPIO()
{
	gpio_config_t dcGpioConfig;
	dcGpioConfig.intr_type    = GPIO_INTR_DISABLE;
	dcGpioConfig.mode         = GPIO_MODE_OUTPUT;
	dcGpioConfig.pin_bit_mask = DC_GPIO_BIT_MASK;
	dcGpioConfig.pull_down_en = GPIO_PULLDOWN_ENABLE;
	dcGpioConfig.pull_up_en   = GPIO_PULLUP_ENABLE;
	gpio_config(&dcGpioConfig);
}

void Display::initSPI()
{
	spi_bus_config_t busConfig;
	std::memset(&busConfig, 0 , sizeof(spi_bus_config_t));

	busConfig.miso_io_num     = SPI_MISO_GPIO;
	busConfig.mosi_io_num     = SPI_MOSI_GPIO;
	busConfig.sclk_io_num     = SPI_SDCLK_GPIO;
	busConfig.quadhd_io_num   = -1;
	busConfig.quadwp_io_num   = -1;
	busConfig.max_transfer_sz = FrameBuffer_t::getSizeInBytes();

	busConfig.flags = 0;

	auto busResult = spi_bus_initialize(SPI_PERIPHERAL, &busConfig, DMA_CHANNEL);
	ESP_ERROR_CHECK(busResult);

	spi_device_interface_config_t deviceConfig;
	std::memset(&deviceConfig, 0 , sizeof(spi_device_interface_config_t));

	deviceConfig.clock_speed_hz = SPI_FREQ;
	deviceConfig.mode           = 0;
	deviceConfig.spics_io_num   = SPI_CS_GPIO;
	deviceConfig.queue_size     = 7;
	deviceConfig.pre_cb         = spiPreTransferCallback;

	deviceConfig.address_bits     = 0;
	deviceConfig.command_bits     = 0;
	deviceConfig.cs_ena_posttrans = 0;
	deviceConfig.cs_ena_pretrans  = 0;
	deviceConfig.dummy_bits       = 0;
	deviceConfig.duty_cycle_pos   = 128;
	deviceConfig.input_delay_ns   = 0;
	deviceConfig.post_cb          = NULL;
	deviceConfig.flags            = 0;

	auto deviceResult = spi_bus_add_device(SPI_PERIPHERAL, &deviceConfig, &spiHandle);
	ESP_ERROR_CHECK(deviceResult);

	ESP_LOGD(DISPLAY_LOG_TAG, "Spi handle located at %x", (uint32_t)spiHandle);
}

void Display::doReset()
{
	ESP_LOGD(DISPLAY_LOG_TAG, "Manual reset not available");
}

void Display::spiPreTransferCallback(spi_transaction_t *transaction)
{
	DataMode_t mode;
	memcpy(&mode, &(transaction->user), sizeof(mode));

	setDataMode(mode);
}

void Display::setDataMode(DataMode_t mode)
{
	if (mode == DataMode_t::DATA)
	{
		gpio_set_level(DC_GPIO, 1);
	}
	else
	{
		gpio_set_level(DC_GPIO, 0);
	}
}

void Display::send(DataMode_t mode, uint8_t byte)
{
	spi_transaction_t transaction;
	std::memset(&transaction, 0 , sizeof(spi_transaction_t));

	transaction.length    = 8;
	transaction.tx_buffer = &byte;
	transaction.user      = (void*) mode;
	transaction.flags     = 0;

	auto result = spi_device_polling_transmit(spiHandle, &transaction);

	if (result != ESP_OK)
	{
		ESP_LOGE(DISPLAY_LOG_TAG, "Sending failed with %u", result);
	}
}

void Display::sendDMA(DataMode_t mode, const uint8_t* ptr,size_t length)
{
	static spi_transaction_t transaction;
	std::memset(&transaction, 0, sizeof(spi_transaction_t));

	transaction.length     = length * 8;
	transaction.tx_buffer  = ptr;
	transaction.user       = (void*) mode;
	transaction.flags      = 0;
	transaction.cmd        = 0;
	transaction.addr       = 0;
	transaction.rxlength   = 0;
	transaction.rx_buffer  = NULL;

	auto resultQueue = spi_device_transmit(spiHandle, &transaction);

	if (resultQueue != ESP_OK)
	{
		ESP_LOGE(DISPLAY_LOG_TAG, "Sending with DMA failed with %u", resultQueue);
	}
}

}
