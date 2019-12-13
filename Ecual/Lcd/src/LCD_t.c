/*
 *
 * lcd.c
 *
 *  Created on: Nov 30, 2019
 *      Author: Ammar Shahin
 */

/*******************************************************************************
 *                    				INCLUDES          	     	               *
 *******************************************************************************/
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
#include "LCD_t.h"

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


#define LCD_DELAY_SYSTICK 1

/*******************************************************************************
 *                      Private FUNCTIONS DEFINITION         	                   *
 *******************************************************************************/
/**
 * Description: This function is used for Sending the command to the LCD.
 * @param command : the command
 * Return : void
 */
static void LCD_sendCommand(uint8_t command)
{
    GPIOPinWrite(GPIO_PORTA_BASE, RW|RS,false);
    vTaskDelay(LCD_DELAY_SYSTICK);

    GPIOPinWrite(GPIO_PORTA_BASE, EN,EN);
    vTaskDelay(LCD_DELAY_SYSTICK);

    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,(command & LAST_HALF_MASK));
    vTaskDelay(LCD_DELAY_SYSTICK);

    GPIOPinWrite(GPIO_PORTA_BASE, EN,false);
    vTaskDelay(LCD_DELAY_SYSTICK);

    GPIOPinWrite(GPIO_PORTA_BASE, EN,EN);
    vTaskDelay(LCD_DELAY_SYSTICK);

    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,((command & MASK_FIRST_BITS)<<4));
    vTaskDelay(LCD_DELAY_SYSTICK);

    GPIOPinWrite(GPIO_PORTA_BASE, EN,false);
    vTaskDelay(LCD_DELAY_SYSTICK);
}



/**
 * Description: This function is used for Displaying a number on the LCD
 * @param num : the Number to be displayed
 * @param buffer : A pointer to the Buffer
 * Return : void
 */
static void intToString(uint32_t num ,char *buffer,uint8_t base )
{

   uint8_t index = false,temp,i;

   while(num)
   {

       buffer[index++]= num % base+ 0x30;
       num /=base;

   }

   buffer[index]=0;

   for(i=0;i< index/2;i++)
   {
       temp=buffer[i];
       buffer[i]=buffer[index-i-1] ;
       buffer[index-i-1]   = temp ;
   }

}


/*******************************************************************************
 *                      API FUNCTIONS DEFINITION                               *
 *******************************************************************************/
/**
 * Description: This function is used for Displaying Char on the LCD.
 * @param data : the Data to be displayed
 * Return : void
 */
void LCD_displayCharacter(uint8_t data)
{

       GPIOPinWrite(GPIO_PORTA_BASE, RS,0x04);
       vTaskDelay(LCD_DELAY_SYSTICK);

       GPIOPinWrite(GPIO_PORTA_BASE, EN,EN);
       vTaskDelay(LCD_DELAY_SYSTICK);

       GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,(data&LAST_HALF_MASK));
       vTaskDelay(LCD_DELAY_SYSTICK);

       GPIOPinWrite(GPIO_PORTA_BASE, EN,false);
       vTaskDelay(LCD_DELAY_SYSTICK);

       GPIOPinWrite(GPIO_PORTA_BASE, EN,EN);
       vTaskDelay(LCD_DELAY_SYSTICK);

       GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,((data&MASK_FIRST_BITS)<<4));
       vTaskDelay(LCD_DELAY_SYSTICK);

       GPIOPinWrite(GPIO_PORTA_BASE, EN,false);
       vTaskDelay(LCD_DELAY_SYSTICK);
}


/**
 * Description: This function is used to init the LCD Module.
 * @param : void
 * Return : void
 */
void LCD_init (void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);

    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, RS|RW|EN);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);

    vTaskDelay(LCD_DELAY_SYSTICK);						/* LCD Power ON delay always >15ms */

    LCD_sendCommand(INIT_CONTROL);
    LCD_sendCommand(INIT_CONTROL_TWO);		    	/* send for 4 bit initialization of LCD  */
    LCD_sendCommand(FOUR_BIT_MDOE);              	/* Use 2 line and initialize 5*7 matrix in (4-bit mode)*/
    LCD_sendCommand(CURSOR_OFF);              	    /* Display on cursor off*/
    LCD_sendCommand(ENTRY_MODE);

    vTaskDelay(LCD_DELAY_SYSTICK);

    LCD_sendCommand(CLEAR_SCREEN);              	/* Clear display screen*/

    vTaskDelay(LCD_DELAY_SYSTICK);

    LCD_sendCommand (CURSOR_AT_BEGINNING);

    vTaskDelay(LCD_DELAY_SYSTICK);
}


/**
 * Description: This function is used for Displaying a string on the LCD.
 * @param data : the Data to be displayed
 * Return : void
 */
void LCD_displayString(const char *Str)
{
	int string_Counter = false;
	while(Str[string_Counter])
	{
		LCD_displayCharacter(Str[string_Counter]);
		string_Counter++;
	}
}

/**
 * Description: This function is used for Displaying a string on the LCD at a specific location
 * @param row : the row to be displayed at
 * @param col : the column to be displayed at
 * @param Str : A pointer to the String of the Data to be displayed
 * Return : void
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


/**
 * Description: This function is used for Displaying a number on the LCD
 * @param data : the data to be displayed
 * Return : void
 */

void LCD_intgerToString(unsigned int data)
{
  char buff[16]; /* String to hold the ascii result */
  intToString(data,buff,10); /* 10 for decimal */
  LCD_displayString(buff);
}


/**
 * Description: This function is used for clearing the LCD
 * Return : void
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand (CLEAR_SCREEN);
	vTaskDelay(LCD_DELAY_SYSTICK);
}
