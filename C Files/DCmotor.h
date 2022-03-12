/*									ADC Driver Module
 ******************************************************************************************
 ******************************************************************************************
 Written by: Hisham Yakan Abuabkr
 Project: Fan Controller System
 File type: Module Header file
  */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
/*
 ************************************** Included files******************************************
 */

#include "std_types.h"

/*
 ************************************* Static Configurations **********************************************
 */

#define MOTOR_PORT_ID PORTB_ID  /*Motor Port*/
#define MOTOR_PIN1_ID PIN0_ID	/*Motor First pin */
#define MOTOR_PIN2_ID PIN1_ID	/*Motor Second pin */

/*
 ************************************* Definitions **********************************************
 */
typedef enum
{
	Motor_OFF,Motor_CW,Motor_AntiCW
}DcMotor_State;

/*
 ************************************* Functions **********************************************
 */


/*
 ****************************** 1.Motor initialization function *******************************
 Function Description: This function is used to initialize the Motor to work by receiving the
 required configurations and setting them.
 Function Inputs: (Void)
  */

void DcMotor_Init(void);

/*
 **************************** 2.Motor Rotation function *****************************
 Function Description: This function is used to rotate the motor in certain direction and with
 certain speed .
 Function Inputs: (DcMotor_State state,uint8 speed)
 state: determines the state whether clockwise or anticlockwise rotation or stop
 speed: Determines the speed of rotation of the motor with duty Cycle form 0 to 100
  */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

/*
 **************************** 3.Motor ClockWise Rotation function *****************************
 Function Description: This function sets the rotation direction of the motor to be clockwise
 rotation
 Function Inputs: (Void)
  */

void motor_rotate_clockwise(void);

/*
 **************************** 4.Motor AntiClockWise Rotation function *****************************
 Function Description: This function sets the rotation direction of the motor to be anticlockwise
 rotation
 Function Inputs: (Void)
  */

void motor_rotate_anticlockwise(void);

/*
 **************************** 5.Motor Stopping function *****************************
 Function Description: This function Stops the rotation of the motor
 Function Inputs: (Void)
  */

void motor_stop(void);



#endif /* DCMOTOR_H_ */
