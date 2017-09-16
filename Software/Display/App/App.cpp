#include "App.h"

#include "RFM69.h"
#include "stm32f0xx_hal.h"
#include "System.h"
#include "Switches.h"
#include "SevenSegment.h"
#include "Flash.h"

extern SPI_HandleTypeDef hspi1;

RFM69 radio = RFM69(&hspi1, CS_RFM69_GPIO_Port, CS_RFM69_Pin);

System::Switch OnOff(SWITCH_ONOFF_GPIO_Port, SWITCH_ONOFF_Pin);
System::Switch Start(SWITCH1_GPIO_Port, SWITCH1_Pin);
System::Switch Stop(SWITCH2_GPIO_Port, SWITCH2_Pin);
System::Switch Highscore(SWITCH3_GPIO_Port, SWITCH3_Pin);

System::SevenSegment<4> Display(
	/* Segment ports */
	{
	SEGMENT_A_GPIO_Port,
	SEGMENT_B_GPIO_Port,
	SEGMENT_C_GPIO_Port,
	SEGMENT_D_GPIO_Port,
	SEGMENT_E_GPIO_Port,
	SEGMENT_F_GPIO_Port,
	SEGMENT_G_GPIO_Port,
	SEGMENT_DOT_GPIO_Port },
	/* Segment pins */
	{
	SEGMENT_A_Pin,
	SEGMENT_B_Pin,
	SEGMENT_C_Pin,
	SEGMENT_D_Pin,
	SEGMENT_E_Pin,
	SEGMENT_F_Pin,
	SEGMENT_G_Pin,
	SEGMENT_DOT_Pin },
	/* Common ports */
	{
	DIGIT1_GPIO_Port,
	DIGIT2_GPIO_Port,
	DIGIT3_GPIO_Port,
	DIGIT4_GPIO_Port },
	/* Common pins */
	{
	DIGIT1_Pin,
	DIGIT2_Pin,
	DIGIT3_Pin,
	DIGIT4_Pin });

typedef uint16_t ButtonID_t;

typedef struct {
	ButtonID_t ID;
	uint32_t lastEvent;
} ButtonEntry_t;

#define MAX_BUTTON_IDS	5

struct RadioIDs {
	std::array<ButtonID_t, MAX_BUTTON_IDS> startIDs;
	std::array<ButtonID_t, MAX_BUTTON_IDS> stopIDs;
};

constexpr uint32_t persistencePage = FLASH_BANK1_END - FLASH_PAGE_SIZE + 1;
auto memory = System::Flash<RadioIDs>(persistencePage);

static RadioIDs IDs;

enum class PacketType : uint8_t {
	Ack = 0x00,
	ButtonPress = 0x01,
};

struct RadioPacket {
	PacketType type;
	ButtonID_t ID;
} __attribute__((packed));

enum class State : uint8_t {
	IDLE,
	RUNNING,
};

State state;
uint32_t startTime;
uint32_t stopTime;
uint32_t displayChangeTime;
uint32_t displayDuration;

uint32_t bestTime = UINT32_MAX;

static void setDisplayDuration(uint32_t ms) {
	displayChangeTime = HAL_GetTick();
	displayDuration = ms;
}

static void switchState(State s) {
	state = s;
	Start.clear();
	Stop.clear();
	Highscore.clear();
	OnOff.clear();
	System::print("Switching to state %d\n", (uint8_t) s);
}

static bool buttonInList(ButtonID_t ID, std::array<ButtonID_t, MAX_BUTTON_IDS> list) {
	for(uint8_t i=0;i<MAX_BUTTON_IDS;i++) {
		if(list[i] == ID) {
			return true;
		}
	}
	/* ID not in list */
	return false;
}

static void removeFromList(ButtonID_t ID, std::array<ButtonID_t, MAX_BUTTON_IDS> &list) {
	for(uint8_t i=0;i<MAX_BUTTON_IDS;i++) {
		if(list[i] == ID) {
			list[i] = 0;
		}
	}
}

static bool addToList(ButtonID_t ID,
		std::array<ButtonID_t, MAX_BUTTON_IDS> &list) {
	removeFromList(ID, list);
	for (uint8_t i = 0; i < MAX_BUTTON_IDS; i++) {
		if (list[i] == 0) {
			list[i] = ID;
			System::print("Added ID to list: %04x, spot %d\n", ID, i);
			return true;
		}
	}
	/* List already full */
	return false;
}


static inline char nibbleToHex(uint8_t n) {
	return n < 10 ? n + '0' : n - 10 + 'A';
}

