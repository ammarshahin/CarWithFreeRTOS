
/*
 * lcd.h
 *
 * Created: 11/26/2019 5:42:13 PM
 *  Author: Osman
 */
#ifndef LCD_H_
#define LCD_H_


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#include <stdint.h>

#define ONE_MILLI       5
#define RS              GPIO_PIN_2
#define RW              GPIO_PIN_3
#define EN              GPIO_PIN_4



/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/


/*
	 * Function: LCD_goToRowColumn.
	 *
	 * @definition: Go to A Specific Row and Colomn in the LCD.
	 *
	 * @param	Name		: row
	 *			Type        : uint8
	 *			DESC		: Select the Specific Row.
	 *
	 * @param	Name		: col
	 *			Type        : uint8
	 *			DESC		: Select the Specific Colomn.
	 *
	 *
	 @return: void.
	 *
	 */

void LCD_goToRowColumn(uint8_t row,uint8_t col);
/*
	 * Function: LCD_sendCommand.
	 *
	 * @definition:Send a rewuired comman to the LCD.
	 *
	 * @param	Name		: Command
	 *			Type        : uint8
	 *			DESC		: Sending the command to the LCD.
	 *
	 *
	 @return: void.
	 *
	 */
void LCD_sendCommand(uint8_t command);
/*
	 * Function: LCD_displayCharacter.
	 *
	 * @definition: Displays a Character on the LCD.
	 *
	 * @param	Name		: data
	 *			Type        : uint8
	 *			DESC		: Sending the Character..
	 *
	 *
	 @return: void.
	 *
	 */

void LCD_displayCharacter(uint8_t data);
/*
	 * Function: LCD_displayString.
	 *
	 * @definition: Displays a String on the LCD.
	 *
	 * @param	Name		: Str
	 *			Type        : uint8 *
	 *			DESC		: Sending an Array of Characters..
	 *
	 *
	 @return: void.
	 *
	 */
void LCD_displayString(const char *Str);
/*
	 * Function: LCD_displayStringRowColumn.
	 *
	 * @definition: Function to Create A task.
	 *
	 * @param	Name		: row
	 *			Type        : uint8
	 *			DESC		: Determines the required Row.
	 *
	 * @param	Name		: col
	 *			Type        : uint8
	 *			DESC		: Determines the required Col.
	 *
	 * @param	Name		: Str
	 *			Type        : uint8*
	 *			DESC		: Sending An Array of Characters.
	 *
	 @return: void
	 *
	 */
void LCD_displayStringRowColumn(uint8_t row,uint8_t col, char* Str);
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

void LCD_init(void);
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
void LCD_clearScreen(void);


void intToString(uint32_t num ,char *buffer,uint8_t base);
void LCD_intgerToString(unsigned int data);

#endif /* LCD_H_ */

