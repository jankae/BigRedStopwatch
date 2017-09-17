#include "App.h"

#include "stm32f0xx_hal.h"
#include "Flash.h"
#include "RFM69.h"
#include "System.h"
#include "Random.h"

extern SPI_HandleTypeDef hspi1;

RFM69 radio = RFM69(&hspi1, CS_RFM_GPIO_Port, CS_RFM_Pin);

typedef uint16_t ButtonID_t;

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

	System::print("Application start\n");

	if (!radio.init()) {
		/* Failed to initialize radio */
		System::print("Radio initialization failed\n");
		System::Shutdown(System::Error::RadioInit);
	}
	System::print("Radio initialized\n");

	radio.setMode(RFM69::Mode::Receive);

	uint32_t battery = System::GetBatteryVoltage();

	System::print("Battery: %lumV\n", battery);
	if (battery < 3300) {
		/* Battery is low, abort */
		System::print("Shutting down due to low battery\n");
		System::Shutdown(System::Error::BatteryLow);
	}

	ButtonID_t ButtonID;
	if (memory.available()) {
		/* Read random ID from memory */
		ButtonID = memory.read();
		System::print("Button ID read from memory: %04x\n", ButtonID);
	} else {
		/* No ID yet, generate one from the RSSI noise */
		do {
			ButtonID = radio.getRandom();
		} while (ButtonID == 0);
		System::print("Button ID generated: %04x\n", ButtonID);
		memory.write(ButtonID);
	}
	System::Random rng;
	rng.seed(ButtonID);

	bool ackReceived = false;
	uint8_t remainingAttempts = 5;
	while (remainingAttempts && !ackReceived) {
		System::print("Sending packet %d\n", 5 - remainingAttempts);
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
					System::print("Received a packet\n");
					RadioPacket *received = (RadioPacket*) packet.data;
					if (received->type == PacketType::Ack
							&& received->ID == ButtonID) {
						/* This is an ACK */
						System::print("Received ACK\n");
						ackReceived = true;
						break;
					}
				}
			}
		}
		remainingAttempts--;
	}

	radio.setMode(RFM69::Mode::Standby);

	if (!ackReceived) {
		/* Failed to reliable send packet */
		System::print("Couldn't get an ACK\n");
		System::Shutdown(System::Error::NoAck);
	}
	/* All done, shutdown without error */
	System::Shutdown(System::Error::None);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	switch (GPIO_Pin) {
	case GPIO_PIN_0:
		radio.onDIO0();
		break;
	}
}
