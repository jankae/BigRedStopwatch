#ifndef RADIO_RADIO_H_
#define RADIO_RADIO_H_

#include <stdint.h>
#include <string.h>

typedef struct {
	/** Initializes hardware interface to the radio */
	int (*initHard) (void);
	/** Checks if the radio is available */
	int (*check) (void);
	/** Initializes the radio (set registers...) */
	int (*initSoft) (void);
	/** Send a datapacket via the radio */
	int (*send) (uint8_t *payload, uint16_t length);
	/** Set this to the callback function handling received radio packets */
	void (*received) (uint8_t *payload, uint16_t length);
} radio_driver_t;

/*
 * Use this struct to access the radio once it is initialized.
 * Packets can be sent with radio->send. To receive packets,
 * the function pointer radio->received must be set by the
 * application
 */
radio_driver_t *radio = NULL;

/**
 * @brief Initializes the connected radio
 *
 * Attempts to initialize the radio using all available drivers.
 * First successfully initialized radio will be used.
 *
 * @return Number of the used driver (-1 on failure)
 */
int Radio_Init();

#endif /* RADIO_RADIO_H_ */
