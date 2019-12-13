/*
 * Icu.c
 *
 * Created: 11/9/2019 8:08:25 PM
 *  Author: Diana Atef
 */ 

/**
 * 	
 *	This file is a source file that contains prototypes of ICU functions'
 *	prototypes and description.
 */
/*******************************************************************************
 *                                  INCLUDES                                   *
 *******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "sysctl.h"
#include "interrupt.h"
#include "gpio.h"
#include "timer.h"
#include "Icu.h"
#include "Ext_Int.h"

/*******************************************************************************
 *                                  Macros                                    *
 *******************************************************************************/
#define TIMER_SET_FACTOR 120000000


/*******************************************************************************
                         Global Varibles                                      *
 *******************************************************************************/
volatile uint16 number_of_overflows;
volatile uint16 previous_number_of_overflows;
volatile uint16 flag = false;
volatile uint8 duration;
volatile uint32 TON = false;

/*******************************************************************************
                                 Definitions                                    *
 *******************************************************************************/
void startCalculationIcu(void)
{
    static uint32_t T0,T1;

    if(flag == false)
    {

        T0 = TimerValueGet(TIMER0_BASE,TIMER_A);

        flag = true;

        GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4 , GPIO_FALLING_EDGE);
    }

    else if(flag == true)
    {
        T1 = TimerValueGet(TIMER0_BASE,TIMER_A);

        if(T1>T0)
        {
            TON = TIMER_SET_FACTOR - T1 + T0 ;
        }
        else
        {
            TON =(T0-T1);
        }

        flag = false;
        GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4 , GPIO_RISING_EDGE);

    }
}

void Timer0Isr(void)
{
   TimerIntClear(TIMER0_BASE, TIMER_A);
}

/*This function initializes the ICU module */
void  SwICU_Init(void)
{
    CallBack(startCalculationIcu);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER0_BASE,TIMER_A,TIMER_SET_FACTOR);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    IntEnable(INT_TIMER0A);
    TimerEnable(TIMER0_BASE, TIMER_A);
    ExtInt_Init();
}

void SwICU_Read(uint32 *Reading_value)
{

    *Reading_value = TON;

}

void ICU_Enable(void)
{
    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4);
}
