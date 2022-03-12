
/*
 ************************************** Included files******************************************
 */
#include "ADC.h"
#include "LCD.h"
#include "DCmotor.h"
#include "Temp_Sensor.h"
#include <util/delay.h>
#include "pwm.h"

/*
************************************************************************************************
 */




int main(){
/*
 ****************************************ADC_Initialization*************************************
 */
		ADC_ConfigType myMainADC;
		myMainADC.prescaler = ADC_PRE_8;
		myMainADC.ref_volt =INTERNAL_VREF;
		ADC_init(&myMainADC);
/*
************************************************************************************************
 */



/*
 ****************************************LCD_Initialization*************************************
 */
	LCD_init();
/*
***********************************************************************************************
 */



/****************************************MOTOR_Initialization*************************************
 */
	DcMotor_Init();
/*
*************************************************************************************************
 */


	while(1)
	{
		/*Receiving the temperature form the sensor */
		uint8 current_temperature = LM35_GetTemperature();

		if(current_temperature<30)
		{
			DcMotor_Rotate(Motor_OFF,0);
			LCD_moveCursor(0,4);
			LCD_displayString("Fan is OFF");

		}

		else if (current_temperature>=30 && current_temperature<60)
		{
			DcMotor_Rotate(Motor_CW,25);
			LCD_moveCursor(0,4);
			LCD_displayString("Fan is ON ");

		}

		else if (current_temperature>=60 && current_temperature<90)
		{
			DcMotor_Rotate(Motor_CW,50);
			LCD_moveCursor(0,4);
			LCD_displayString("Fan is ON ");

		}

		else if (current_temperature>=90 && current_temperature<120)
		{
			DcMotor_Rotate(Motor_CW,75);
			LCD_moveCursor(0,4);
			LCD_displayString("Fan is ON ");

		}

		else if (current_temperature>=120)
		{
			DcMotor_Rotate(Motor_CW,100);
			LCD_moveCursor(0,4);
			LCD_displayString("Fan is ON ");

		}

		/*Displaying the temperature through the LCD*/

		LCD_moveCursor(1,4);
		LCD_displayString("Temp = ");
		LCD_intgerToString(current_temperature);
		if(current_temperature<100 && current_temperature>9)
		{
			LCD_displayCharacter(' ');
		}
		else if (current_temperature<=9)
		{
			LCD_displayString("  ");
		}
		LCD_moveCursor(1,15);
		LCD_displayCharacter('C');

		/*Return cursor to intial position*/
		LCD_moveCursor(0,0);

	}

	return 0;
}


