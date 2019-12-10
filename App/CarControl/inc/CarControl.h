/*
 * Car_Control.h
 *
 *  Created on: Nov 5, 2019
 *      Author: AVE-LAP-052
 */

#ifndef CAR_CONTROL_H_
#define CAR_CONTROL_H_

/************************************************************************/
/*                        Functions Prototypes                          */
/************************************************************************/
/**
 * Function : Car_Init
 * Description: This function is to initialize the car 
 *  it Don't take any thing and returns nothing
 */
void Car_Init(void);

/**
 * Function : CarControlLogic
 * Description: This function is to Implement the car logic 
 *  it Don't take any thing and returns nothing
 */
void CarControlLogic( uint32_t ultrasonicDistanc);


/************************************************************************/
/*               Direction Control functions' Prototypes                */
/************************************************************************/
/**
 * Function : Move_Forward
 * Description: This function is to make car move forward
 *  it take nothing and returns nothing
 */
void Move_Forward(void);

/**
 * Function : Move_Backward
 * Description: This function is to make car move Backward
 *  it take nothing and returns nothing
 */
void Move_Backward(void);


/**
 * Function : Move_RotateRight
 * Description: This function is to make car Rotate Right
 *  it take nothing and returns nothing
 */
void Move_RotateRight(void);

/**
 * Function : move_RotateLeft
 * Description: This function is to make car Rotate Left
 *  it take nothing and returns nothing
 */
void Move_RotateLeft(void);

/**
 * Function : Stop
 * Description: This function is to make car Stop
 *  it take nothing and returns nothing
 */
void Stop(void);

#endif /* CAR_CONTROL_H_ */
