/*						Temperature Sensor LM35 Driver Module
 ******************************************************************************************
 ******************************************************************************************
 Written by: Hisham Yakan Abuabkr
 Project: Fan Controller System
 File type: Module Header file
  */


/*
 ************************************** Included files******************************************
 */
#include "Temp_Sensor.h"
#include "std_types.h"
#include "ADC.h"


/*
 ************************************* Functions **********************************************
 */
/*
 ******************** 1.Temperature sensor getter function **************************


 * Description : Function used calculate the temperature from the ADC digital value and return it.
 Function Inputs:void
 */

uint8 LM35_GetTemperature(void)
{
	uint8 temp= 0; // Variable to store the temperature
	uint16 adc= 0;

	// Receiving the converted value form the ADC
	adc = ADC_readChannel(SENSOR_CHANNEL_ID);

	temp = (uint8)(((uint32)adc*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp;
}