static void StateMachine(void) {
	state = State::IDLE;

	/* Stay within state machine until off switch is pressed */
	while (OnOff.pressedFor() < 1000) {
		if(System::GetBatteryVoltage(true) < 3000) {
			/* Battery is low, abort */
			System::print("Battery voltage low: %lumV\n", System::GetBatteryVoltage(false));
			System::Shutdown(System::Error::BatteryLow);
		}

		/* Check for start/stop events */
		uint32_t startEvent = 0;
		uint32_t stopEvent = 0;
		ButtonID_t pressedID = 0;
		if (Start.shortPress()) {
			System::print("Start press\n");
			startEvent = Start.pressTime();
			Start.clear();
		} else if(Stop.shortPress()) {
			System::print("Stop press\n");
			stopEvent = Stop.pressTime();
			Stop.clear();
		} else if (radio.gotPacket()) {
			/* Evaluate radio packet */
			System::print("Radio packet received\n");
			RFM69::Packet packet = radio.getPacket();
			if (packet.length >= sizeof(RadioPacket)) {
				RadioPacket *received = (RadioPacket*) packet.data;
				if (received->type == PacketType::ButtonPress) {
					/* Some button was pressed */
					System::print("Button press: %04x\n", received->ID);
					/* Send ACK */
					RadioPacket ack = { .type = PacketType::Ack, .ID =
							received->ID };
					radio.send((uint8_t*) &ack, sizeof(RadioPacket));

					pressedID = received->ID;
					if(buttonInList(pressedID, IDs.startIDs)) {
						System::print("Start packet\n");
						startEvent = packet.receivedTimestamp - packet.sentTimestamp;
					} else if(buttonInList(pressedID, IDs.stopIDs)) {
						System::print("Stop packet\n");
						stopEvent = packet.receivedTimestamp - packet.sentTimestamp;
					}
				}
			}
		}

		switch(state) {
		case State::IDLE:
			if(HAL_GetTick() - displayChangeTime > displayDuration) {
				/* Clear old message from display */
				Display.clear();
			}
			if (startEvent) {
				startTime = startEvent;
				switchState(State::RUNNING);
			} else if(pressedID) {
				char hexID[4] = {
						nibbleToHex((pressedID & 0xF000) >> 12),
						nibbleToHex((pressedID & 0x0F00) >> 8),
						nibbleToHex((pressedID & 0x00F0) >> 4),
						nibbleToHex((pressedID & 0x000F) >> 0),
				};
				/* Got a button press, check if it should be added to some list */
				if (Start.pressedFor() > 500) {
					removeFromList(pressedID, IDs.stopIDs);
					if (addToList(pressedID, IDs.startIDs)) {
						Display.setString(hexID);
						setDisplayDuration(1500);
					} else {
						Display.setString("FULL");
						setDisplayDuration(1500);
					}
				} else if (Stop.pressedFor() > 500) {
					removeFromList(pressedID, IDs.startIDs);
					if (addToList(pressedID, IDs.stopIDs)) {
						Display.setString(hexID);
						setDisplayDuration(1500);
					} else {
						Display.setString("FULL");
						setDisplayDuration(1500);
					}
				}
			} else if(Highscore.shortPress()) {
				Highscore.clear();
				Display.setNumber(bestTime, 3);
				setDisplayDuration(3000);
			} else if(Highscore.pressedFor() >= 500) {
				Display.setString("DEL ");
				if(Highscore.pressedFor() < 3000) {
					/* Don't delete yet */
					Display.blink();
					setDisplayDuration(100);
				} else {
					/* Clear highscore */
					bestTime = UINT32_MAX;
					setDisplayDuration(2000);
				}
			} else if(Start.isPressed() && Stop.isPressed()) {
				Display.setString("DEL ");
				if(Start.pressedFor() < 3000 || Stop.pressedFor() < 3000) {
					/* Don't delete yet */
					Display.blink();
					setDisplayDuration(100);
				} else {
					/* Delete button assignments */
					IDs.startIDs.fill(0);
					IDs.stopIDs.fill(0);
					setDisplayDuration(2000);
				}
			}
			break;
		case State::RUNNING:
			Display.setNumber(HAL_GetTick() - startTime, 3);
			if (stopEvent) {
				stopTime = stopEvent;
				switchState(State::IDLE);
				uint32_t runTime = stopTime - startTime;
				Display.setNumber(runTime, 3);
				if(runTime < bestTime) {
					bestTime = runTime;
					Display.blink();
				}
				setDisplayDuration(5000);
			}
			break;
		}
	}
}

void App_Start()
{
	System::print("Application start\n");

	if (!radio.init()) {
		/* Failed to initialize radio */
		System::print("Radio initialization failed\n");
		System::Shutdown(System::Error::RadioInit);
	}
	System::print("Radio initialized\n");

	if(memory.available()) {
		System::print("Reading button IDs from memory...\n");
		IDs = memory.read();
#if 1
		System::print("StartIDs:");
		for (auto i = IDs.startIDs.begin(); i != IDs.startIDs.end(); i++) {
			if (*i)
				System::print(" %04x", *i);
		}
		System::print("\nStopIDs:");
		for (auto i = IDs.stopIDs.begin(); i != IDs.stopIDs.end(); i++) {
			if (*i)
				System::print(" %04x", *i);
		}
		System::print("\n");
#endif
	} else {
		System::print("No button ID information available\n");
		IDs.startIDs.fill(0);
		IDs.stopIDs.fill(0);
	}

	uint32_t battery = System::GetBatteryVoltage(true);
	uint32_t booster = System::GetBoosterVoltage(false);

	System::print("Battery: %lumV, Booster: %lumV\n", battery, booster);
	if(battery < 3300) {
		System::print("Shutting down due to low battery\n");
		System::Shutdown(System::Error::BatteryLow);
	}

	Display.setString("On  ");
	HAL_Delay(1000);

	radio.setMode(RFM69::Mode::Receive);

	/* Stopwatch application */
	StateMachine();

	/* If button assignment has changed, store in Flash */
	auto memIDs = memory.read();
	if (!memory.available() || memIDs.startIDs != IDs.startIDs
			|| memIDs.stopIDs != IDs.stopIDs) {
		System::print("Writing button IDs to flash\n");
		memory.write(IDs);
	}

	Display.setString("OFF ");
	HAL_Delay(1000);
	System::Shutdown();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	switch (GPIO_Pin) {
	case GPIO_PIN_12:
		radio.onDIO0();
		break;
	}
}

void HAL_SYSTICK_Callback(void) {
	OnOff.update();
	Start.update();
	Stop.update();
	Highscore.update();

	constexpr uint8_t displayUpdatePeriod = 2;
	static uint8_t displayUpdateCnt = 0;
	if (displayUpdateCnt == 0) {
		Display.update();
		displayUpdateCnt = displayUpdatePeriod;
	} else {
		displayUpdateCnt--;
	}
}
