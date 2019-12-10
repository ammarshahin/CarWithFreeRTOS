/*
 * Tasks.c
 *
 * Created: 11/30/2019 2:42:20 PM
 *  Author: Ammar Shahin
 */ 

/************************************************************************/
/*								INCLUDES						        */
/************************************************************************/
#include <PWM_t.h>
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "sysctl.h"
#include "interrupt.h"
#include "gpio.h"
#include "timer.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks.h"
#include "pin_map.h"
#include "hw_gpio.h"
#include "pin_map.h"
#include "CarControl.h"

/************************************************************************/
/*								Defines  						        */
/************************************************************************/
#define  TASK_DELAY_SYSTICK 1000

/************************************************************************/
/*					      Global Variables						        */
/************************************************************************/
 TaskHandle_t Init_Task_Handle;
 TaskHandle_t CarTaskLogic_Handle;

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
     PWM_Init();
     //Ultrasonic_Init();
     Car_Init();

     BaseType_t xReturned = false;

    xReturned = xTaskCreate(CarTaskLogic,
    "CarTaskLogic",
    configMINIMAL_STACK_SIZE,
    NULL,
    CarTaskLogic_PRIORITY,
    &CarTaskLogic_Handle
    );

    if( xReturned != pdPASS )
    {
         // Error Handling Code
    }

    vTaskSuspend(Init_Task_Handle);
}

/**
 * Description: This Task is used to Toggle the the Leds
 * @param port : input parameter to the Task
 * Return : void
 */
 void CarTaskLogic(void* pvParameters)
{
     uint32_t ultrasonicDistanc = false;

     while(1)
     {
         ultrasonicDistanc = 20;
         CarControlLogic(ultrasonicDistanc);
         vTaskDelay(500);
     }

}

void Timer0IntHandler(void)
{

}
