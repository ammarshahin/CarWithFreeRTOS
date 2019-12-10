/*
* Car_Control.c
*
* Created: 10/12/2019 1:51:29 PM
*  Author: Ammar Shahin
*/


/************************************************************************/
/*                        Files Includes                                */
/************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "sysctl.h"
#include "interrupt.h"
#include "gpio.h"
#include "timer.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks.h"
#include "pin_map.h"
#include "hw_gpio.h"
#include "pin_map.h"
#include "DC_Motor.h"
//#include "Ultrasonic.h"
#include "CarControl.h"
/************************************************************************/
/*                         Macros and Defines                           */
/************************************************************************/
#define SLOW_SPEED 30
#define FAST_SPEED 100
#define NORMAL_SPEED 50

#define CAUTIOUS_DISTANCE 40
#define DENGEROUS_DISTANCE 20
/************************************************************************/
/*                        Functions Definitions                         */
/************************************************************************/

/**
 * Function : Car_Init
 * Description: This function is to initialize the car 
 *  it Don't take any thing and returns nothing
 */
void Car_Init(void)
{
    DC_Motor_Init(DC_MOTOR_CHANNEL_0);
    DC_Motor_Init(DC_MOTOR_CHANNEL_1);

    Move_Forward();
}


/**
 * Function : CarControlLogic
 * Description: This function is to Implement the car logic 
 *  it Don't take any thing and returns nothing
 */
void CarControlLogic( uint32_t ultrasonicDistanc)
{
    if(ultrasonicDistanc > CAUTIOUS_DISTANCE) /* No obstacle Go Forward */
	{
		Move_Forward();
		DC_Motor_Set_Speed(FAST_SPEED);
	}
	else if ( (ultrasonicDistanc < CAUTIOUS_DISTANCE) && (ultrasonicDistanc > DENGEROUS_DISTANCE) )  /* Obstacle on the near range */
	{
		Move_RotateRight();
		DC_Motor_Set_Speed(NORMAL_SPEED);
	}
	else if(ultrasonicDistanc < DENGEROUS_DISTANCE)  /* Obstacle is very near go back till an enough range to rotate */
	{
		DC_Motor_Set_Speed(SLOW_SPEED);
		Move_Backward();
	}
}

/**
 * Function : Move_Forward
 * Description: This function is to make car move forward
 *  it take nothing and returns nothing
 */

void Move_Forward(void)
{
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
}

/**
 * Function : Move_Backward
 * Description: This function is to make car move Backward
 *  it take nothing and returns nothing
 */
void Move_Backward(void)
{
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
}

/**
 * Function : Move_RotateRight
 * Description: This function is to make car Rotate Right
 *  it take nothing and returns nothing
 */
void Move_RotateRight(void)
{
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
}

/**
 * Function : move_RotateLeft
 * Description: This function is to make car Rotate Left
 *  it take nothing and returns nothing
 */
void Move_RotateLeft(void)
{
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
}


/**
 * Function : Stop
 * Description: This function is to make car Stop
 *  it take nothing and returns nothing
 */

void Stop(void)
{
    DC_Motor_Stop(DC_MOTOR_CHANNEL_0);
    DC_Motor_Stop(DC_MOTOR_CHANNEL_1);
}
/*
carLogic(ultrasonicDistanc);
         DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
         DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
         vTaskDelay(500);
         DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
         //DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
*/
