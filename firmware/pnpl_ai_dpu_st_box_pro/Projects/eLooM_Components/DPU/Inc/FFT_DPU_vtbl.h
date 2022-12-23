/**
  ******************************************************************************
  * @file    FFT_DPU_vtbl.h
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
 
#ifndef USER_INC_FFT_DPU_VTBL_H_
#define USER_INC_FFT_DPU_VTBL_H_

#ifdef __cplusplus
extern "C" {
#endif


// IDPU virtual functions
  sys_error_code_t FFT_DPU_Process_vtbl(IDPU *_this);
  sys_error_code_t FFT_DPUInit(IDPU *_this);


#ifdef __cplusplus
}
#endif

#endif /* USER_INC_FFT_DPU_VTBL_H_ */
