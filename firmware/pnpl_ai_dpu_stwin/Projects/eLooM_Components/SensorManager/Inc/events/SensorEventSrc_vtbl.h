/**
 ******************************************************************************
 * @file    SensorEventSrc_vtbl.h
 * @author  SRA - MCD
 * @version 1.1.0
 * @date    10-Dec-2021
 *
 * @brief
 *
 * <DESCRIPTIOM>
 *
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *                             
 *
 ******************************************************************************
 */
#ifndef INCLUDE_EVENTS_SENSOREVENTSRC_VTBL_H_
#define INCLUDE_EVENTS_SENSOREVENTSRC_VTBL_H_

#ifdef __cplusplus
extern "C" {
#endif


// Inline functions definition
// ***************************

// IEventSrc virtual functions
sys_error_code_t SensorEventSrc_vtblSendEvent(const IEventSrc *_this, const IEvent *pxEvent, void *pvParams);


#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_EVENTS_SENSOREVENTSRC_VTBL_H_ */
