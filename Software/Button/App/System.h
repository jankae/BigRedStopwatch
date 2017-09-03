#pragma once

#include <cstdint>

enum ErrorCode : uint8_t {
		ErrBatteryLow = 2,
		ErrRadioInit = 3,
		ErrNoAck = 4,
		ErrTurnoff = 5,
};

void Shutdown();

void Shutdown(ErrorCode errorCode);

uint16_t getBatteryVoltage();

