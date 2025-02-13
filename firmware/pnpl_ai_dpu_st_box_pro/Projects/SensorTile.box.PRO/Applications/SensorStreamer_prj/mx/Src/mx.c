/**
 ******************************************************************************
 * @file    mx.c
 * @author  STMicroelectronics - AIS - MCD Team
 * @version 3.0.1
 * @date    21/01/2022 10:35:14
 *
 * @brief Project peripherals configuration files.
 *
 * This files defines the peripherals configuration parameters that can be used
 * in the Low Level API of an eLooM driver - IDrvInit(). It creates a link
 * between the initialization code generated by CubeMX (see the .ioc file
 * in the tools folder) and the eLooM framework.
 *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
 */

#include "mx.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"
#include "i2c.h"
#include "spi.h"
#include "gpdma.h"


/**
 * (USER_BUTTON) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_UBInitParams = {
    MX_GPIO_PC13_Init,
	USER_BUTTON_EXTI_IRQn,
	USER_BUTTON_Pin,
	USER_BUTTON_GPIO_Port
};

/**
 * (INT_HTS) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT_HTSInitParams = {
    MX_GPIO_PE11_Init,
	INT_HTS_EXTI_IRQn,
	INT_HTS_Pin,
	INT_HTS_GPIO_Port
};

/**
 * (INT_STT) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT_STTInitParams = {
    MX_GPIO_PB15_Init,
	INT_STT_EXTI_IRQn,
	INT_STT_Pin,
	INT_STT_GPIO_Port
};

/**
 * (INT_LPS) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT_LPSInitParams = {
    MX_GPIO_PE8_Init,
	INT_LPS_EXTI_IRQn,
	INT_LPS_Pin,
	INT_LPS_GPIO_Port
};

/**
 * (INT_MAG) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT_MAGInitParams = {
    MX_GPIO_PE6_Init,
	INT_MAG_EXTI_IRQn,
	INT_MAG_Pin,
	INT_MAG_GPIO_Port
};

/**
 * (INT1_ACC) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT1_ACCInitParams = {
    MX_GPIO_PF2_Init,
	INT1_ACC_EXTI_IRQn,
	INT1_ACC_Pin,
	INT1_ACC_GPIO_Port
};

/**
 * (INT1_DSV16X) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT1_DSV16XInitParams = {
    MX_GPIO_PA4_Init,
	INT1_DSV16X_EXTI_IRQn,
	INT1_DSV16X_Pin,
	INT1_DSV16X_GPIO_Port
};

/**
 * PI7 Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_CS_ACCInitParams = {
    MX_GPIO_PI7_Init,
    UsageFault_IRQn, /*!< NOT USED */
	CS_ACC_Pin,
	CS_ACC_GPIO_Port
};

/**
 * PI5 Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_CS_DSV16XInitParams = {
    MX_GPIO_PI5_Init,
    UsageFault_IRQn, /*!< NOT USED */
	CS_DSV16X_Pin,
	CS_DSV16X_GPIO_Port
};

/**
 * (INT1_DHCX) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT1_DHCXInitParams = {
    MX_GPIO_PB8_Init,
	INT1_DHCX_EXTI_IRQn,
	INT1_DHCX_Pin,
	INT1_DHCX_GPIO_Port
};

/**
 * (INT2_DHCX) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT2_DHCXInitParams = {
    MX_GPIO_PF4_Init,
	INT2_DHCX_EXTI_IRQn,
	INT2_DHCX_Pin,
	INT2_DHCX_GPIO_Port
};

/**
 * (INT1_DWB) Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_INT1_DWBInitParams = {
    MX_GPIO_PF15_Init,
	INT1_DWB_EXTI_IRQn,
	INT1_DWB_Pin,
	INT1_DWB_GPIO_Port
};

/**
 * PH6 Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_CS_DLPCInitParams = {
    MX_GPIO_PH6_Init,
    UsageFault_IRQn, /*!< NOT USED */
	CS_DLPC_Pin,
	CS_DLPC_GPIO_Port
};

/**
 * PH15 Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_CS_DHCXInitParams = {
    MX_GPIO_PH15_Init,
    UsageFault_IRQn, /*!< NOT USED */
	CS_DHCX_Pin,
	CS_DHCX_GPIO_Port
};

/**
 * PF12 Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_CS_DWBInitParams = {
    MX_GPIO_PF12_Init,
    UsageFault_IRQn, /*!< NOT USED */
	CS_DWB_Pin,
	CS_DWB_GPIO_Port
};

/**
 * TIM6 initialization parameters.
 */
const MX_TIMParams_t MX_TIM7InitParams = {
    .p_mx_init_f = MX_TIM7_Init,
    .p_tim = &htim7,
    .irq_n = TIM7_IRQn
};

#if 0
/**
 * LD2 Initialization parameters.
 */
const MX_GPIOParams_t MX_GPIO_LD2InitParams = {
    MX_GPIO_PA5_Init,
    UsageFault_IRQn, /* not used. */
    GPIO_PIN_5,
    GPIOA
};

/**
 * TIM16 initialization parameters.
 */
const MX_TIMParams_t MX_TIM16InitParams = {
    .p_mx_init_f = MX_TIM16_Init,
    .p_tim = &htim16,
    .irq_n = TIM1_UP_TIM16_IRQn
};
#endif

/**
 * I2C1 initialization parameters.
 */
const MX_I2CParams_t MX_I2C1InitParams = {
    .p_mx_init_f = MX_I2C1_Init,
    .p_i2c_handle = &hi2c1,
    .p_mx_dma_init_f = MX_GPDMA1_InitCustom,
    .i2c_er_irq_n = I2C1_ER_IRQn,
    .i2c_ev_irq_n = I2C1_EV_IRQn,
    .i2c_dma_rx_irq_n = GPDMA1_Channel2_IRQn,
    .i2c_dma_tx_irq_n = GPDMA1_Channel3_IRQn
};

/**
 * SPI2 initialization parameters.
 */
const MX_SPIParams_t MX_SPI2InitParams = {
    .p_mx_init_f = MX_SPI2_Init,
    .p_spi_handle  = &hspi2,
    .p_mx_dma_init_f = MX_GPDMA1_InitCustom,
    .spi_dma_rx_irq_n = GPDMA1_Channel0_IRQn,
    .spi_dma_tx_irq_n = GPDMA1_Channel1_IRQn
};
