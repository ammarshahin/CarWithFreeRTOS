/*
 * Ext_Int.h
 *
 * Created: 11/9/2019 8:09:24 PM
 *  Author: AVE-LAP-025
 */ 

/**
 * 	
 *	This file is a header file that contains prototypes of External interrupt functions'
 *	prototypes and description.
 */
#ifndef EXT_INT_H_
#define EXT_INT_H_

/************************************************************************/
/*				 Enum for all external interrupts                       */
/************************************************************************/

typedef enum 
{
	EXT_INT_0,
	EXT_INT_1,
	EXT_INT_2
}ExtInt_TypeDef;

/************************************************************************/
/*			         	 Enum for edge                                  */
/************************************************************************/

typedef enum 
{
	Sense_LowLevel,
	Sense_AnyLogicChange,
	Sense_FallingEdge,
	Sense_RisingEdge
}ExtIntSense_TypeDef;

/************************************************************************/
/*				 External interrupt functions' prototypes	            */
/************************************************************************/

/*
 * Description:
 * This function initializes specific External interrupt  
 * Parameter: Input: ext interrupt number
 *			  Type: ExtInt_TypeDef 
 *			  Input: ext interrupt sense either rising or falling
 *			  Type: ExtIntSense_TypeDef
 *			  Output: void
 * Return : void
 */

void ExtInt_Init(void);

void PortAIntHandler(void);

void CallBack(void (*ptr1)(void));

#endif /* EXT_INT_H_ */
