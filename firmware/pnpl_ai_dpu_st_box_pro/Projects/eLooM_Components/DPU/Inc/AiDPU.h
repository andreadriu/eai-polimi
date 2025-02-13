/**
  ******************************************************************************
  * @file    AiDPU.h
  * @author  STMicroelectronics - AIS - MCD Team
  * @brief   Digital processing Unit specialized for the Cube.AI library  *
  * This DPU process the data using Ai library generated by Cube.AI.
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
  
#ifndef DPU_INC_AIDPU_H_
#define DPU_INC_AIDPU_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "ADPU.h"
#include "ADPU_vtbl.h"
#include "har_network.h"
#include "aiApp.h"
#include "fft.h"

/**
 * Specifies the execution mode for the DPU. The execution mode tells the DPU what to do when it is running
 * and new signals provided by the data source is ready to be processed by the AI library.
 */
typedef enum _EAiMode {
  E_AI_MODE_NONE = 0,//!< no execution mode is selected.
  E_AI_DETECTION     //!< the AI library detect the similarity of the signal with the learned model.
} EAiMode_t;

#define AIDPU_NB_AXIS         (3)
#define AIDPU_NB_SAMPLE       (24)
#define AIDPU_AI_PROC_IN_SIZE (AI_HAR_NETWORK_IN_1_SIZE)
#define AIDPU_NAME            "har_network"

/**
 * Create  type name for _AiDPU_t.
 */
typedef struct _AiDPU_t AiDPU_t;

/**
 * AiDPU_t internal state.
 * It declares only the virtual table used to implement the inheritance.
 */
struct _AiDPU_t {
  /**
   * Base class object.
   */
  ADPU super;

  /**
   * Specifies if the in and out stream of teh DPU have been initialized.
   * To initialize the streams the application must use
   */
  boolean_t stream_ready;

  /**
   * Specifies the output data from Ai library. The output of the inference is:
   * ai_out[0] = index that specifies the HAR class
   * ai_out[1] = probability that the recognized activity belong to a given class.
   */
  float ai_out[2];

  /**
   * Specifies AI processing scale factor.
   */
  float scale;

  /**
   * Specifies AI processing function to use in order to process the signals.
   */
  int (*ai_processing_f)(const char*, float *, float[2]);
};


/* Public API declaration */
/**************************/

/**
 * Allocate an instance of AiDPU_t in the heap.
 *
 * @return a pointer to the generic object ::IDPU if success,
 * or NULL if out of memory error occurs.
 */
IDPU *AiDPUAlloc(void);

/**
 * Allocate an instance of AiDPU_t in a memory block specified by the application.
 * The size of the memory block must be greater or equal to sizeof(AiDPU_t).
 * This allocator allows the application to avoid the dynamic allocation.
 *
 * \code
 * AiDPU_t dpu;
 * AiDPUStaticAlloc(&dpu);
 * \endcode
 *
 * @param p_mem_block [IN] specify a memory block allocated by the application.
 *        The size of the memory block must be greater or equal to sizeof(AiDPU_t).
 * @return a pointer to the generic object ::IDPU if success,
 * or NULL if out of memory error occurs.
 */
IDPU *AiDPUStaticAlloc(void *p_mem_block);

/**
 * Compute the size in byte of the buffer that the application need to allocate and pass
 * to the DPU when it is attached to a sensor or to another DPU.
 *
 * \anchor fig400 \image html 400_api_DPUSetInputParams.png "Fig.400 - API - AiDPUSetInputParam() " width=630px
 *
 * @param _this [IN] specifies a pointer to the object.
 * @param signal_size [IN] specifies the number of input elements that the DPU must collect before starting the processing phase.
 * @param axes [IN] specifies the number of axes (or dimension) of each element.
 * @param cb_items [IN] specifies the number of items for the ::CircularBuffer used by the DPU.
 *                      An item of the ::CirculaBuffer is used to store `size` elements from the input source.
 * @return The size in byte of the buffer need by the DPU to acquire and process input data if success, zero otherwise.
 */
uint16_t AiDPUSetStreamsParam(AiDPU_t *_this, uint16_t signal_size, uint8_t axes, uint8_t cb_items);


/**
 * Set the processing mode for the DPU. It specifies to the DPU if a new signal is used
 * to learn and improve the model, or to detect anomalies.
 *
 * @param _this [IN] specifies a pointer to the object.
 * @param sensi [IN] specifies the sensitivity of the sensor
 * @return SYS_NO_ERROR_CODE if success, an error code otherwise.
 */
sys_error_code_t AiDPUSetSensitivity(AiDPU_t *_this, float sensi);


/**
 * Set the processing mode for the DPU. It specifies to the DPU if a new signal is used
 * to learn and improve the model, or to detect anomalies.
 *
 * @param _this [IN] specifies a pointer to the object.
 * @param mode [IN] specifies the processing mode. Valid value are:
 *  - E_AI_DETECTION
 * @return SYS_NO_ERROR_CODE if success, an error code otherwise.
 */
sys_error_code_t AiDPUSetProcessingMode(AiDPU_t *_this, EAiMode_t mode);


/**
 * Get the actual processing mode for the DPU.
 *
 * @param _this [IN] specifies a pointer to the object.
 * @return the actual processing mode of the DPU.
 */
inline EAiMode_t AiDPUGetProcessingMode(AiDPU_t *_this);

/**
 * Partial reset of the DPU internal state: all input and output buffers are re-initialized to prepare
 * the DPU to process a new stream of data.
 *
 * @param _this [IN] specifies a pointer to the object.
 * @return SYS_NO_ERROR_CODE if success, an error code otherwise.
 */
sys_error_code_t AiDPUPrepareToProcessData(AiDPU_t *_this);


/* Inline functions definition */
/*******************************/

SYS_DEFINE_INLINE
EAiMode_t AiDPUGetProcessingMode(AiDPU_t *_this)
{
  assert_param(_this != NULL);
  EAiMode_t res = E_AI_MODE_NONE;
/*
  if (_this->ai_processing_f == AI_detect)
  {
    res = E_AI_DETECTION;
  }
*/
  return res;
}

#ifdef __cplusplus
}
#endif

#endif /* DPU_INC_AiDPU_H_ */
