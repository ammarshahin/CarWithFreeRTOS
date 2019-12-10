/*
 * PWM.h
 * Description : This file is used to control the PWM in the MCU
 * Created: 10/12/2019 3:27:00 PM
 *  Author: Ammar Shahin
 */ 

#ifndef PWM_H_
#define PWM_H_

/************************************************************************/
/*                            INCLUDES                                  */
/************************************************************************/
#include <stdint.h>

/************************************************************************/
/*                        Functions Prototypes                          */
/************************************************************************/
/**
 * Function :  PWM_PhaseCorrect
 * Description: PWM_PhaseCorrect is a function to initiate a PWM on a GPIO pin OC1 
 * @param dutyCycle the duty cycle of the PWM in percentage
 * @param freq the frequency of the PWM in Hz
 */
void PWM_Init();

/**
 * Function :  PWM_PhaseCorrect
 * Description: PWM_PhaseCorrect is a function to initiate a PWM on a GPIO pin OC1 
 * @param dutyCycle the duty cycle of the PWM in percentage
 * @param freq the frequency of the PWM in Hz
 */
void PWM_SetDutyCycle( uint32_t dutycycle );
#endif /* PWM_H_ */
