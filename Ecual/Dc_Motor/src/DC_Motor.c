/*
 * DC_Motor.c
 * Description : This file is used to control the motor channels.
 * Created: 11/5/2019 1:06:51 PM
 *  Author: Ammar Shahin
 */ 

/************************************************************************/
/*				              Files Includes                            */
/************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "PWM_t.h"
#include "tm4c123gh6pm.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "sysctl.h"
#include "interrupt.h"
#include "gpio.h"
#include "FreeRTOS.h"
#include "timer.h"
#include "task.h"
#include "pin_map.h"
#include "hw_gpio.h"
#include "pin_map.h"
#include "DC_Motor.h"

/************************************************************************/
/*                               Macros                                 */
/************************************************************************/

#define ONE_HUNDERED 100

/************************************************************************/
/*				          Data Types and Defines                        */
/************************************************************************/

/**
 * Function : DC_Motor_Init
 * Description : This function is used to initialize the DC motor channels
 * @pram  Channel  : is the channel that the user want to initialize [DC_MOTOR_CHANNEL_0 or DC_MOTOR_CHANNEL_1]
 * Return : the function Returns nothing
 */
void DC_Motor_Init( uint32_t Channel)
{
	switch(Channel)
	{
		case DC_MOTOR_CHANNEL_0 : 
			/* Initiate the Motor pin Direction */
		    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
		    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_2);
		break;
		case DC_MOTOR_CHANNEL_1 : 
            /* Initiate the Motor pin Direction */
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
            GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_1|GPIO_PIN_3);
		break;
		default:
		break;
	}
}

/**
 * Function : DC_Motor_Set_Speed
 * Description : This function is used to set the speed of the motor
 * @pram  Speed : Set the speed of the motor to this much
 * Return : void
 */
void DC_Motor_Set_Speed(uint32_t Speed)
{
	if(Speed <= ONE_HUNDERED)
	{
	    PWM_SetDutyCycle(Speed);

	}
	else
	{
	    // Do Nothing
	}
}

/**
 * Function : DC_Motor_Set_Direction
 * Description : This function is used to set the Direction of the motor Channel.
 * @pram  Channel : Set the Channel of the motor.
 * @pram  Direction : Set the Direction of the motor Channel.
 * Return : void.
 */
void DC_Motor_Set_Direction(uint32_t Channel , uint32_t Direction)
{
	switch(Channel)
	{
		case DC_MOTOR_CHANNEL_0 :
			switch(Direction)
			{
				case DC_MOTOR_FORWARD :
					/* Set the Motor pin */
				    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_2, 0x01);
				    //GPIOPinWrite(GPIO_PORTD_BASE, , 0);
				break;
				case DC_MOTOR_BACK : 
					/* Set the Motor pin */
				    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_2, 0x04);
				    //GPIOPinWrite(GPIO_PORTD_BASE, , 2);
				break;
				default:
				break;
			}
		break;
		case DC_MOTOR_CHANNEL_1 :
			switch(Direction)
			{
				case DC_MOTOR_FORWARD :
					/* Set the Motor pin */
				    GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_3 | GPIO_PIN_1, 0x02);
				    //GPIOPinWrite(GPIO_PORTD_BASE, , 4);
				break;
				case DC_MOTOR_BACK :
					/* Set the Motor pin */
				    GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_3 | GPIO_PIN_1, 0x08);
				    //GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 4);
				break;
				default:
				break;
			}
			break;
	}
}

/**
 * Function : DC_Motor_Stop
 * Description : This function is used to Stop the motor Channel.
 * @pram  Channel : Set the Channel of the motor.
 * Return : the function Returns Nothing.
 */
void DC_Motor_Stop(uint32_t Channel)
{
	switch(Channel)
	{
		case DC_MOTOR_CHANNEL_0 :
		    GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2 | GPIO_PIN_0, 0x00);
		    break;
		case DC_MOTOR_CHANNEL_1 : 
		    GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_3 | GPIO_PIN_1, 0x00);
		    break;
		default:
		    break;
	}		
}


#if 0
/**
 * Function : DC_Motor_Start
 * Description : This function is used to Start the motor Channel.
 * @pram  Channel : Set the Channel of the motor.
 * Return : the function Returns Nothing.
 */
void DC_Motor_Start(uint8 Channel)
{
	DC_Motor_Set_Speed(DEFAULT_SPEED);
	Timers_timer1_Start();
	DC_Motor_Set_Direction(Channel,DC_MOTOR_FORWARD); // Move Forward as A default Direction
}
#endif
