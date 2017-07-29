/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define DIGIT1_Pin GPIO_PIN_13
#define DIGIT1_GPIO_Port GPIOC
#define DIGIT2_Pin GPIO_PIN_14
#define DIGIT2_GPIO_Port GPIOC
#define DIGIT3_Pin GPIO_PIN_15
#define DIGIT3_GPIO_Port GPIOC
#define BATTERY_Pin GPIO_PIN_0
#define BATTERY_GPIO_Port GPIOA
#define SEGMENT_G_Pin GPIO_PIN_1
#define SEGMENT_G_GPIO_Port GPIOA
#define SEGMENT_F_Pin GPIO_PIN_2
#define SEGMENT_F_GPIO_Port GPIOA
#define SEGMENT_A_Pin GPIO_PIN_3
#define SEGMENT_A_GPIO_Port GPIOA
#define SEGMENT_B_Pin GPIO_PIN_4
#define SEGMENT_B_GPIO_Port GPIOA
#define SWITCH1_Pin GPIO_PIN_5
#define SWITCH1_GPIO_Port GPIOA
#define SWITCH2_Pin GPIO_PIN_6
#define SWITCH2_GPIO_Port GPIOA
#define SWITCH3_Pin GPIO_PIN_7
#define SWITCH3_GPIO_Port GPIOA
#define SEGMENT_DOT_Pin GPIO_PIN_1
#define SEGMENT_DOT_GPIO_Port GPIOB
#define SEGMENT_C_Pin GPIO_PIN_2
#define SEGMENT_C_GPIO_Port GPIOB
#define SEGMENT_D_Pin GPIO_PIN_10
#define SEGMENT_D_GPIO_Port GPIOB
#define SEGMENT_E_Pin GPIO_PIN_11
#define SEGMENT_E_GPIO_Port GPIOB
#define RFM69_DIO0_Pin GPIO_PIN_12
#define RFM69_DIO0_GPIO_Port GPIOB
#define RFM69_DIO1_Pin GPIO_PIN_13
#define RFM69_DIO1_GPIO_Port GPIOB
#define RFM69_DIO2_Pin GPIO_PIN_14
#define RFM69_DIO2_GPIO_Port GPIOB
#define RFM69_DIO3_Pin GPIO_PIN_15
#define RFM69_DIO3_GPIO_Port GPIOB
#define RFM69_DIO4_Pin GPIO_PIN_8
#define RFM69_DIO4_GPIO_Port GPIOA
#define RFM69_DIO5_Pin GPIO_PIN_9
#define RFM69_DIO5_GPIO_Port GPIOA
#define CS_NRF24_Pin GPIO_PIN_10
#define CS_NRF24_GPIO_Port GPIOA
#define NRF24_CE_Pin GPIO_PIN_11
#define NRF24_CE_GPIO_Port GPIOA
#define NRF24_IRQ_Pin GPIO_PIN_12
#define NRF24_IRQ_GPIO_Port GPIOA
#define CS_RFM69_Pin GPIO_PIN_7
#define CS_RFM69_GPIO_Port GPIOF
#define DIGIT4_Pin GPIO_PIN_9
#define DIGIT4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
