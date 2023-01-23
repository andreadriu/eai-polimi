/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : steval_stwinkt1b_bus.h
  * @brief          : header file for the BSP BUS IO driver
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STEVAL_STWINKT1B_BUS_H
#define STEVAL_STWINKT1B_BUS_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "steval_stwinkt1b_conf.h"
#include "steval_stwinkt1b_errno.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STEVAL_STWINKT1B
  * @{
  */

/** @defgroup STEVAL_STWINKT1B_BUS STEVAL_STWINKT1B BUS
  * @{
  */

/** @defgroup STEVAL_STWINKT1B_BUS_Exported_Constants STEVAL_STWINKT1B BUS Exported Constants
  * @{
  */

#define BUS_SPI3_INSTANCE SPI3
#define BUS_SPI3_MISO_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_SPI3_MISO_GPIO_PIN GPIO_PIN_4
#define BUS_SPI3_MISO_GPIO_PORT GPIOB
#define BUS_SPI3_MISO_GPIO_CLK_DISABLE() __HAL_RCC_GPIOB_CLK_DISABLE()
#define BUS_SPI3_MISO_GPIO_AF GPIO_AF6_SPI3
#define BUS_SPI3_MOSI_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_SPI3_MOSI_GPIO_AF GPIO_AF6_SPI3
#define BUS_SPI3_MOSI_GPIO_PORT GPIOB
#define BUS_SPI3_MOSI_GPIO_PIN GPIO_PIN_5
#define BUS_SPI3_MOSI_GPIO_CLK_DISABLE() __HAL_RCC_GPIOB_CLK_DISABLE()
#define BUS_SPI3_SCK_GPIO_PORT GPIOB
#define BUS_SPI3_SCK_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_SPI3_SCK_GPIO_CLK_DISABLE() __HAL_RCC_GPIOB_CLK_DISABLE()
#define BUS_SPI3_SCK_GPIO_PIN GPIO_PIN_3
#define BUS_SPI3_SCK_GPIO_AF GPIO_AF6_SPI3

#ifndef BUS_SPI3_POLL_TIMEOUT
  #define BUS_SPI3_POLL_TIMEOUT                   0x1000U
#endif
/* SPI3 Baud rate in bps  */
#ifndef BUS_SPI3_BAUDRATE
   #define BUS_SPI3_BAUDRATE   10000000U /* baud rate of SPIn = 10 Mbps*/
#endif

/**
  * @}
  */

/** @defgroup STEVAL_STWINKT1B_BUS_Private_Types STEVAL_STWINKT1B BUS Private types
  * @{
  */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
typedef struct
{
  pSPI_CallbackTypeDef  pMspInitCb;
  pSPI_CallbackTypeDef  pMspDeInitCb;
}BSP_SPI_Cb_t;
#endif /* (USE_HAL_SPI_REGISTER_CALLBACKS == 1U) */
/**
  * @}
  */

/** @defgroup STEVAL_STWINKT1B_LOW_LEVEL_Exported_Variables LOW LEVEL Exported Constants
  * @{
  */

extern SPI_HandleTypeDef hspi3;

/**
  * @}
  */

/** @addtogroup STEVAL_STWINKT1B_BUS_Exported_Functions
  * @{
  */

/* BUS IO driver over SPI Peripheral */
HAL_StatusTypeDef MX_SPI3_Init(SPI_HandleTypeDef* hspi);
int32_t BSP_SPI3_Init(void);
int32_t BSP_SPI3_DeInit(void);
int32_t BSP_SPI3_Send(uint8_t *pData, uint16_t Length);
int32_t BSP_SPI3_Recv(uint8_t *pData, uint16_t Length);
int32_t BSP_SPI3_SendRecv(uint8_t *pTxData, uint8_t *pRxData, uint16_t Length);
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
int32_t BSP_SPI3_RegisterDefaultMspCallbacks (void);
int32_t BSP_SPI3_RegisterMspCallbacks (BSP_SPI_Cb_t *Callbacks);
#endif /* (USE_HAL_SPI_REGISTER_CALLBACKS == 1U) */

int32_t BSP_GetTick(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif /* STEVAL_STWINKT1B_BUS_H */

