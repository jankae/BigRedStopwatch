#include "System.h"
#include "stm32f0xx_hal.h"
#include <cstdarg>

extern ADC_HandleTypeDef hadc;
extern DMA_HandleTypeDef hdma_adc;
extern UART_HandleTypeDef huart1;

namespace System {

static void blinkErrorLED(Error error) {
	uint8_t blinks = (uint8_t) error;
	while(blinks--) {
		HAL_GPIO_WritePin(ERROR_LED_GPIO_Port, ERROR_LED_Pin, GPIO_PIN_SET);
		HAL_Delay(200);
		HAL_GPIO_WritePin(ERROR_LED_GPIO_Port, ERROR_LED_Pin, GPIO_PIN_RESET);
		HAL_Delay(300);
	}
}

void Shutdown() {
	print("Shutting down...\n");
	/* Wait for the button to be released */
	while (!HAL_GPIO_ReadPin(SWITCH_GPIO_Port, SWITCH_Pin))
		;

	while (1) {
		/* Cut power to itself */
		HAL_GPIO_WritePin(DISABLE_GPIO_Port, DISABLE_Pin, GPIO_PIN_RESET);

		HAL_Delay(1000);
		/* We should never get here, as power should be already lost */
		/* Enable power again to reliably blink error code */
		HAL_GPIO_WritePin(DISABLE_GPIO_Port, DISABLE_Pin, GPIO_PIN_SET);
		blinkErrorLED(Error::Turnoff);
	}
}

void Shutdown(Error error) {
	blinkErrorLED(error);
	Shutdown();
}

uint16_t GetBatteryVoltage() {
	constexpr uint16_t samples = 16;
	uint16_t buffer[samples];
	HAL_ADC_Start_DMA(&hadc, (uint32_t*) buffer, samples);
	/* wait for ADC sampling to finish */
	while(HAL_DMA_GetState(&hdma_adc) & HAL_DMA_STATE_BUSY);

	/* Calculate average */
	uint32_t avg = 0;
	uint8_t i;
	for(i=0;i<samples;i++) {
		avg += buffer[i];
	}
	avg /= samples;

	/* Convert to voltage */
	/* Reference is 3V, battery voltage sensed via 1:2 voltage divider */
	return avg * 6000UL / 4096;
}

void print(const char *fmt, ...) {
#if DEBUG
	char buffer[100];

	va_list arp;
	va_start(arp, fmt);
	uint16_t length = vsnprintf(buffer, sizeof(buffer), fmt, arp);
	va_end(arp);

	HAL_UART_Transmit(&huart1, (uint8_t*) buffer, length, 1000);
#endif
}

}
