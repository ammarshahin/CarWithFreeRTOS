/*
 * Ext_Int.c
 *
 * Created: 11/9/2019 8:09:38 PM
 *  Author: AVE-LAP-025
 */ 

/**
 * 	
 *	This file is a source file that contains External interrupt functions'
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
#include "Ext_Int.h"


void (*ptr)(void);

/*This function initializes specific External interrupt*/
void ExtInt_Init(void)
{

/*
    Register the port-level interrupt handler. This handler is the first
    * level interrupt handler for all the pin interrupts.
*/

   GPIOIntRegister(GPIO_PORTF_BASE, PortAIntHandler);
/*

    Initialize the GPIO pin configuration.
    *
    * Set pins 2, 4, and 5 as input, SW controlled.
*/

   GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4 );

   //
   // Make pins 2 and 4 rising edge triggered interrupts.
   //
   GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4 , GPIO_RISING_EDGE);



   /* Enable the pin interrupts. -------------------------------*/

   GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4);
}


void PortAIntHandler(void)
{
    GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);
    ptr();

}

void CallBack(void (*ptr1)(void))
{
     ptr = ptr1;
}
