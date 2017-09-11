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

void BoosterON(bool enable);

uint16_t GetBatteryVoltage(bool forceUpdate);
uint16_t GetBoosterVoltage(bool forceUpdate);

}

