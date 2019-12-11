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
#include "LCD_t.h"
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
     vTaskSuspend(CarTaskLogic_Handle);
     vTaskSuspend(Ultarsonic_Task_Handle);

     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

     initializeUltraSonic();
     Car_Init();
     LCD_init();

     vTaskResume(CarTaskLogic_Handle);
     vTaskResume(Ultarsonic_Task_Handle);


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
         vTaskDelay(55);
     }
}


 void UltrasonicTask(void* pvParameters)
 {
     while(true)
     {
         triggerUltrasonic();
         ultrasonicDistanc = calculateDistance();
         if( ultrasonicDistanc > 100 )
         {
             ultrasonicDistanc = 99;
         }
         else
         {
             //Do Nothing
         }
         LCD_clearScreen();
         LCD_intgerToString(ultrasonicDistanc);
         vTaskDelay(100);
     }
 }
