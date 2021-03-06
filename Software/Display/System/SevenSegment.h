#pragma once

#include <array>
#include "gpio.h"
#include "System.h"
#include <cmath>

namespace System {

template <uint8_t digits>
class SevenSegment {
public:
	constexpr SevenSegment(std::array<GPIO_TypeDef*, 8> sports,
			std::array<uint16_t, 8> spins,
			std::array<GPIO_TypeDef*, digits> cports,
			std::array<uint16_t, digits> cpins)
	: segmentPorts(sports)
	, segmentPins(spins)
	, commonPorts(cports)
	, commonPins(cpins)
	, segmentState()
	, activeSegment(0)
	, blinking(false)
	{};

	void update(void) {
		/* Disable the old digit */
		commonPorts[activeSegment]->BRR |= commonPins[activeSegment];

		activeSegment++;
		if (activeSegment >= digits) {
			activeSegment = 0;
		}
		/* Set segments to the next digit */
		uint8_t i;
		for (i = 0; i < 8; i++) {
			if (segmentState[activeSegment] & (1 << i)) {
				/* this digit is on */
				segmentPorts[i]->BSRR |= segmentPins[i];
			} else {
				/* this digit is off */
				segmentPorts[i]->BRR |= segmentPins[i];
			}
		}
		if (!blinking || HAL_GetTick() % blinkPeriod >= blinkPeriod / 2) {
			/* Enable the new digit */
			commonPorts[activeSegment]->BSRR |= commonPins[activeSegment];
		}
	}
	void clear() {
		segmentState.fill(0x00);
		System::BoosterON(false);
	}
	void setString(const char *s) {
		uint8_t i;
		for (i = 0; i < digits; i++) {
			uint8_t d = digits - i - 1;
			if (s[i] >= '0' && s[i] <= '9') {
				/* It is a digit */
				segmentState[d] = fontNumbers[s[i] - '0'];
			} else if (s[i] >= 'A' && s[i] <= 'Z') {
				/* It is an upper case digit */
				segmentState[d] = fontAlphabetical[s[i] - 'A'];
			} else if (s[i] >= 'a' && s[i] <= 'z') {
				/* It is an lower case digit */
				segmentState[d] = fontAlphabetical[s[i] - 'a'];
			} else {
				/* no segment configuration for this character */
				segmentState[d] = 0x00;
			}
		}
		blinking = false;
		System::BoosterON(true);
	}
	void setNumber(uint32_t num, uint8_t decimalDigits) {
		std::array<uint8_t, digits> lSegments;
		/* Find dot position */
		constexpr uint32_t digitlimit = pow(10, digits);
		uint32_t limit = digitlimit;
		uint8_t d = decimalDigits;
		while (d--)
			limit *= 10;
		if (num >= limit) {
			/* number is too big to be displayed */
			segmentState.fill(fontNumbers[9]);
			return;
		}

		while (num >= digitlimit) {
			decimalDigits--;
			num /= 10;
		}

		for (uint8_t i = 0; i < digits; i++) {
			lSegments[i] = fontNumbers[num % 10];
			num /= 10;
		}

		if (decimalDigits) {
			/* Add dot at the dot position */
			lSegments[decimalDigits] |= 0x80;
		}
		segmentState = lSegments;
		blinking = false;
		System::BoosterON(true);
	}
	void blink(void) {
		blinking = true;
	}
private:
	static constexpr uint32_t blinkPeriod = 500;
	const std::array<GPIO_TypeDef*, 8> segmentPorts;
	const std::array<uint16_t, 8> segmentPins;
	const std::array<GPIO_TypeDef*, digits> commonPorts;
	const std::array<uint16_t, digits> commonPins;
	std::array<uint8_t, digits> segmentState;
	uint8_t activeSegment;
	bool blinking;

	static const uint8_t fontAlphabetical[26];
	static const uint8_t fontNumbers[10];
};

template<uint8_t digits> constexpr uint8_t SevenSegment<digits>::fontAlphabetical[] = {
		0x77,				/* A */
		0x7C,				/* B */
		0x39,				/* C */
		0x7C,				/* D */
		0x79,				/* E */
		0x71,				/* F */
		0x3D,				/* G */
		0x76,				/* H */
		0x30,				/* I */
		0x1E,				/* J */
		0x00,				/* K */
		0x38,				/* L */
		0x00,				/* M */
		0x54,				/* N */
		0x5C,				/* O */
		0x73,				/* P */
		0x67,				/* Q */
		0x50,				/* R */
		0x6D,				/* S */
		0x78,				/* T */
		0x3E,				/* U */
		0x00,				/* V */
		0x00,				/* W */
		0x00,				/* X */
		0x6E,				/* Y */
		0x5B,				/* Z */
};

template<uint8_t digits> constexpr uint8_t SevenSegment<digits>::fontNumbers[] = {
		0x3F,				/* 0 */
		0x06,				/* 1 */
		0x5B,				/* 2 */
		0x4F,				/* 3 */
		0x66,				/* 4 */
		0x6D,				/* 5 */
		0x7D,				/* 6 */
		0x07,				/* 7 */
		0x7F,				/* 8 */
		0x6F,				/* 9 */
};

}
