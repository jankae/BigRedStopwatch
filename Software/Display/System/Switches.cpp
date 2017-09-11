#include "Switches.h"

namespace System {

void Switch::update(void) {
	if (port->IDR & pin) {
		if (pressCnt) {
			pressCnt--;
		}
	} else {
		// TODO adjust debouncing constant here
		pressCnt = 10;
	}
	if (pressed && !pressCnt) {
		/* Was pressed, now not anymore */
		pressed = false;
		lastPressedFor = HAL_GetTick() - pressedSince;
	} else if (!pressed && pressCnt) {
		/* Was not pressed, is now */
		pressed = true;
		pressedSince = HAL_GetTick();
	}
}

bool Switch::isPressed(void) {
	return pressed;
}

bool Switch::wasPressed(void) {
	return lastPressedFor > 0 ? true : false;
}

uint32_t Switch::pressedFor(void) {
	if (pressed) {
		return HAL_GetTick() - pressedSince;
	} else {
		return 0;
	}
}

uint32_t Switch::wasPressedFor(void) {
	return lastPressedFor;
}

}
