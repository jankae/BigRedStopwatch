#include "../Hal/Display.h"

#include "main.h"
#include "gpio.h"
#include <string.h>

#define DISPLAY_NUM_DIGITS		4

static GPIO_TypeDef * const Segment_GPIO[8] = {
		SEGMENT_A_GPIO_Port,
		SEGMENT_B_GPIO_Port,
		SEGMENT_C_GPIO_Port,
		SEGMENT_D_GPIO_Port,
		SEGMENT_E_GPIO_Port,
		SEGMENT_F_GPIO_Port,
		SEGMENT_G_GPIO_Port,
		SEGMENT_DOT_GPIO_Port
};

static const uint32_t Segment_Pins[8] = {
	SEGMENT_A_Pin,
	SEGMENT_B_Pin,
	SEGMENT_C_Pin,
	SEGMENT_D_Pin,
	SEGMENT_E_Pin,
	SEGMENT_F_Pin,
	SEGMENT_G_Pin,
	SEGMENT_DOT_Pin
};

static GPIO_TypeDef * const Digit_GPIO[DISPLAY_NUM_DIGITS] = {
		DIGIT1_GPIO_Port,
		DIGIT2_GPIO_Port,
		DIGIT3_GPIO_Port,
		DIGIT4_GPIO_Port
};

static const uint32_t Digit_Pins[DISPLAY_NUM_DIGITS] = {
		DIGIT1_Pin,
		DIGIT2_Pin,
		DIGIT3_Pin,
		DIGIT4_Pin
};

static const uint8_t fontAlphabetical[26] = {
		0x77,				/* A */
		0x7C,				/* B */
		0x39,				/* C */
		0x7E,				/* D */
		0x79,				/* E */
		0x71,				/* F */
		0x3D,				/* G */
		0x76,				/* H */
		0x30,				/* I */
		0x1E,				/* J */
		0x00,				/* K */
		0x38,				/* L */
		0x00,				/* M */
		0x00,				/* N */
		0x7C,				/* O */
		0x73,				/* P */
		0x00,				/* Q */
		0x70,				/* R */
		0x6D,				/* S */
		0x78,				/* T */
		0x3E,				/* U */
		0x00,				/* V */
		0x00,				/* W */
		0x00,				/* X */
		0x6E,				/* Y */
		0x1B,				/* Z */
};

static const uint8_t fontNumbers[10] = {
		0xCF,				/* 0 */
		0x06,				/* 1 */
		0x1B,				/* 2 */
		0x4F,				/* 3 */
		0x66,				/* 4 */
		0x6D,				/* 5 */
		0x7D,				/* 6 */
		0x07,				/* 7 */
		0x7F,				/* 8 */
		0x6F,				/* 9 */
};


/* Active segments */
static uint8_t screen[4];
static uint8_t currentDigit = 0;

static inline void allDigitsOff(void) {
	uint8_t i;
	for (i = 0; i < DISPLAY_NUM_DIGITS; i++) {
		/* deactivate all digits */
		Digit_GPIO[i]->BRR |= Digit_Pins[i];
	}
}

void Display_Init(void) {
	currentDigit = 0;
	memset(screen, 0, sizeof(screen));
	allDigitsOff();
}

void Display_SetScreen(char *s) {
	uint8_t i;
	for (i = 0; i < DISPLAY_NUM_DIGITS; i++) {
		if (*s >= '0' && *s <= '9') {
			/* It is a digit */
			screen[i] = fontNumbers[*s - '0'];
		} else if (*s >= 'A' && *s <= 'Z') {
			/* It is an upper case digit */
			screen[i] = fontAlphabetical[*s - 'A'];
		} else if (*s >= 'a' && *s <= 'z') {
			/* It is an lower case digit */
			screen[i] = fontAlphabetical[*s - 'a'];
		} else {
			/* no segment configuration for this character */
			screen[i] = 0x00;
		}
		s++;
	}
}

void Display_SetNumber(uint32_t num) {
	uint8_t dot;
	uint16_t divider;
	/* Find dot position */
	if (num >= 10000000) {
		/* number is too big to be displayed */
		memset(screen, fontNumbers[9], sizeof(screen));
		return;
	} else if (num >= 1000000) {
		/* No dot */
		dot = 0;
		divider = 1000;
	} else if (num >= 100000) {
		dot = 1;
		divider = 100;
	} else if (num >= 10000) {
		dot = 2;
		divider = 10;
	} else {
		dot = 3;
		divider = 1;
	}
	num /= divider;
	screen[0] = fontNumbers[num / 1000];
	screen[1] = fontNumbers[(num / 100) % 10];
	screen[2] = fontNumbers[(num / 10) % 10];
	screen[3] = fontNumbers[num % 10];
	if (dot) {
		/* Add dot at the dot position */
		screen[dot] |= 0x80;
	}
}

void Display_Update(void) {
	allDigitsOff();
	currentDigit++;
	if (currentDigit >= DISPLAY_NUM_DIGITS) {
		currentDigit = 0;
	}
	/* Set segments to the next digit */
	uint8_t i;
	for (i = 0; i < 8; i++) {
		if (screen[currentDigit] & (1 << i)) {
			/* this digit is on */
			Segment_GPIO[i]->BSRR |= Segment_Pins[i];
		} else {
			/* this digit is off */
			Segment_GPIO[i]->BRR |= Segment_Pins[i];
		}
	}
	/* Enable the new digit */
	Digit_GPIO[currentDigit]->BSRR |= Digit_Pins[currentDigit];
}
