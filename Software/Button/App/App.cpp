#include "App.h"

#include "stm32f0xx_hal.h"
#include "Flash.h"
#include "RFM69.h"
#include "System.h"
#include "Random.h"

extern SPI_HandleTypeDef hspi1;

RFM69 radio = RFM69(&hspi1, CS_RFM_GPIO_Port, CS_RFM_Pin);

typedef uint32_t ButtonID_t;

constexpr uint32_t persistencePage = FLASH_BANK1_END - FLASH_PAGE_SIZE + 1;
auto memory = System::Flash<ButtonID_t>(persistencePage);

enum class PacketType : uint8_t {
	Ack = 0x00,
	ButtonPress = 0x01,
};

struct RadioPacket {
	PacketType type;
	ButtonID_t ID;
} __attribute__((packed));

void App_Start() {
	if (!radio.init()) {
		/* Failed to initialize radio */
		System::Shutdown(System::Error::RadioInit);
	}

	radio.setMode(RFM69::Mode::Receive);

	if (System::GetBatteryVoltage() < 3500) {
		/* Battery is low, abort */
		System::Shutdown(System::Error::BatteryLow);
	}

	ButtonID_t ButtonID;
	if (memory.available()) {
		/* Read random ID from memory */
		ButtonID = memory.read();
	} else {
		/* No ID yet, generate one from the RSSI noise */
		ButtonID = radio.getRandom();
		memory.write(ButtonID);
	}
	System::Random rng;
	rng.seed(ButtonID);

	bool ackReceived = false;
	uint8_t remainingAttempts = 5;
	while (remainingAttempts && !ackReceived) {
		/* Create button packet */
		const RadioPacket payload = { .type = PacketType::ButtonPress, .ID =
				ButtonID };
		radio.send((uint8_t*) &payload, sizeof(RadioPacket));

		/* Wait for ACK */
		uint32_t sentTime = HAL_GetTick();
		/* Randomize wait time to avoid continuous collisions */
		const uint32_t waitTime = 100 + rng.next() % 64;
		while (HAL_GetTick() - sentTime < waitTime) {
			if (radio.gotPacket()) {
				/* Received something, check for ACK */
				RFM69::Packet packet = radio.getPacket();
				if (packet.length >= sizeof(RadioPacket)) {
					RadioPacket *received = (RadioPacket*) packet.data;
					if (received->type == PacketType::Ack
							&& received->ID == ButtonID) {
						/* This is an ACK */
						ackReceived = true;
						break;
					}
				}
			}
		}
	}

	if (!ackReceived) {
		/* Failed to reliable send packet */
		System::Shutdown(System::Error::NoAck);
	}
	/* All done, shutdown without error */
	System::Shutdown();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	switch (GPIO_Pin) {
	case GPIO_PIN_0:
		radio.onDIO0();
		break;
	}
}
