/*
 * Tasks.c
 *
 * Created: 11/30/2019 2:42:20 PM
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
#include "timer.h"
#include "PWM.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks.h"
#include "pin_map.h"
#include "hw_gpio.h"
#include "pin_map.h"
#include "CarControl.h"
#include "LCD.h"
#include "Ultrasonic.h"

/************************************************************************/
/*								Defines  						        */
/************************************************************************/
#define  TASK_DELAY_SYSTICK 1000

/************************************************************************/
/*					      Global Variables						        */
/************************************************************************/
 TaskHandle_t Init_Task_Handle;
 TaskHandle_t Ultarsonic_Task_Handle;
 TaskHandle_t CarTaskLogic_Handle;

 volatile uint32_t ultrasonicDistanc;
/************************************************************************/
/*					      OS Tasks Implementations				        */
/************************************************************************/
/**
 * Description: This Task is used to Init the System [Leds]
 * @param port : input parameter to the Task
 * Return : void
 */
 void Init_Task(void* pvParameters)
{
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
     //LCD_init();
     initializeUltraSonic();
     Car_Init();

     //GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3); // Debug Led

    vTaskSuspend(Init_Task_Handle);

    while(true)
    {
        // Never going to reach this line
    }
}

/**
 * Description: This Task is used to Toggle the the Leds
 * @param port : input parameter to the Task
 * Return : void
 */
 void CarTaskLogic(void* pvParameters)
{

     while(1)
     {
         CarControlLogic(ultrasonicDistanc);
         vTaskDelay(200);
     }
}


 void UltrasonicTask(void* pvParameters)
 {
     while(true)
     {
         triggerUltrasonic();
         ultrasonicDistanc = calculateDistance();
         LCD_DisplayNumber(ultrasonicDistanc);
         vTaskDelay(100);
     }
 }
