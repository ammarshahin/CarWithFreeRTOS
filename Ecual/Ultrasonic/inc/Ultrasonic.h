/*
 * Ultrasonic.h
 *
 * Created: 12/11/2019
 *  Author: Diana Atef
 */ 
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/************************************************************************/
/*                             INCLUDES                                 */
/************************************************************************/
#include "Std_Types.h"
#include "UltrasonicCfg.h"


/************************************************************************/
/*                     Functions Prototypes                             */
/************************************************************************/
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
 * Description: calculateDistance
 * This function returns the distance
 * Parameter: void
 * Return : Distance calculated
 */
uint32_t calculateDistance(void);

/*
 * Description: UltrasonicGetDistanc
 * This function is used to get the distance of the Ultrasonic
 * Parameter: pUltrasonicDistanc pointer to the variable to set the distance to
 * Return : void
 */
void UltrasonicGetDistanc(uint32_t* pUltrasonicDistanc);

/*
 * Description: UltrasonicSetDistanc
 * This function is used to Set the distance of the Ultrasonic
 * Parameter: pUltrasonicDistanc the value to set the distance to
 * Return : void
 */
void UltrasonicSetDistanc(uint32_t pUltrasonicDistanc);

#endif /* ULTRASONIC_H_ */
