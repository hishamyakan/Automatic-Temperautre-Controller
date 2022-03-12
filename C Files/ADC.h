/*									ADC Driver Module
 ******************************************************************************************
 ******************************************************************************************
 Written by: Hisham Yakan Abuabkr
 Project: Fan Controller System
 File type: Module Header file
  */



#ifndef ADC_H_
#define ADC_H_

/*
 ************************************** Included files******************************************
 */
#include "std_types.h"


/*
 ************************************* Static Configurations **********************************************
 */
#define ADC_CHANNEL_ID 2  /*ADC Channel connected to analog device*/

/*
 ************************************* Definitions **********************************************
 */

#define ADC_MAXIMUM_VALUE    1023		/*ADC number of bits */
#define  ADC_REF_VOLT_VALUE  2.56   	/*ADC Reference Voltage*/

/*Enumeration to determine the preScaller */

typedef enum
{
	ADC_PRE_0,ADC_PRE_2,ADC_PRE_4,ADC_PRE_8,ADC_PRE_16,ADC_PRE_32,ADC_PRE_64,ADC_PRE_128
}ADC_Prescaler;

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL_VREF
}ADC_ReferenceVolatge;


/*Structure to receive the ADC Configurations */

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;


/*
 ************************************* Functions **********************************************
 */

/*
 ****************************** 1.ADC initialization function *******************************
 Function Description: This function is used to initialize the ADC to work by receiving the
 required configurations and setting them.
 Function Inputs:(ADC_ConfigType * Config_Ptr) A pointer to structure that receives the
 configuration of the ADC which is the preScaller and the source of reference voltage
  */

void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
****************************** 2.ADC function to read the channel *******************************
Function Description: This function is used to initialize the ADC to work by receiving the
required configurations and setting them.
Function Inputs: (uint8 channel) The channel at which the analoge device is connected and it
is a number from 0 to 7
 */

uint16 ADC_readChannel(uint8 channel);

#endif /* ADC_H_ */
