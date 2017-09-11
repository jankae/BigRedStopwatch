#include "App.h"

#include <cstdlib>
#include "RFM69.h"
#include "stm32f0xx_hal.h"
#include "System.h"
#include "Switches.h"
#include "SevenSegment.h"

extern SPI_HandleTypeDef hspi1;

RFM69 radio = RFM69(&hspi1, CS_RFM69_GPIO_Port, CS_RFM69_Pin);

System::Switch SwitchOnOff(SWITCH_ONOFF_GPIO_Port, SWITCH_ONOFF_Pin);
System::Switch SwitchStart(SWITCH1_GPIO_Port, SWITCH1_Pin);
System::Switch SwitchStop(SWITCH2_GPIO_Port, SWITCH2_Pin);
System::Switch SwitchHistory(SWITCH3_GPIO_Port, SWITCH3_Pin);

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

enum class PacketType : uint8_t {
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
		System::Shutdown(System::Error::RadioInit);
	}

	radio.setMode(RFM69::Mode::Receive);

	if(System::GetBatteryVoltage(true) < 3500) {
		/* Battery is low, abort */
		System::Shutdown(System::Error::BatteryLow);
	}

	System::BoosterON(true);
	Display.setString("TEST");
	HAL_Delay(3000);
	System::BoosterON(false);

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
	SwitchOnOff.update();
	SwitchStart.update();
	SwitchStop.update();
	SwitchHistory.update();

	constexpr uint8_t displayUpdatePeriod = 2;
	static uint8_t displayUpdateCnt = 0;
	if (displayUpdateCnt == 0) {
		Display.update();
		displayUpdateCnt = displayUpdatePeriod;
	} else {
		displayUpdateCnt--;
	}
}
