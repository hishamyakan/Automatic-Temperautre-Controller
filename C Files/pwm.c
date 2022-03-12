/*									PWM Driver Module
 ******************************************************************************************
 ******************************************************************************************
 Written by: Hisham Yakan Abuabkr
 Project: Fan Controller System
 File type: Module Source file
  */

/*
 ************************************** Included files******************************************
 */
#include "pwm.h"
#include "std_types.h"
#include "gpio.h"
#include "avr/io.h"


/*
 ************************************* Functions **********************************************
 */

/*
 ****************************** 1.Timer0 PWM Function *******************************
 Function Description: This function is used to generate the PMW Signal from the pin PB3
 Function Inputs: uint8 duty_cycle [Duty Cycle from 0 to 100 ]
  */

void PWM_Timer0_Start(uint8 duty_cycle)
{

	TCNT0 = 0; /* Set Timer Initial value. */
	OCR0  = (duty_cycle*(PWM_TOP_VALUE))/100; /* Set Compare Value. */
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT); /* set PB3/OC0 as output pin. */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

