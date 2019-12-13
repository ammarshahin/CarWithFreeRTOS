/*
 *
 * lcd.c
 *
 *  Created on: Nov 30, 2019
 *      Author: Ammar Shahin
 */


#ifndef LCD_H_
#define LCD_H_

/************************************************************************/
/*                              INCLUDES                                */
/************************************************************************/
#include <stdint.h>

/*******************************************************************************
 *                                  Macros                                    *
 *******************************************************************************/
#define ONE_MILLI       5
#define RS              GPIO_PIN_2
#define RW              GPIO_PIN_3
#define EN              GPIO_PIN_4


/*******************************************************************************
 *                      API FUNCTIONS DEFINITION                               *
 *******************************************************************************/
/**
 * Description: This function is used to init the LCD Module.
 * @param : void
 * Return : void
 */
void LCD_init (void);

/**
 * Description: This function is used for Displaying Char on the LCD.
 * @param data : the Data to be dispalyed
 * Return : void
 */
void LCD_displayCharacter(uint8_t data);

/**
 * Description: This function is used for Displaying a string on the LCD.
 * @param data : the Data to be dispalyed
 * Return : void
 */
void LCD_displayString(const char *Str);

/**
 * Description: This function is used for Displaying a string on the LCD at a spacfic locatiocn
 * @param row : the row to be dispalyed at
 * @param col : the column to be dispalyed at
 * @param Str : A pointer to the String of the Data to be dispalyed
 * Return : void
 */
void LCD_displayStringRowColumn(uint8_t row,uint8_t col, char* Str);

/**
 * Description: This function is used for Displaying a number on the LCD
 * @param data : the data to be displayed
 * Return : void
 */

void LCD_intgerToString(unsigned int data);

/**
 * Description: This function is used for clearing the LCD
 * Return : void
 */
void LCD_clearScreen(void);

#endif /* LCD_H_ */

