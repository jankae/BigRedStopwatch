#ifndef DISPLAY_DISPLAY_H_
#define DISPLAY_DISPLAY_H_

#include <stdint.h>

void Display_Init(void);

void Display_SetScreen(char *s);

void Display_SetNumber(uint32_t num);

void Display_Update(void);

#endif /* DISPLAY_DISPLAY_H_ */
