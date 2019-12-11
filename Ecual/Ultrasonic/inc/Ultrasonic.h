/*
 * Ultrasonic.h
 *
 * Created: 11/9/2019 8:08:43 PM
 *  Author: AVE-LAP-025
 */ 

/**
 * 	
 *	This file is a header file that contains prototypes of Ultrasonic functions'
 *	prototypes and description.
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#include "Std_Types.h"
#include "UltrasonicCfg.h"

/*
 * Description:
 * This function initializes the Ultrasonic
 * Parameter: void
 * Return : void
 */

void initializeUltraSonic(void);


/*
 * Description:
 * This function triggers the Ultrasonic trigger pin
 * Parameter: void
 * Return : void
 */

void triggerUltrasonic(void);


/*
 * Description:
 * This function returns number of counts which will be used to calculate the distance
 * Parameter: void
 * Return : Distance calculated
 */

uint32 calculateDistance(void);

#endif /* ULTRASONIC_H_ */
