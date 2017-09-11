#pragma once

#include <cstdint>

namespace System {

enum class Error : uint8_t {
		BatteryLow = 2,
		RadioInit = 3,
		NoAck = 4,
		Turnoff = 5,
};

void Shutdown();

void Shutdown(Error error);

uint16_t GetBatteryVoltage();

}

