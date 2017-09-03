#ifndef HAL_SWITCHES_H_
#define HAL_SWITCHES_H_

#include <stdint.h>

typedef struct {
	uint32_t changeTimestamp;
	uint8_t pressed;
	uint8_t pressCount;
	uint32_t lastPressLength;
} SwitchState_t;

typedef enum {
	SWITCH_START = 0x00,
	SWITCH_STOP = 0x01,
	SWITCH_OFF = 0x02,
} Switch_t;

void Switches_Init(void);

void Switches_Update(void);

/**
 * @brief Checks whether a switch is currently pressed
 *
 * @param s Status of the switch to check
 * @return Time in ms since the switch was pressed, 0 if not pressed
 */
uint32_t Switch_Pressed(Switch_t s);

/**
 * @brief Checks whether a switch was clicked
 *
 * Sideeffect: Clears the 'switch clicked'-event, e.g.
 *
 * @param s Status of the switch to check
 * @return Time in ms the switch was pressed for, 0 if it has not been clicked
 */
uint32_t Switch_Clicked(Switch_t s);

#endif /* HAL_SWITCHES_H_ */
