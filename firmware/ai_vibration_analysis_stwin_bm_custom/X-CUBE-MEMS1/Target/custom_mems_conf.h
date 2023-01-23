/**
  ******************************************************************************
  * @file    custom_mems_conf.h
  * @author  MEMS Application Team
  * @brief   This file contains definitions of the MEMS components bus interfaces for custom boards
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CUSTOM_MEMS_CONF_H__
#define __CUSTOM_MEMS_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "steval_stwinkt1b_bus.h"
#include "steval_stwinkt1b_errno.h"

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

#define USE_CUSTOM_MOTION_SENSOR_ISM330DHCX_0     1U

#define CUSTOM_ISM330DHCX_0_SPI_Init BSP_SPI3_Init
#define CUSTOM_ISM330DHCX_0_SPI_DeInit BSP_SPI3_DeInit
#define CUSTOM_ISM330DHCX_0_SPI_Send BSP_SPI3_Send
#define CUSTOM_ISM330DHCX_0_SPI_Recv BSP_SPI3_Recv

#define CUSTOM_ISM330DHCX_0_CS_PORT GPIOF
#define CUSTOM_ISM330DHCX_0_CS_PIN GPIO_PIN_13

#ifdef __cplusplus
}
#endif

#endif /* __CUSTOM_MEMS_CONF_H__*/
