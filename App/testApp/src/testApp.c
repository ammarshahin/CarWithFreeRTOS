/*
 * testApp.c
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
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks.h"


/************************************************************************/
/*				      Main Function Implementation			            */
/************************************************************************/
int main(void)
 {
       SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_OSC_INT);

       uint32_t x= SysCtlClockGet();
       BaseType_t xReturned = 0;

        xReturned = xTaskCreate(Init_Task,
        "Initialization Task",
        configMINIMAL_STACK_SIZE,
        NULL,
        INIT_TASK_PRIORITY,
        &Init_Task_Handle
        );

        if( xReturned != pdPASS )
        {
             // Error Handling Code
        }

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

        xReturned = xTaskCreate(UltrasonicTask,
       "Ultarsonic Task",
       configMINIMAL_STACK_SIZE,
       NULL,
       Ultarsonic_TASK_PRIORITY,
       &Ultarsonic_Task_Handle
       );

       if( xReturned != pdPASS )
       {
            // Error Handling Code
       }

        /* Start Scheduler */
        vTaskStartScheduler();
}
