/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "mx.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
void MX_GPIO_PE11_Init(void);
void MX_GPIO_PC13_Init(void);
void MX_GPIO_PB15_Init(void);
void MX_GPIO_PE8_Init(void);
void MX_GPIO_PE6_Init(void);
void MX_GPIO_PF2_Init(void);
void MX_GPIO_PA4_Init(void);
void MX_GPIO_PI0_Init(void);
void MX_GPIO_PI7_Init(void);
void MX_GPIO_PI5_Init(void);

void MX_GPIO_PF9_Init(void);
void MX_GPIO_PF3_Init(void);
void MX_GPIO_PH6_Init(void);
void MX_GPIO_PB8_Init(void);
void MX_GPIO_PF4_Init(void);
void MX_GPIO_PH15_Init(void);
void MX_GPIO_PF12_Init(void);
void MX_GPIO_PF15_Init(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

