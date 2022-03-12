/*						Temperature Sensor LM35 Driver Module
 ******************************************************************************************
 ******************************************************************************************
 Written by: Hisham Yakan Abuabkr
 Project: Fan Controller System
 File type: Module Header file
  */

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

/*
 ************************************** Included files******************************************
 */
#include "std_types.h"

/*
 ************************************* Definitions **********************************************
 */

#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150
#define SENSOR_CHANNEL_ID 		  2


/*
 ************************************* Functions **********************************************
 */
/*
 ******************** 1.Temperature sensor getter function **************************

 * Description : Function used calculate the temperature from the ADC digital value and return it.
 Function Inputs:void
 */

uint8 LM35_GetTemperature(void);

#endif /* TEMP_SENSOR_H_ */
