/**
  ******************************************************************************
  * @file    ABusIF.c
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

#include "ABusIF.h"

int32_t ABusIFNullRW(void *pxSensor, uint8_t nRegAddr, uint8_t *pnData, uint16_t nSize)
{
  UNUSED(pxSensor);
  UNUSED(nRegAddr);
  UNUSED(pnData);
  UNUSED(nSize);

  return 0;
}
