#pragma once

#include <cstdint>

namespace System {

enum class Error : uint8_t {
		None = 1,
		BatteryLow = 2,
		RadioInit = 3,
		NoAck = 4,
		Turnoff = 5,
};

void Shutdown();

void Shutdown(Error error);

uint16_t GetBatteryVoltage();

void print(const char *fmt, ...);

}

