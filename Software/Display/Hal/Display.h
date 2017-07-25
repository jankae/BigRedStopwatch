#ifndef HAL_DISPLAY_H_
#define HAL_DISPLAY_H_

#include <stdint.h>

/**
 * @brief Initializes the display with all elements turned off
 */
void Display_Init(void);

/**
 * @brief Writes a given screen to the display.
 *
 * If a character can't be displayed due to 7-segment limitations,
 * its space will be left blank
 *
 * @param s String to display, MUST always be of length 4
 */
void Display_SetScreen(char *s);

/**
 * @brief Displays a number on the display
 *
 * This function expects fixed point numbers with 3 digits
 * after the decimal point. E.g. passing 1234 will result
 * in 1.234 being displayed.
 *
 * @param num The number to display
 */
void Display_SetNumber(uint32_t num);

/**
 * @brief Switched the multiplexed display to the next digit.
 *
 * This function must be called regularly from a timer interrupt.
 */
void Display_Update(void);

#endif /* HAL_DISPLAY_H_ */
