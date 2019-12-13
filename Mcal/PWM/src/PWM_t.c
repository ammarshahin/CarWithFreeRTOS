/*
 * PWM.c
 * Description : This file is used to control the PWM in the MCU
 * Created: 10/12/2019 3:27:00 PM
 *  Author: Ammar Shahin
 */ 

/************************************************************************/
/*								INCLUDES						        */
/************************************************************************/
#include <stdint.h>
#include <stdbool.h>
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
#include "PWMCar.h"
#include "pwm.h"

/************************************************************************/
/*                           Macros and Defines                         */
/************************************************************************/
#define MAX_VALUE_PWM   5000
#define ONE_HUNDERD     100

/************************************************************************/
/*                        Functions Definitions                         */
/************************************************************************/
/**
 * Function :  PWM_PhaseCorrect
 * Description: PWM_PhaseCorrect is a function to initiate a PWM
 * @param dutyCycle the duty cycle of the PWM in percentage
 * @param freq the frequency of the PWM in Hz
 */

void PWM_Init(void)
{
	//Configure PWM Clock to match system
      SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

      //Enable the peripherals used by this program.
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 

       //Configure PF1,PF2,PF3 Pins as PWM
       GPIOPinConfigure(GPIO_PF1_M1PWM5);
       GPIOPinConfigure(GPIO_PF2_M1PWM6);
       GPIOPinConfigure(GPIO_PF3_M1PWM7);

       GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
		
		//Set the Period (expressed in clock ticks)
       PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, MAX_VALUE_PWM);
       PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, MAX_VALUE_PWM);
       PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, MAX_VALUE_PWM);
	   
	   PWM_SetDutyCycle(50);

       //Configure PWM Options
       PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
       PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_SYNC);

       // Enable the PWM generator
       PWMGenEnable(PWM1_BASE, PWM_GEN_2);
       PWMGenEnable(PWM1_BASE, PWM_GEN_3);

       // Turn on the Output pins
       PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, true);
}

/**
 * Function :  PWM_PhaseCorrect
 * Description: PWM_PhaseCorrect is a function to initiate a PWM on a GPIO pin OC1 
 * @param dutyCycle the duty cycle of the PWM in percentage
 */

void PWM_SetDutyCycle( uint32_t dutycycle )
{
    uint32_t WidthSetValue = (MAX_VALUE_PWM * dutycycle) / ONE_HUNDERD;

       //Set PWM duty
       PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, WidthSetValue);
       PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, WidthSetValue);
       PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, WidthSetValue);
}
