/*
 * Icu.h
 *
 * Created: 11/9/2019 8:08:14 PM
 *  Author: AVE-LAP-025
 */ 

/**
 * 	
 *	This file is a header file that contains prototypes of ICU functions'
 *	prototypes and description.
 */

#ifndef ICU_H_
#define ICU_H_

#include "Std_Types.h"

void delayUS(uint32 ms);

void CallBack(void (*ptr1)(void));

void startCalculationIcu(void);

void Timer0Isr(void);

void PortAIntHandler(void);
/*
 * Description:
 * This function initializes the ICU module 
 * Parameter: void
 * Return : void
 */
void  SwICU_Init(void);
/*
 * Description:
 * This function Reads all Timer 0 counts (Including overflow ) 
 * Parameter: void
 * Return : Reading value
 */
void SwICU_Read(uint32 *Reading_value);

void ICU_Enable(void);


#endif /* ICU_H_ */
