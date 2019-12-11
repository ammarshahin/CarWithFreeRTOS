/*
 *
 * lcd.c
 *
 *  Created on: Nov 30, 2019
 *      Author: Osman
 */

/*******************************************************************************
 *                    				INCLUDES          	     	               *
 *******************************************************************************/
#include "lcd.h"
#include "FreeRTOS.h"
#include "task.h"
#include "pin_map.h"
#include <stdint.h>
#include <stdbool.h>
#include "hw_gpio.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "sysctl.h"
#include "pin_map.h"
#include "gpio.h"

/*******************************************************************************
 *                    			 LOCAL MACROS           	                   *
 *******************************************************************************/
#define DIGIT_LIMIT					16
#define	SELECT_COLOM_ONE			0x40
#define SELECT_COLOM_TWO			0x10
#define LAST_COLOM					0x50
#define CURSOR_BEGINNING			0x80
#define LAST_HALF_MASK				0xF0
#define MASK_FIRST_BITS				0x0F
#define CURSOR_AT_BEGINNING			0x80
#define MOVE_CURSOR					0xC0
#define CLEAR_SCREEN				0x01
#define INIT_PORT					0xFF
#define INIT_CONTROL				0x33
#define FOUR_BIT_MDOE				0x28
#define CURSOR_OFF					0x0c
#define ENTRY_MODE					0x06
#define INIT_CONTROL_TWO			0x32


/*******************************************************************************
 *                    		 FUNCTION DEFINITION          	                   *
 *******************************************************************************/


/*
	 * Function: LCD_sendCommand.
	 *
	 * @definition:Send a rewuired comman to the LCD.
	 *
	 * @param	Name		: Command
	 *			Type        : uint8_t
	 *			DESC		: Sending the command to the LCD.
	 *
	 *
	 @return: void.
	 *
	 */
void LCD_sendCommand(uint8_t command)
{


    GPIOPinWrite(GPIO_PORTA_BASE, RW|RS,false);
    vTaskDelay( ONE_MILLI );
    GPIOPinWrite(GPIO_PORTA_BASE, EN,EN);
    vTaskDelay( ONE_MILLI );
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,(command & LAST_HALF_MASK));
    vTaskDelay( ONE_MILLI );
    GPIOPinWrite(GPIO_PORTA_BASE, EN,false);
    vTaskDelay( ONE_MILLI );
    GPIOPinWrite(GPIO_PORTA_BASE, EN,EN);
    vTaskDelay( ONE_MILLI );
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,((command & MASK_FIRST_BITS)<<4));
    vTaskDelay( ONE_MILLI );
    GPIOPinWrite(GPIO_PORTA_BASE, EN,false);
    vTaskDelay( ONE_MILLI );


}

/*
	 * Function: LCD_displayCharacter.
	 *
	 * @definition: Displays a Character on the LCD.
	 *
	 * @param	Name		: data
	 *			Type        : uint8_t
	 *			DESC		: Sending the Character..
	 *
	 *
	 @return: void.
	 *
	 */

void LCD_displayCharacter(uint8_t data)
{

        GPIOPinWrite(GPIO_PORTA_BASE, RS,0x04);
       vTaskDelay( ONE_MILLI );
       GPIOPinWrite(GPIO_PORTA_BASE, EN,EN);
       vTaskDelay( ONE_MILLI );
       GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,(data&LAST_HALF_MASK));
       vTaskDelay( ONE_MILLI );
       GPIOPinWrite(GPIO_PORTA_BASE, EN,false);
       vTaskDelay( ONE_MILLI );
       GPIOPinWrite(GPIO_PORTA_BASE, EN,EN);
       vTaskDelay( ONE_MILLI );
       GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,((data&MASK_FIRST_BITS)<<4));
       vTaskDelay( ONE_MILLI );
       GPIOPinWrite(GPIO_PORTA_BASE, EN,false);
       vTaskDelay( ONE_MILLI );

}

/*
	 * Function: LCD_init.
	 *
	 * @definition:Initialize the LCD.
	 *
	 * @param:void
	 *
	 *
	 * @return: void.
	 *
	 */


void LCD_init (void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);

    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, RS|RW|EN);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);




		vTaskDelay( ONE_MILLI );						/* LCD Power ON delay always >15ms */
		LCD_sendCommand(INIT_CONTROL);
		LCD_sendCommand(INIT_CONTROL_TWO);		    	/* send for 4 bit initialization of LCD  */
		LCD_sendCommand(FOUR_BIT_MDOE);              	/* Use 2 line and initialize 5*7 matrix in (4-bit mode)*/
		LCD_sendCommand(CURSOR_OFF);              	    /* Display on cursor off*/
		LCD_sendCommand(ENTRY_MODE);
		vTaskDelay( ONE_MILLI );                        /* Increment cursor (shift cursor to right)*/
		LCD_sendCommand(CLEAR_SCREEN);              	/* Clear display screen*/
		vTaskDelay( ONE_MILLI );
		LCD_sendCommand (CURSOR_AT_BEGINNING);
}


/*
	 * Function: LCD_displayString.
	 *
	 * @definition: Displays a String on the LCD.
	 *
	 * @param	Name		: Str
	 *			Type        : uint8_t *
	 *			DESC		: Sending an Array of Characters..
	 *
	 *
	 @return: void.
	 *
	 */
void LCD_displayString(const char *Str)
{
	int string_Counter ;
	for(string_Counter = false; Str[string_Counter]!='\0'; string_Counter++)
	{
		LCD_displayCharacter(Str[string_Counter]);
	}
}

/*
	 * Function: LCD_displayStringRowColumn.
	 *
	 * @definition: Function to Create A task.
	 *
	 * @param	Name		: row
	 *			Type        : uint8_t
	 *			DESC		: Determines the required Row.
	 *
	 * @param	Name		: col
	 *			Type        : uint8_t
	 *			DESC		: Determines the required Col.
	 *
	 * @param	Name		: Str
	 *			Type        : uint8_t*
	 *			DESC		: Sending An Array of Characters.
	 *
	 @return: void
	 *
	 */

void LCD_displayStringRowColumn(uint8_t row,uint8_t col, char* Str)
{
	if (row == false && col<DIGIT_LIMIT)
	{
		LCD_sendCommand((col & MASK_FIRST_BITS)|CURSOR_AT_BEGINNING);
	}
	else if (row == true && col<DIGIT_LIMIT)
	{
		LCD_sendCommand((col & MASK_FIRST_BITS)|MOVE_CURSOR);
	}

	else
	{

	}
	LCD_displayString(Str);
}


LCD_DisplayNumber(uint8_t Number)
{
    }


/*
 * Function: LCD_clearScreen.
 *
 * @definition: Clear the Screen.
 *
 * @param:void
 *
 *
 * @return: void.
 *
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand (CLEAR_SCREEN);
}
