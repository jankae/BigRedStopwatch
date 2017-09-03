#include "Switches.h"

#include <string.h>
#include "stm32f0xx_hal.h"

#define SWITCHES_NUM			3

SwitchState_t switches[SWITCHES_NUM];

static GPIO_TypeDef * const Switch_GPIO[SWITCHES_NUM] = {
		SWITCH1_GPIO_Port,
		SWITCH2_GPIO_Port,
		SWITCH3_GPIO_Port
};

static const uint32_t Switch_Pins[SWITCHES_NUM] = {
	SWITCH1_Pin,
	SWITCH2_Pin,
	SWITCH3_Pin
};

void Switches_Init(void) {
	memset(switches, 0, sizeof(switches));
}

void Switches_Update(void) {
	uint8_t i;
	for (i = 0; i < SWITCHES_NUM; i++) {
		if (Switch_GPIO[i]->IDR & Switch_Pins[i]) {
			/* Pin is high -> Switch is not pressed */
			if (switches[i].pressCount) {
				switches[i].pressCount--;
			}
		} else {
			/* Pin is low -> Switch is pressed */
			switches[i].pressCount = 10; // TODO adjust debouncing constant here
		}
		if (switches[i].pressed && !switches[i].pressCount) {
			/* Switch is marked as pressed and is now released */
			switches[i].pressed = 0;
			switches[i].lastPressLength = HAL_GetTick()
					- switches[i].changeTimestamp;
			switches[i].changeTimestamp = HAL_GetTick();
		} else if(!switches[i].pressed && switches[i].pressCount) {
			/* Switch is marked as released and is now pressed */
			switches[i].pressed = 1;
			switches[i].lastPressLength = 0;
			switches[i].changeTimestamp = HAL_GetTick();
		}
	}
}

/**
 * @brief Checks whether a switch is currently pressed
 *
 * @param s Status of the switch to check
 * @return Time in ms since the switch was pressed, 0 if not pressed
 */
uint32_t Switch_Pressed(Switch_t s) {
	if (switches[s].pressed) {
		/* calculate the time */
		return HAL_GetTick() - switches[s].changeTimestamp;
	} else {
		/* currently not pressed */
		return 0;
	}
}

/**
 * @brief Checks whether a switch was clicked
 *
 * @param s Status of the switch to check
 * @return Time in ms the switch was pressed for, 0 if it has not been clicked
 */
uint32_t Switch_Clicked(Switch_t s) {
	uint32_t buf = switches[s].lastPressLength;
	switches[s].lastPressLength = 0;
	return buf;
}
