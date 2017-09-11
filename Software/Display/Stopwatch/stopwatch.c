#include "stopwatch.h"
#include <stdint.h>

#include "radio.h"

//#include "../System/Switches.h"

#define HISTORY_ENTRIES		10

uint8_t historyLength;
uint32_t history[HISTORY_ENTRIES];

uint32_t fastest;

typedef enum {
	WATCH_READY,			/* Currently awaiting start signal */
	WATCH_RUNNING,			/* Start signal received, waiting for stop signal */
	WATCH_BLOCKED,			/* Received stop, display time, NO immediate reaction to start signals */
	WATCH_DISPLAY,			/* Still displaying time, transition to running if start is received */
} Stopwatch_state_t;

typedef enum {
	EVENT_START,
	EVENT_STOP,
} Event_t;

Stopwatch_state_t state;
uint32_t transitionTimestamp;

static void receivedData(uint8_t *payload, uint16_t length) {

}

static uint32_t eventOccured(Event_t event)
{
	switch(event)
	{
	}
}

static void resetHistory(void) {
	/* Clear all history */
	historyLength = 0;
	/* Reset the fastest time */
	fastest = UINT32_MAX;
}

int Stopwatch_Init() {
	if (radio) {
		/* Set the receive callback */
		radio->received = receivedData;
	}
	state = WATCH_READY;
	resetHistory();

	return 0;
}

void Stopwatch() {
	while(1) {
		switch(state) {
		case WATCH_READY:
			break;
		case WATCH_RUNNING:
			break;
		case WATCH_BLOCKED:
			break;
		case WATCH_DISPLAY:
			break;
		}
	}
}
