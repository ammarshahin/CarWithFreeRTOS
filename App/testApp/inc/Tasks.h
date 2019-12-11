/*
 * Tasks.h
 *
 * Created: 11/30/2019 2:42:06 PM
 *  Author: Ammar Shahin
 */ 


#ifndef TASKS_H_
#define TASKS_H_

/************************************************************************/
/*								Defines  						        */
/************************************************************************/


#define  INIT_TASK_PRIORITY             4
#define  Ultarsonic_TASK_PRIORITY       3
#define  CarTaskLogic_PRIORITY          2

/************************************************************************/
/*						Extern Global variables  				        */
/************************************************************************/
extern  TaskHandle_t Init_Task_Handle;
extern  TaskHandle_t Ultarsonic_Task_Handle;
extern  TaskHandle_t CarTaskLogic_Handle;

/************************************************************************/
/*					      OS Tasks Implementations				        */
/************************************************************************/
/**
 * Description: This Task is used to Init the System [Leds]
 * @param pvParameters : input parameter to the Task
 * Return : void
 */
void Init_Task(void* pvParameters);

/**
 * Description: This Task is used to Apply the logic of the Car Control
 * @param pvParameters : input parameter to the Task
 * Return : void
 */
void CarTaskLogic(void* pvParameters);

/**
 * Description: This Task is used to get the Distance of the Ultrasonic and send it to the CarTaskLogic
 * @param pvParameters : input parameter to the Task
 * Return : void
 */
void UltrasonicTask(void* pvParameters);

#endif /* TASKS_H_ */
