//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// LCD controller related functions - definitions.
//---------------------------------------------------------------------------
#pragma once

/** @addtogroup LCD
 *  @{
 */
/** The main port from which instructions for the LCD controller will be sent */
#define MSP_LCD_DATA_PORT           P2OUT

/** Used to execute the prepared instruction to the controller*/
#define MSP_LCD_EXECUTE_BIT             3

/** Used to define the mode of communication for the controller (command(0) or data(1)) */
#define MSP_LCD_COMMUNICATION_MODE_BIT  2

/************************************************************************/
/* 	                          LCD COMMANDS                              */
/************************************************************************/
/** Wipes off the controllers memory and cleans up the display. */
#define	MSP_LCD_COMMAND_CLEAR_DISPLAY                       0x01
/** Reverts cursor back to first cell */
#define MSP_LCD_COMMAND_SET_CURSOR_HOME	                    0x02
/** Turn off the display */
#define MSP_LCD_COMMAND_DISPLAY_OFF	                        0x08
/** Turn on the display */
#define MSP_LCD_COMMAND_DISPLAY_ON                          0x0c

/** Moves the 16-element window onto left */
#define MSP_LCD_COMMAND_DATA_ROLL_LEFT                      0x18
/** Moves the 16-element window onto right */
#define MSP_LCD_COMMAND_DATA_ROLL_RIGHT                     0x1c
/** Moves the cursor one cell left */
#define MSP_LCD_COMMAND_CURSOR_SHIFT_LEFT                   0x10
/** Moves the cursor one cell right */
#define MSP_LCD_COMMAND_CURSOR_SHIFT_RIGHT                  0x14

/** Switch the entry mode to use the first LCD line */
#define MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1            0x80
/** Switch the entry mode to use the second LCD line */
#define MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2            0xc0
/** Not used, since the display can only display 2 lines */
#define MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE3            0x28
/** Switch the entry mode to write into built-in character generator RAM block */
#define MSP_LCD_CHARACTER_GEN_RAM_ADDRESS                   0x40

/************************************************************************/
/* 	                 CUSTOM DISPLAY CHARACTER SLOTS                     */
/************************************************************************/
#define MSP_LCD_CUSTOM_CHAR_0 0x00
#define MSP_LCD_CUSTOM_CHAR_1 0x01
#define MSP_LCD_CUSTOM_CHAR_2 0x02
#define MSP_LCD_CUSTOM_CHAR_3 0x03
#define MSP_LCD_CUSTOM_CHAR_4 0x04
#define MSP_LCD_CUSTOM_CHAR_5 0x05
#define MSP_LCD_CUSTOM_CHAR_6 0x06
#define MSP_LCD_CUSTOM_CHAR_7 0x07

/**
 *  Sends the command to the LCD controller to execute written command 
 *  @note Internal function.
 */
void lcdExecuteCommand(void);

/**
 * Sends the value (character or value for CGRAM) to the LCD controller.
 *
 * @param[in]  data  Value to be sent.
 */
void lcdSendData(unsigned char data);

/**
 * Sends the character to the LCD controller.
 *
 * @param[in]  character  Given character to send.
 */
void lcdSendCharacter(unsigned char character);

/**
 * Sends the command to the LCD controller.
 *
 * @param[in]  command  Command from the list of commands to be sent.
 */
void lcdSendCommand(unsigned char command);

/**
 * Sets up the ports for LCD controller.
 * 
 * @note This doesn't initializes the controller since it is in unknown state.
 * Please, call the lcdStartUp function to properly initialize the controller.
 */
void lcdSetUpPorts(void);

/** Initializes the controller and clears up the display */
void lcdStartUp(void);

/** Clears up the display */
void lcdClearDisplay(void);

/** Sets the controller to first line of display */
void lcdGoToFirstLine(void);

/** Sets the controller to second line of display */
void lcdGoToSecondLine(void);

/**
 * Sends the string to the LCD controller
 *
 * @param  string  String that we want to send.
 */
void lcdSendString(char *string);

/* @} */
