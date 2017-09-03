#pragma once

#include <cstdint>

#include "../Radio/rfm69hw_registermap.h"
#include "stm32f0xx_hal.h"

#define RFM69_GETTIME()		HAL_GetTick()

#ifdef RFM69_GETTIME
#define RFM69_MAX_FRAME 	61
#else
#define RFM69_MAX_FRAME 	65
#endif

class RFM69 {
public:
	enum class Mode: uint8_t {
				Sleep = MODE_SLEEP,
				Standby = MODE_STDBY,
				Synthesizer = MODE_FS,
				Transmit = MODE_TX,
				Receive = MODE_RX,
	};

	class Packet {
	public:
		uint8_t data[RFM69_MAX_FRAME];
		uint8_t length;
		uint32_t sentTimestamp;
		uint32_t receivedTimestamp;
		int8_t rssi;
		uint8_t lna;
	};

	constexpr RFM69(SPI_HandleTypeDef *spi, GPIO_TypeDef *gpio, uint16_t pin)
	: spi(spi)
	, nss_gpio(gpio)
	, nss_pin(pin)
	, mode(Mode::Standby)
	, oldMode(Mode::Standby)
	, packet()
	, receivedPacket(false)
	, isHWversion(true)
	, transmitPower(0)
	{};

	bool init();
	uint32_t getFrequency();
	void setFrequency(uint32_t freq);
	void setMode(Mode m);
	void setPower(int8_t dbm) { transmitPower = dbm; }
	Mode getMode();
	bool send(const uint8_t *data, uint8_t len);
	int8_t getRSSI();
	uint32_t getRandom();
	void onDIO0(void);
	Packet getPacket(void);
	bool gotPacket() const {
		return receivedPacket;
	}

private:
	uint8_t readRegister(uint8_t address);
	void writeRegister(uint8_t address, uint8_t value);
	uint8_t readSubregister(uint8_t address, uint8_t mask, uint8_t position);
	void writeSubregister(uint8_t address, uint8_t mask, uint8_t position, uint8_t value);
	void applyPower(int8_t dbm);
	void restoreMode() { setMode(oldMode); };

	SPI_HandleTypeDef *spi;
	GPIO_TypeDef *nss_gpio;
	uint16_t nss_pin;
	Mode mode, oldMode;
	Packet packet;
	bool receivedPacket;
	const bool isHWversion;
	int8_t transmitPower;
};
