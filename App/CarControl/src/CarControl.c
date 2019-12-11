/*
* Car_Control.c
*
* Created: 10/12/2019 1:51:29 PM
*  Author: Ammar Shahin
*/


/************************************************************************/
/*                        Files Includes                                */
/************************************************************************/
#include <PWMCar.h>
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
#include "CarControl.h"
/************************************************************************/
/*                         Macros and Defines                           */
/************************************************************************/
#define SLOW_SPEED 50
#define NORMAL_SPEED 50

#define COUTUS_DISTANCE 40
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
    PWM_Init();

    DC_Motor_Init(DC_MOTOR_CHANNEL_0);
    DC_Motor_Init(DC_MOTOR_CHANNEL_1);

    CarStop();
}


/**
 * Function : CarControlLogic
 * Description: This function is to Implement the car logic 
 *  it Don't take any thing and returns nothing
 */
void CarControlLogic( uint32_t UltrasonicDistance)
{
    if( (UltrasonicDistance > DENGEROUS_DISTANCE) && (UltrasonicDistance < COUTUS_DISTANCE ))
    {
        CarStop();
//                vTaskDelay(10);
                DC_Motor_Set_Speed(SLOW_SPEED);
                CarMove__RotateRight();
                vTaskDelay(300);
                //CarStop();
                //vTaskDelay(10);
    }
    else if ( UltrasonicDistance < DENGEROUS_DISTANCE )  /* Obstacle on the near range */
	{
        CarStop();
//        vTaskDelay(10);
        DC_Motor_Set_Speed(SLOW_SPEED);
        CarMove__Backward();
        vTaskDelay(200);
	}
	else
	{
	    DC_Motor_Set_Speed(NORMAL_SPEED);
	    CarMove__Forward();
	}
}

/**
 * Function : CarMove__Forward
 * Description: This function is to make car CarMove_ forward
 *  it take nothing and returns nothing
 */
void CarMove__Forward(void)
{
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
}

/**
 * Function : CarMove__Backward
 * Description: This function is to make car CarMove_ Backward
 *  it take nothing and returns nothing
 */
void CarMove__Backward(void)
{
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
}

/**
 * Function : CarMove__RotateRight
 * Description: This function is to make car Rotate Right
 *  it take nothing and returns nothing
 */
void CarMove__RotateRight(void)
{
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
}

/**
 * Function : CarMove__RotateLeft
 * Description: This function is to make car Rotate Left
 *  it take nothing and returns nothing
 */
void CarMove__RotateLeft(void)
{
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
    DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
}


/**
 * Function : Stop
 * Description: This function is to make car Stop
 *  it take nothing and returns nothing
 */
void CarStop(void)
{
    DC_Motor_Stop(DC_MOTOR_CHANNEL_0);
    DC_Motor_Stop(DC_MOTOR_CHANNEL_1);
}
