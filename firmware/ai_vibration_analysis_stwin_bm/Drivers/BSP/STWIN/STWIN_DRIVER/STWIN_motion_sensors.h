/**
******************************************************************************
* @file    STWIN_motion_sensors.h
* @author  SRA
* @version v1.4.0
* @date    11-Sep-2020
* @brief   This file contains definitions for the BSP Motion Sensors interface
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2019 STMicroelectronics. 
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under BSD 3-Clause license,
* the "License"; You may not use this file except in compliance with the 
* License. You may obtain a copy of the License at:
*                        opensource.org/licenses/BSD-3-Clause
*
******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STWIN_MOTION_SENSORS_H__
#define STWIN_MOTION_SENSORS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "STWIN_conf.h"
#include "motion_sensor.h"
#include "stm32l4xx_hal_spi.h"

#ifndef USE_MOTION_SENSOR_IIS2DH_0
#define USE_MOTION_SENSOR_IIS2DH_0		1
#endif

#ifndef USE_MOTION_SENSOR_IIS2MDC_0
#define USE_MOTION_SENSOR_IIS2MDC_0		1
#endif

#ifndef USE_MOTION_SENSOR_IIS3DWB_0
#define USE_MOTION_SENSOR_IIS3DWB_0		1
#endif
  
#ifndef USE_MOTION_SENSOR_ISM330DHCX_0
#define USE_MOTION_SENSOR_ISM330DHCX_0	1
#endif
  
#if (USE_MOTION_SENSOR_IIS2DH_0 == 1)
#include "iis2dh.h"
#endif

#if (USE_MOTION_SENSOR_IIS2MDC_0 == 1)
#include "iis2mdc.h"
#endif

#if (USE_MOTION_SENSOR_IIS3DWB_0 == 1)
#include "iis3dwb.h"
#endif  
  
#if (USE_MOTION_SENSOR_ISM330DHCX_0 == 1)
#include "ism330dhcx.h"
#endif 
  
#if (USE_MOTION_SENSOR_IIS2DH_0 == 1)
#define IIS2DH_0 (0)
#endif

#if (USE_MOTION_SENSOR_IIS2MDC_0 == 1)
#define IIS2MDC_0 (USE_MOTION_SENSOR_IIS2DH_0)
#endif
 
#if (USE_MOTION_SENSOR_IIS3DWB_0 == 1)
#define IIS3DWB_0 (USE_MOTION_SENSOR_IIS2DH_0 + USE_MOTION_SENSOR_IIS2MDC_0)
#endif
  
#if (USE_MOTION_SENSOR_ISM330DHCX_0 == 1)
#define ISM330DHCX_0 (USE_MOTION_SENSOR_IIS2DH_0 + USE_MOTION_SENSOR_IIS2MDC_0 + USE_MOTION_SENSOR_IIS3DWB_0)
#endif

typedef struct
{
  int32_t x;
  int32_t y;
  int32_t z;
} BSP_MOTION_SENSOR_Axes_t;

typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;
} BSP_MOTION_SENSOR_AxesRaw_t;

/* Motion Sensor instance Info */
typedef struct
{
  uint8_t  Acc;
  uint8_t  Gyro;
  uint8_t  Magneto;
  uint8_t  LowPower;
  uint32_t GyroMaxFS;
  uint32_t AccMaxFS;
  uint32_t MagMaxFS;
  float    GyroMaxOdr;
  float    AccMaxOdr;
  float    MagMaxOdr;
} MOTION_SENSOR_Capabilities_t;

typedef struct
{
  uint32_t Functions;
} MOTION_SENSOR_Ctx_t;

#define MOTION_GYRO             1U
#define MOTION_ACCELERO         2U
#define MOTION_MAGNETO          4U

#define MOTION_FUNCTIONS_NBR    3U
#define MOTION_INSTANCES_NBR    (USE_MOTION_SENSOR_IIS2DH_0 + USE_MOTION_SENSOR_IIS2MDC_0 + USE_MOTION_SENSOR_IIS3DWB_0 + USE_MOTION_SENSOR_ISM330DHCX_0)

#if (MOTION_INSTANCES_NBR == 0)
#error "No motion sensor instance has been selected"
#endif

int32_t BSP_MOTION_SENSOR_Init(uint32_t Instance, uint32_t Functions);
int32_t BSP_MOTION_SENSOR_DeInit(uint32_t Instance);
int32_t BSP_MOTION_SENSOR_GetCapabilities(uint32_t Instance, MOTION_SENSOR_Capabilities_t *Capabilities);
int32_t BSP_MOTION_SENSOR_ReadID(uint32_t Instance, uint8_t *Id);
int32_t BSP_MOTION_SENSOR_Enable(uint32_t Instance, uint32_t Function);
int32_t BSP_MOTION_SENSOR_Disable(uint32_t Instance, uint32_t Function);
int32_t BSP_MOTION_SENSOR_GetAxes(uint32_t Instance, uint32_t Function, BSP_MOTION_SENSOR_Axes_t *Axes);
int32_t BSP_MOTION_SENSOR_GetAxesRaw(uint32_t Instance, uint32_t Function, BSP_MOTION_SENSOR_AxesRaw_t *Axes);
int32_t BSP_MOTION_SENSOR_GetSensitivity(uint32_t Instance, uint32_t Function, float *Sensitivity);
int32_t BSP_MOTION_SENSOR_GetOutputDataRate(uint32_t Instance, uint32_t Function, float *Odr);
int32_t BSP_MOTION_SENSOR_SetOutputDataRate(uint32_t Instance, uint32_t Function, float Odr);
int32_t BSP_MOTION_SENSOR_GetFullScale(uint32_t Instance, uint32_t Function, int32_t *Fullscale);
int32_t BSP_MOTION_SENSOR_SetFullScale(uint32_t Instance, uint32_t Function, int32_t Fullscale);

#ifdef __cplusplus
}
#endif

#endif /* STWIN_MOTION_SENSORS_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
