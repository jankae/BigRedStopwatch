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
		lastPressedFor = 0;
	}
}

bool Switch::isPressed(void) {
	return pressed;
}

bool Switch::wasPressed(void) {
	return lastPressedFor > 0 ? true : false;
}

bool Switch::shortPress(void) {
	if(lastPressedFor > 0 && lastPressedFor < 500) {
		return true;
	} else {
		return false;
	}
}

bool Switch::longPress(void) {
	if(lastPressedFor > 500) {
		clear();
		return true;
	} else {
		return false;
	}
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

void Switch::clear(void) {
	lastPressedFor = 0;
}

uint32_t Switch::pressTime(void) {
	if(pressed || lastPressedFor > 0) {
		return pressedSince;
	} else {
		return 0;
	}
}

uint32_t Switch::releaseTime(void) {
	if(lastPressedFor > 0) {
		return pressedSince + lastPressedFor;
	} else {
		return 0;
	}
}

}

