/*
 * sensor_app.h
 *
 *  Created on: Oct 21, 2022
 *      Author: leonardoiacussi
 */

#ifndef INC_SENSOR_APP_H_
#define INC_SENSOR_APP_H_

//Includes for sensor_app.c
#include "pre_processing_app.h"
#include "aiApp.h"
#include "params.h"


#include "custom_motion_sensors_ex.h"


void sensor_init(void);
void sensor_process(void);

uint8_t Sensor_IO_SPI_CS_Init_All(void);


#endif /* INC_SENSOR_APP_H_ */
