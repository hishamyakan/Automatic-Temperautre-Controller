/*									ADC Driver Module
 ******************************************************************************************
 ******************************************************************************************
 Written by: Hisham Yakan Abuabkr
 Project: Fan Controller System
 File type: Module Header file
  */

/*
 ************************************** Included files******************************************
 */

#include  "DCmotor.h"
#include "Macros.h"
#include "std_types.h"
#include "gpio.h"
#include "pwm.h"


/*
 ************************************* Functions **********************************************
 */


/*
 ****************************** 1.Motor initialization function *******************************
 Function Description: This function is used to initialize the Motor to work by receiving the
 required configurations and setting them.
 Function Inputs: (Void)
  */


void DcMotor_Init(void)
{
	/*
	 1.Setting motor pin0 and pin1 as output
	 2.Initializing the motor state to stop
	 */


	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN2_ID,PIN_OUTPUT);
	motor_stop();
}

/*
 **************************** 2.Motor Rotation function *****************************
 Function Description: This function is used to rotate the motor in certain direction and with
 certain speed .
 Function Inputs: (DcMotor_State state,uint8 speed)
 state: determines the state whether clockwise or anticlockwise rotation or stop
 speed: Determines the speed of rotation of the motor with duty Cycle form 0 to 100
  */




void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/*Generating a PWM signal on Enable pin of the H-bridge with the required speed*/
	PWM_Timer0_Start(speed);



	if(state == Motor_CW)
	{
		motor_rotate_clockwise();
	}

	else if (state == Motor_AntiCW)
	{
		motor_rotate_anticlockwise();
	}

	else
	{
		motor_stop();
	}


}

/*
 **************************** 3.Motor ClockWise Rotation function *****************************
 Function Description: This function sets the rotation direction of the motor to be clockwise
 rotation
 Function Inputs: (Void)
  */

void motor_rotate_clockwise(void)
{

	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_HIGH);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);

}

/*
 **************************** 4.Motor AntiClockWise Rotation function *****************************
 Function Description: This function sets the rotation direction of the motor to be anticlockwise
 rotation
 Function Inputs: (Void)
  */

void motor_rotate_anticlockwise(void)
{
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_HIGH);
}


/*
 **************************** 5.Motor Stopping function *****************************
 Function Description: This function Stops the rotation of the motor
 Function Inputs: (Void)
  */

void motor_stop(void)
{
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);
}
