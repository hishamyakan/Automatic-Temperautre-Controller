/*
 ************************************** Included files******************************************
 */

#include "gpio.h"
#include "Macros.h"
#include<avr/io.h>




/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,GPIO_PinDirectionType direction)
{
	if(port_num>=0 && port_num<4 && pin_num>=0 && pin_num<8)
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
				SET_BIT(DDRA,pin_num);
			else
				CLEAR_BIT(DDRA,pin_num);
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
				SET_BIT(DDRB,pin_num);
			else
				CLEAR_BIT(DDRB,pin_num);
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
				SET_BIT(DDRC,pin_num);
			else
				CLEAR_BIT(DDRC,pin_num);
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
				SET_BIT(DDRD,pin_num);
			else
				CLEAR_BIT(DDRD,pin_num);
			break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */

void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 value)
{
	if(port_num>=0 && port_num<4 && pin_num>=0 && pin_num<8)
	{
		if(value == LOGIC_HIGH)
		{
			switch(port_num)
			{
			case PORTA_ID:
				SET_BIT(PORTA, pin_num);
				break;
			case PORTB_ID:
				SET_BIT(PORTB, pin_num);
				break;
			case PORTC_ID:
				SET_BIT(PORTC, pin_num);
				break;
			case PORTD_ID:
				SET_BIT(PORTD, pin_num);
				break;
			}
		}
		else
		{

			switch(port_num)
			{
			case PORTA_ID:
				CLEAR_BIT(PORTA, pin_num);
				break;
			case PORTB_ID:
				CLEAR_BIT(PORTB, pin_num);
				break;
			case PORTC_ID:
				CLEAR_BIT(PORTC, pin_num);
				break;
			case PORTD_ID:
				CLEAR_BIT(PORTD, pin_num);
				break;
			}
		}

	}
}


/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num,uint8 pin_num)
{
	uint8 returnValue = 0;
	if(port_num>=0 && port_num<4 && pin_num>=0 && pin_num<8)
	{
		switch(port_num)
				{
				case PORTA_ID:
					returnValue = GET_BIT(PINA,pin_num);
					break;
				case PORTB_ID:
					returnValue = GET_BIT(PINB,pin_num);
					break;
				case PORTC_ID:
					returnValue = GET_BIT(PINC,pin_num);
					break;
				case PORTD_ID:
					returnValue = GET_BIT(PIND,pin_num);
					break;
				}

	}
	return returnValue;
}

void GPIO_setupPortDirection(uint8 port_num,GPIO_PortDirectionType direction)
{
	switch(port_num)
		{
			case PORTA_ID:
				DDRA = direction;
				break;
			case PORTB_ID:
				DDRB = direction;
				break;
			case PORTC_ID:
				DDRC = direction;
				break;
			case PORTD_ID:
				DDRD = direction;
				break;
			}
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num,uint8 value)
{
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
	switch(port_num)
		{
			case PORTA_ID:
				PORTA = value;
				break;
			case PORTB_ID:
				PORTB = value;
				break;
			case PORTC_ID:
				PORTC = value;
				break;
			case PORTD_ID:
				PORTD = value;
				break;
			}
	}
}


/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 returnValue = 0;
	if(port_num >= NUM_OF_PORTS)
		{
			/* Do Nothing */
		}
	else
		{
	switch(port_num)
			{
				case PORTA_ID:
					returnValue = PINA;
					break;
				case PORTB_ID:
					returnValue = PINB;
					break;
				case PORTC_ID:
					returnValue = PINC;
					break;
				case PORTD_ID:
					returnValue = PIND;
					break;
				}
		}
	return returnValue;
}

/*
 * Description :
 *  enable the internal pull up resistance
 */
void GPIO_internalPullUpPinEnable(uint8 port_num,uint8 pin_num)
{
	switch(port_num)
		{
			case PORTA_ID:
				SET_BIT(PORTA,pin_num);
				break;
			case PORTB_ID:
				SET_BIT(PORTB,pin_num);;
				break;
			case PORTC_ID:
				SET_BIT(PORTC,pin_num);;
				break;
			case PORTD_ID:
				SET_BIT(PORTD,pin_num);;
				break;
		}
}
