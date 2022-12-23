/**
  ******************************************************************************
  * @file    AnomalyThreshold_DPU.h
  * @author  SRA - MCD
  * @brief   
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
  
#ifndef ANOMALYTHRESHOLD_DPU_H_
#define ANOMALYTHRESHOLD_DPU_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "services/systp.h"
#include "services/syserror.h"


#include "events/ProcessEventSrc.h"
#include "events/ProcessEventSrc_vtbl.h"
#include "events/ProcessEvent.h"

#include "IDPU.h"
#include "IDPUVtbl.h"
#include "ADPU.h"
#include "ADPU_vtbl.h"



  typedef struct Range {
    uint16_t Min;
    uint16_t Max;
  }Range_t;

  typedef enum
  {
    TH_OK =0, WARNING, ALERT, CRITICAL
  } Threshold_type_t;


  typedef struct ThValue {
    Range_t frequency_range;
    float Value;
    Threshold_type_t Type;
  }ThValue_t;


  typedef struct
  {
    Threshold_type_t severity;
    float freq;
    float mag;
  } Event_t;

  typedef struct _AnomalyEvent_t {
    ai_logging_packet_t   packet;
    Event_t    evt;
  } AnomalyEvent_t;


  /**
   * Create  type name for _AnomalyThreshold_DPUTask.
   */
  typedef struct _AnomalyThreshold_DPU_t AnomalyThreshold_DPU_t;

  // Public API declaration
  //***********************

  /**
   * Allocate an instance of AnomalyThreshold_DPUTask.
   *
   * @return a pointer to the generic obejct ::AManagedTaskEx if success,
   * or NULL if out of memory error occurs.
   */
  IDPU *AnomalyThreshold_DPUAlloc(void);

  uint32_t AnomalyThreshold_DPUSetInputParam(AnomalyThreshold_DPU_t *_this, uint16_t size, uint8_t nAxis, uint8_t cb_items, float bfs, uint8_t is_lower);
  sys_error_code_t AnomalyThreshold_DPU_UpdateThreshold(AnomalyThreshold_DPU_t *_this, ThValue_t warning, ThValue_t alert, ThValue_t critical, uint32_t tag);
  sys_error_code_t AnomalyThreshold_DPUSetInputThreshold(AnomalyThreshold_DPU_t *_this, ThValue_t warning, ThValue_t alert, ThValue_t critical, uint32_t tag);



  // Inline functions definition
  // ***************************

#ifdef __cplusplus
}
#endif

#endif /* USER_INC_AnomalyThreshold_DPUTask_H_ */
