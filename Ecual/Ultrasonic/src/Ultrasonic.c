/*
 * Ultrasonic.c
 *
 * Created: 11/12/2019
 *  Author: Diana Atef
 */ 

/************************************************************************/
/*                              INCLUDES                                */
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
#include "Ultrasonic.h"
#include "Icu.h"

/************************************************************************/
/*                            Macros                                    */
/************************************************************************/
#define DISTANCE_FACTOR  17000
#define SYSCTL_DELAY_MS_FACTOR (3*1000000)
#define SYSCTL_DELAY      15

#define ULTRASONIC_TRIGGER_PIN_MASK1 0x80
#define ULTRASONIC_TRIGGER_PIN_MASK2 0x00

/************************************************************************/
/*                         Global variables                             */
/************************************************************************/
volatile uint32_t UltrasonicDistanc;

/************************************************************************/
/*                     Functions Implementations                        */
/************************************************************************/
/*initialize the ultrasonic */
void initializeUltraSonic(void)
{
    GPIOPinTypeGPIOOutput(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN);
    SwICU_Init();
}

/*trigger ultrasonic trigger pin*/

void triggerUltrasonic(void)
{
    GPIOPinWrite(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, ULTRASONIC_TRIGGER_PIN_MASK1);
    vTaskDelay(SYSCTL_DELAY);
	GPIOPinWrite(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, ULTRASONIC_TRIGGER_PIN_MASK2);
}

/*function to return number of counts which will be used to calculate the distance*/

uint32_t calculateDistance(void)
{
	uint32 Reading_value = false;
	uint32 distance = false;
	SwICU_Read(&Reading_value);
	distance = (Reading_value / (double)SysCtlClockGet()) * DISTANCE_FACTOR;
	return distance;
}

void UltrasonicGetDistanc(uint32_t* pUltrasonicDistanc)
{
    *pUltrasonicDistanc = UltrasonicDistanc;
}

void UltrasonicSetDistanc(uint32_t pUltrasonicDistanc)
{
    UltrasonicDistanc = pUltrasonicDistanc;
}
