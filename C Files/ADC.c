/*									ADC Driver Module
 ******************************************************************************************
 ******************************************************************************************
 Written by: Hisham Yakan Abuabkr
 Project: Fan Controller System
 File type: Module Source file
  */

/*
 ************************************** Included files******************************************
 */

#include "ADC.h"
#include "std_types.h"
#include "gpio.h"
#include "avr/io.h"
#include "Macros.h"

/*
 ************************************* Functions **********************************************
 */

/*
 ****************************** 1.ADC initialization function *******************************
 Function Description: This function is used to initialize the ADC to work by receiving the
 required configurations and setting them.
 Function Inputs:(ADC_ConfigType * Config_Ptr) A pointer to structure that receives the
 configuration of the ADC which is the prescaler and the source of reference voltage
  */

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*Setting the reference voltage in the ADMUX register in bits REFS1 & REFS0 */
	ADMUX = ((ADMUX &0x3F)|(Config_Ptr->ref_volt)<<6);

	/*Enabling the ADC & Setting the preScaller value in the ADCSRA register in bits ADPS2:0 */
	ADCSRA = (1<<ADEN)|((ADCSRA&0xF8)|(Config_Ptr->prescaler));
}


/*
****************************** 2.ADC function to read the channel *******************************
Function Description: This function is used to initialize the ADC to work by receiving the
required configurations and setting them.
Function Inputs: (uint8 channel) The channel at which the analoge device is connected and it
is a number from 0 to 7
 */

uint16 ADC_readChannel(uint8 channel)
{
	channel &= 0x07; /*The channel must be a number between 0 and 7 */

	/* Determine the ADC Channel to read in the register ADMUX */
	ADMUX = ((ADMUX &0xE0)|(ADC_CHANNEL_ID));
	/* Start the conversion */
	ADCSRA |= (1<<ADSC);

	/* Waiting until the conversion is finished */
	while(bit_is_clear(ADCSRA,ADIF));

	/*Clearing the flag */
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
