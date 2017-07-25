#include "radio.h"

#define RADIO_NUM_DRIVERS	0

radio_driver_t *radio = NULL;

radio_driver_t * const driverList[RADIO_NUM_DRIVERS] = {
		/* Add additional radio drivers here */
};

int Radio_Init() {
	uint8_t i;
	/* Search all drivers for an available radio,
	 * the first radio found will be used */
	for (i = 0; i < RADIO_NUM_DRIVERS; i++) {
		if (!driverList[i]->initHard()) {
			/* Hardware initialization for this radio failed */
			continue;
		}
		if (!driverList[i]->check()) {
			/* This radio is not available */
			continue;
		}
		if (!driverList[i]->initSoft()) {
			/* Software initialization for this radio failed */
			continue;
		}
		/* Found a radio and initialized it */
		radio = driverList[i];
		return i;
	}
	/* No radio available */
	return -1;
}
