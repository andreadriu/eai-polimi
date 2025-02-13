/**
  ******************************************************************************
  * @file    MDFDriver.h
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
#ifndef HSDCORE_INC_DRIVERS_MDFDRIVER_H_
#define HSDCORE_INC_DRIVERS_MDFDRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "drivers/IDriver.h"
#include "drivers/IDriver_vtbl.h"
#include "mx.h"


/**
  * Create  type name for _MDFDriver_t.
  */
typedef struct _MDFDriver_t MDFDriver_t;

/**
  * Initialization parameters for the driver.
  */
typedef struct _MDFDriverParams_t
{
  /**
    * Specifies the peripheral HAL initialization parameters generated by CubeMX.
    */
  MX_MDFParams_t *p_mx_mdf_cfg;

  /**
    * Generic parameter.
    */
  uint32_t param;
} MDFDriverParams_t;


/**
  *  MDFDriver_t internal structure.
  */
struct _MDFDriver_t
{
  /**
    * Base class object.
    */
  IDriver super;

  /* Driver variables should be added here. */

  /**
    * Specifies all the configuration parameters for the MDF peripheral linked to
    * an instance of this class. It based on the HAL driver generated by CubeMX.
    */
  MDFDriverParams_t mx_handle;

  /**
    * Specifies a data buffer. The application is responsible to allocate the buffer.
    * The driver object store in the buffer the audio data.
    */
  int16_t *p_buffer;

  /**
    * Specifies the size in word of the data buffer.
    */
  uint32_t buffer_size;
};


/** Public API declaration */
/***************************/

/**
  * Allocate an instance of MDFDriver_t. The driver is allocated
  * in the FreeRTOS heap.
  *
  * @return a pointer to the generic interface ::IDriver if success,
  * or SYS_OUT_OF_MEMORY_ERROR_CODE otherwise.
  */
IDriver *MDFDriverAlloc(void);

sys_error_code_t MDFSetMDFConfig(IDriver *_this, float ODR);

/**
  * Register a callback function with the HAL driver.
  * @sa HAL_MDF_RegisterCallback()
  */
static inline sys_error_code_t MDFDriverFilterRegisterCallback(MDFDriver_t *_this, HAL_MDF_CallbackIDTypeDef CallbackID,
                                                        pMDF_CallbackTypeDef pCallback);

/**
  * Set the buffer that will be filled by the driver with audio data from the sensor.
  * The application must provide a data buffer before starting the driver.
  *
  * @param _this [IN] specifies an instance of the driver.
  * @param p_buffer [IN] specifies a pointer to the data buffer.
  * @param buffer_size [IN] specifies the size in word of the data buffer.
  * @return SYS_NO_ERROR_CODE if success, an error code otherwise.
  */
sys_error_code_t MDFDrvSetDataBuffer(MDFDriver_t *_this, int16_t *p_buffer, uint32_t buffer_size);


/** Inline functions definition */
/********************************/

SYS_DEFINE_INLINE
sys_error_code_t MDFDriverFilterRegisterCallback(MDFDriver_t *_this, HAL_MDF_CallbackIDTypeDef CallbackID,
                                                 pMDF_CallbackTypeDef pCallback)
{
  assert_param(_this != NULL);

  (void)HAL_MDF_RegisterCallback(_this->mx_handle.p_mx_mdf_cfg->p_mdf, CallbackID, pCallback);

  return SYS_NO_ERROR_CODE;
}

#ifdef __cplusplus
}
#endif

#endif /* HSDCORE_INC_DRIVERS_MDFDRIVER_H_ */
