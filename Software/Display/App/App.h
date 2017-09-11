

#ifndef SRC_APP_H_
#define SRC_APP_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void App_Start();

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_SYSTICK_Callback(void);

#ifdef __cplusplus
}
#endif

#endif /* SRC_APP_H_ */
