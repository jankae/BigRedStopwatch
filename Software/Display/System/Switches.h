#pragma once

#include <cstdint>
#include "stm32f0xx_hal.h"

namespace System {

class Switch {
public:
	constexpr Switch(GPIO_TypeDef* port, uint16_t pin)
	: port(port)
	, pin(pin)
	, pressed(false)
	, pressedSince(0)
	, lastPressedFor(0)
	, pressCnt(0)
	{};

	void update(void);
	bool isPressed(void);
	bool wasPressed(void);
	uint32_t pressedFor(void);
	uint32_t wasPressedFor(void);
private:
	const GPIO_TypeDef* port;
	const uint16_t pin;

	bool pressed;
	uint32_t pressedSince;
	uint32_t lastPressedFor;
	uint8_t pressCnt;
};

}
