/**
  ******************************************************************************
  * @file    app_mems_int_pin_a_interface.c
  * @author  MEMS Application Team
  * @brief   This file contains the MEMS INT pin A interface
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

/* Includes ------------------------------------------------------------------*/

#include "stdio.h"

extern volatile uint8_t MemsEventDetected;

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
	MemsEventDetected = 1;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	MemsEventDetected = 1;
}
