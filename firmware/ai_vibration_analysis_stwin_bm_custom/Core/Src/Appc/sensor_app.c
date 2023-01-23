/*
 * sensor_app.c
 *
 *  Created on: Oct 21, 2022
 *      Author: leonardoiacussi
 */

#include "sensor_app.h"
#include "custom_motion_sensors.h"
#include "usb_device.h"
#include <stdio.h>
#include "arm_math.h"
#include "usbd_cdc_if.h"

#include "stdio.h"

// define number of samples in the ISM330DHCX FIFO BUFFER
#define MAX_STRING_BUF_SIZE 30

// printing variables
static char string_out[MAX_STRING_BUF_SIZE];

// error return variable
int32_t ret=0;
uint8_t ret_uint=0;

// Pre processing init variable
pre_processing_data_t pre_processing_data;
float sensor_acc_sensitivity;
HAL_StatusTypeDef ret_hal_status;
uint8_t MemsEventDetected;


// process variables
int16_t DataOut[3];
tridimensional_data_t sensor_acc[INPUT_BUFFER_SIZE];
float32_t preprocessing_output_array[INPUT_BUFFER_SIZE/2];
float ai_out[2];

// time measurement variables
int32_t time_elapsed=0;
int32_t time_elapsed2=0;
int32_t post_FIFO_read;
int32_t pre_FIFO_read;

void sensor_init(void){

	// init ism330dhcx sensor
	ret_uint = Sensor_IO_SPI_CS_Init_All();
	ret = CUSTOM_MOTION_SENSOR_Init(CUSTOM_ISM330DHCX_0,MOTION_ACCELERO);
	ret = CUSTOM_MOTION_SENSOR_SetOutputDataRate(CUSTOM_ISM330DHCX_0, MOTION_ACCELERO,ISM330DHCX_ACC_ODR);
	ret = CUSTOM_MOTION_SENSOR_FIFO_Set_BDR( CUSTOM_ISM330DHCX_0,  MOTION_ACCELERO, ISM330DHCX_ACC_ODR);
	ret = CUSTOM_MOTION_SENSOR_SetFullScale( CUSTOM_ISM330DHCX_0,  MOTION_ACCELERO, ISM330DHCX_ACC_FS);

	// get sensor sensitivity
	ret = CUSTOM_MOTION_SENSOR_GetSensitivity(CUSTOM_ISM330DHCX_0, MOTION_ACCELERO, &sensor_acc_sensitivity);

	// sensor fifo init
	ret = CUSTOM_MOTION_SENSOR_FIFO_Set_INT1_FIFO_Full(CUSTOM_ISM330DHCX_0, ENABLE);
	ret = CUSTOM_MOTION_SENSOR_FIFO_Set_Watermark_Level( CUSTOM_ISM330DHCX_0, INPUT_BUFFER_SIZE);
	ret = CUSTOM_MOTION_SENSOR_FIFO_Set_Stop_On_Fth(CUSTOM_ISM330DHCX_0,  ENABLE);
	ret = CUSTOM_MOTION_SENSOR_FIFO_Set_Mode(CUSTOM_ISM330DHCX_0,  ISM330DHCX_STREAM_MODE);

	// AI init
	aiInit();
	// PRE PROCESSING init
	pre_processing_init(&pre_processing_data);

}

void sensor_process(void){

	if (MemsEventDetected == 1){

		//pre_FIFO_read = BSP_GetTick();

		MemsEventDetected = 0;

		for(int jj=0;jj<INPUT_BUFFER_SIZE;jj++){
			CUSTOM_MOTION_SENSOR_FIFO_Get_Data_Word(CUSTOM_ISM330DHCX_0, MOTION_ACCELERO, DataOut);
			sensor_acc[jj].x = ((float)DataOut[0])*sensor_acc_sensitivity*0.001; // from [mg] to [g]
			sensor_acc[jj].y = ((float)DataOut[1])*sensor_acc_sensitivity*0.001;
			sensor_acc[jj].z = ((float)DataOut[2])*sensor_acc_sensitivity*0.001;
		}

		// call pre_processing_functions
		pre_processing_process(sensor_acc, INPUT_BUFFER_SIZE, preprocessing_output_array, INPUT_BUFFER_SIZE/2, &pre_processing_data);

		// call ai process
		aiProcess(preprocessing_output_array, ai_out);

		// print to Virtual COM
		snprintf(string_out, sizeof(string_out), "label: %.0f , Accuracy: %.2f \r\n", ai_out[0], ai_out[1]);
		CDC_Transmit_FS((uint8_t*)string_out, strlen(string_out));

		// print to STLINK
		//printf("Class: %f, Accuracy: %f \r\n",ai_out[0],ai_out[1]);

		//post_FIFO_read = BSP_GetTick();

		//time_elapsed = post_FIFO_read - pre_FIFO_read;

	}
	//Get number of unread FIFO samples
    //CUSTOM_MOTION_SENSOR_FIFO_Get_Num_Samples(CUSTOM_ISM330DHCX_0, &num_samples);

}



/**
 * @brief  Set all sensor Chip Select high. To be called before any SPI read/write
 * @param  None
 * @retval HAL_StatusTypeDef HAL Status
 */
uint8_t Sensor_IO_SPI_CS_Init_All(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Set the pin for the ISM330DHCX before init to avoid a glitch */
  //if use STWIN
  BUS_SPI3_SCK_GPIO_CLK_ENABLE();
  //if use STWIN.BX
  //BUS_SPI2_SCK_GPIO_CLK_ENABLE();

  HAL_GPIO_WritePin(CUSTOM_ISM330DHCX_0_CS_PORT, CUSTOM_ISM330DHCX_0_CS_PIN, GPIO_PIN_SET);

  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

  GPIO_InitStruct.Pin = CUSTOM_ISM330DHCX_0_CS_PIN;
  HAL_GPIO_Init(CUSTOM_ISM330DHCX_0_CS_PORT, &GPIO_InitStruct);

  return 0;
}

