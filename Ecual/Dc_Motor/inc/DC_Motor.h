/*
 *  Dc_Motor.h
 *	Description : This file is used to control the motor channels.
 *  Created on: Nov 5, 2019
 *      Author: AVE-LABS-50
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/************************************************************************/
/*				              Files Includes                            */
/************************************************************************/
#include "Typedefs.h"

/************************************************************************/
/*				          Data Types and Defines                        */
/************************************************************************/
#define DC_MOTOR_BACK	      0
#define DC_MOTOR_FORWARD      1

#define DC_MOTOR_CHANNEL_0 	  0
#define DC_MOTOR_CHANNEL_1	  1

/************************************************************************/
/*				         DC Motors functions' Prototypes                */
/************************************************************************/

/**
 * Function : DC_Motor_Init
 * Description : This function is used to initialize the DC motor channels
 * @pram  Channel  : is the channel that the user want to initialize [DC_MOTOR_CHANNEL_0 or DC_MOTOR_CHANNEL_1]
 * Return : the function Returns nothing
 */
void DC_Motor_Init(uint32_t Channel);

/**
 * Function : DC_Motor_Set_Speed
 * Description : This function is used to set the speed of the motor
 * @pram  Speed : Set the speed of the motor to this much
 * Return : the function Returns uint8 to describe the status of the speed setting (OK Or Not_OK)
 */
void DC_Motor_Set_Speed(uint32_t Speed);

/**
 * Function : DC_Motor_Set_Direction
 * Description : This function is used to set the Direction of the motor Channel.
 * @pram  Channel : Set the Channel of the motor.
 * @pram  Direction : Set the Direction of the motor Channel.
 * Return : the function Returns uint8 to describe the status of the Direction setting (OK Or Not_OK).
 */
void DC_Motor_Set_Direction(uint32_t Channel , uint32_t Direction);

/**
 * Function : DC_Motor_Stop
 * Description : This function is used to Stop the motor Channel.
 * @pram  Channel : Set the Channel of the motor.
 * Return : the function Returns Nothing.
 */
void DC_Motor_Stop(uint32_t Channel);

/**
 * Function : DC_Motor_Start
 * Description : This function is used to Start the motor Channel.
 * @pram  Channel : Set the Channel of the motor.
 * Return : the function Returns Nothing.
 */
void DC_Motor_Start(uint32_t Channel);


#endif /* DC_MOTOR_H_ */
