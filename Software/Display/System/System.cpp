#include "System.h"
#include "stm32f0xx_hal.h"
#include "main.h"

extern ADC_HandleTypeDef hadc;
extern DMA_HandleTypeDef hdma_adc;

namespace System {

static uint16_t battery, booster;

static void sampleADC() {
	constexpr uint16_t samples = 16;
	uint16_t buffer[samples * 2];
	HAL_ADC_Start_DMA(&hadc, (uint32_t*) buffer, samples * 2);
	/* wait for ADC sampling to finish */
	while (HAL_DMA_GetState(&hdma_adc) & HAL_DMA_STATE_BUSY)
		;

	/* Calculate average */
	uint32_t avgBat = 0;
	uint32_t avgBoost = 0;
	uint8_t i;
	for (i = 0; i < samples * 2; i += 2) {
		avgBat += buffer[i];
		avgBoost += buffer[i + 1];
	}
	avgBat /= samples;
	avgBoost /= samples;

	/* Convert to voltage */
	/* Reference is 3V, battery voltage sensed via 1:2 voltage divider */
	battery = avgBat * 6000UL / 4096;
	/* Reference is 3V, battery voltage sensed via 1:5.7 voltage divider */
	booster = avgBoost * 17100 / 4096;
}

void Shutdown() {
	/* Wait for the button to be released */
	while (!HAL_GPIO_ReadPin(SWITCH_ONOFF_GPIO_Port, SWITCH_ONOFF_Pin))
		;

	while (1) {
		/* Cut power to itself */
		HAL_GPIO_WritePin(DISABLE_GPIO_Port, DISABLE_Pin, GPIO_PIN_SET);

		HAL_Delay(1000);
		/* We should never get here, as power should be already lost */
		/* Enable power again to reliably blink error code */
		HAL_GPIO_WritePin(DISABLE_GPIO_Port, DISABLE_Pin, GPIO_PIN_RESET);
	}
}

void Shutdown(Error error) {
	Shutdown();
}

void BoosterON(bool enable) {
	if(enable) {
		BOOST_ENABLE_GPIO_Port->BSRR |= BOOST_ENABLE_Pin;
	} else {
		BOOST_ENABLE_GPIO_Port->BRR |= BOOST_ENABLE_Pin;
	}
}

uint16_t GetBatteryVoltage(bool forceUpdate) {
	if(forceUpdate)
		sampleADC();
	return battery;
}

uint16_t GetBoosterVoltage(bool forceUpdate) {
	if(forceUpdate)
		sampleADC();
	return booster;
}

}
