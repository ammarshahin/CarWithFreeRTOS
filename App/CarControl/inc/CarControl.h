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
 * Function : CarMove__Forward
 * Description: This function is to make car CarMove_ forward
 *  it take nothing and returns nothing
 */
void CarMove__Forward(void);

/**
 * Function : CarMove__Backward
 * Description: This function is to make car CarMove_ Backward
 *  it take nothing and returns nothing
 */
void CarMove__Backward(void);


/**
 * Function : CarMove__RotateRight
 * Description: This function is to make car Rotate Right
 *  it take nothing and returns nothing
 */
void CarMove__RotateRight(void);

/**
 * Function : CarMove__RotateLeft
 * Description: This function is to make car Rotate Left
 *  it take nothing and returns nothing
 */
void CarMove__RotateLeft(void);

/**
 * Function : Stop
 * Description: This function is to make car Stop
 *  it take nothing and returns nothing
 */
void CarStop(void);

#endif /* CAR_CONTROL_H_ */
