/**
 ******************************************************************************
 * @file    LPS22DFTask.h
 * @author  SRA - MCD
 * @version 1.0.0
 * @date    6-Sep-2021
 *
 * @brief
 *
 * <DESCRIPTIOM>
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under ODE SOFTWARE LICENSE AGREEMENT
 * SLA0094, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0094
 *
 ******************************************************************************
 */
#ifndef LPS22DFTASK_H_
#define LPS22DFTASK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "services/systp.h"
#include "services/syserror.h"
#include "services/AManagedTaskEx.h"
#include "services/AManagedTaskEx_vtbl.h"
#include "ABusIF.h"
#include "events/DataEventSrc.h"
#include "events/DataEventSrc_vtbl.h"
#include "ISensor.h"
#include "ISensor_vtbl.h"


#define LPS22DF_MAX_DRDY_PERIOD           (1.0)
#ifndef LPS22DF_MAX_WTM_LEVEL
#define LPS22DF_MAX_WTM_LEVEL             (128)
#endif
#define LPS22DF_MIN_WTM_LEVEL             (16)
#define LPS22DF_MAX_SAMPLES_PER_IT        (LPS22DF_MAX_WTM_LEVEL)

#define LPS22DF_CFG_MAX_LISTENERS         2

/**
 * Create a type name for _LPS22DFTask.
 */
typedef struct _LPS22DFTask LPS22DFTask;

// Public API declaration
//***********************

/**
 * Get the ISourceObservable interface for the gyroscope.
 * @param _this [IN] specifies a pointer to a task object.
 * @return a pointer to the generic object ::ISourceObservable if success,
 * or NULL if out of memory error occurs.
 */
ISourceObservable* LPS22DFTaskGetPressSensorIF(LPS22DFTask *_this);

/**
 * Allocate an instance of LPS22DFTask.
 *
 * @param pIRQConfig [IN] specifies a ::MX_GPIOParams_t instance declared in the mx.h file.
 *        It must be a GPIO connected to the LPS22DF sensor and configured in EXTI mode.
 *        If it is NULL then the sensor is configured in polling mode.
 * @param pCSConfig [IN] specifies a ::MX_GPIOParams_t instance declared in the mx.h file.
 *        It must be a GPIO identifying the SPI CS Pin.
 * @return a pointer to the generic object ::AManagedTaskEx if success,
 * or NULL if out of memory error occurs.
 */
AManagedTaskEx* LPS22DFTaskAlloc(const void *pIRQConfig, const void *pCSConfig);

/**
 * Get the Bus interface for the sensor task.
 *
 * @param _this [IN] specifies a pointer to a task object.
 * @return a pointer to the Bus interface of the sensor.
 */
ABusIF* LPS22DFTaskGetSensorIF(LPS22DFTask *_this);

/**
 * Get the ::IEventSrc interface for the sensor task.
 * @param _this [IN] specifies a pointer to a task object.
 * @return a pointer to the ::IEventSrc interface of the sensor.
 */
IEventSrc* LPS22DFTaskGetPressEventSrcIF(LPS22DFTask *_this);

// Inline functions definition
// ***************************

#ifdef __cplusplus
}
#endif

#endif /* LPS22DFTASK_H_ */
