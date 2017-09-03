#include "App.h"

#include <cstdlib>
#include "RFM69.h"
#include "stm32f0xx_hal.h"
#include "System.h"

extern SPI_HandleTypeDef hspi1;

RFM69 radio = RFM69(&hspi1, CS_RFM_GPIO_Port, CS_RFM_Pin);

enum PacketType : uint8_t {
	Ack = 0x00,
	Start = 0x01,
	Stop = 0x02,
};

struct RadioPacket {
	PacketType type;
	uint32_t ID;
} __attribute__((packed));

void App_Start()
{
	if (!radio.init()) {
		/* Failed to initialize radio */
		Shutdown(ErrRadioInit);
	}

	radio.setMode(RFM69::Mode::Receive);

	srand(radio.getRandom());
	/* generate random ID to identify correct Ack */
	uint32_t ButtonID = rand();

	if(getBatteryVoltage() < 3500) {
		/* Battery is low, abort */
		Shutdown(ErrBatteryLow);
	}

	bool ackReceived = false;
	uint8_t remainingAttempts = 5;
	while(remainingAttempts && !ackReceived) {
		/* Create button packet */
		const RadioPacket payload = {.type = BUTTON_TYPE, .ID = ButtonID};
		radio.send((uint8_t*) &payload, sizeof(RadioPacket));

		/* Wait for ACK */
		uint32_t sentTime = HAL_GetTick();
		/* Randomize wait time to avoid continuous collisions */
		const uint32_t waitTime = 100 + rand() % 64;
		while(HAL_GetTick() - sentTime < waitTime) {
			if(radio.gotPacket()) {
				/* Received something, check for ACK */
				RFM69::Packet packet = radio.getPacket();
				if(packet.length >= sizeof(RadioPacket)) {
					RadioPacket *received = (RadioPacket*) packet.data;
					if(received->type == Ack && received->ID == ButtonID) {
						/* This is an ACK */
						ackReceived = true;
						break;
					}
				}
			}
		}
	}

	if(!ackReceived) {
		/* Failed to reliable send packet */
		Shutdown(ErrNoAck);
	}
	/* All done, shutdown without error */
	Shutdown();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
	case GPIO_PIN_0:
		radio.onDIO0();
		break;
	}
}
