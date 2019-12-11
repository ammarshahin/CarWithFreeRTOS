/*
 * Ultrasonic.c
 *
 * Created: 11/9/2019 8:08:56 PM
 *  Author: AVE-LAP-025
 */ 
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

void delayUS(uint32 ms)
{
   SysCtlDelay( (SysCtlClockGet()/(3*1000000))*ms );
}

/*initialize the ultrasonic */
void initializeUltraSonic(void)
{
    GPIOPinTypeGPIOOutput(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN);
    SwICU_Init();
}

/*trigger ultrasonic trigger pin*/

void triggerUltrasonic(void)
{
    GPIOPinWrite(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, 0x80);
    delayUS(15);
	GPIOPinWrite(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, 0x00);
}

/*function to return number of counts which will be used to calculate the distance*/

uint32_t calculateDistance(void)
{
	uint32 Reading_value=0;
	uint32 distance=0;
	SwICU_Read(&Reading_value);
	distance = (Reading_value / (double)SysCtlClockGet()) * 17000;
	return distance;
}
