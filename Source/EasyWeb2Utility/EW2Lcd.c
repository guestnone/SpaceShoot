//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// LCD controller related functions - implementation.
//---------------------------------------------------------------------------

#include <msp430x14x.h>

#include "EW2Lcd.h"
#include "CommonUtil.h"

void lcdExecuteCommand(void)
{
	MSP_SET_BIT(P2OUT, MSP_LCD_EXECUTE_BIT);
	commonDelay(10);
	MSP_CLEAR_BIT(P2OUT, MSP_LCD_EXECUTE_BIT);
}

void lcdSendData(unsigned char data)
{
	int temp;
	commonDelay(500);
	
	// upper nibble
	temp = data & 0xf0;
	
	MSP_LCD_DATA_PORT &= 0x0f;
	MSP_LCD_DATA_PORT |= temp;
	
	MSP_SET_BIT(MSP_LCD_DATA_PORT, MSP_LCD_COMMUNICATION_MODE_BIT);
	lcdExecuteCommand();
	
	// lower nibble
	temp = data & 0x0f;
	temp = temp << 4;
	
	MSP_LCD_DATA_PORT &= 0x0f;
	MSP_LCD_DATA_PORT |= temp;
	
	MSP_SET_BIT(MSP_LCD_DATA_PORT, MSP_LCD_COMMUNICATION_MODE_BIT);
	lcdExecuteCommand();
}

void lcdSendCharacter(unsigned char character)
{
	lcdSendData(character);
}

void lcdSendCommand(unsigned char command)
{
	int temp;
	commonDelay(500);
	
	// upper nibble
	temp = command & 0xf0;
	
	MSP_LCD_DATA_PORT &= 0x0f;
	MSP_LCD_DATA_PORT |= temp;
	
	MSP_CLEAR_BIT(MSP_LCD_DATA_PORT, MSP_LCD_COMMUNICATION_MODE_BIT);
	lcdExecuteCommand();
	
	// lower nibble
	temp = command & 0x0f;
	temp = temp << 4;
	
	MSP_LCD_DATA_PORT &= 0x0f;
	MSP_LCD_DATA_PORT |= temp;
	
	MSP_CLEAR_BIT(MSP_LCD_DATA_PORT, MSP_LCD_COMMUNICATION_MODE_BIT);
	lcdExecuteCommand();
}

void lcdSetUpPorts(void)
{
	P2SEL = 0;
	P2OUT = 0;
	P2DIR = ~BIT0;
}

void lcdStartUp(void)
{	
	MSP_CLEAR_BIT(MSP_LCD_DATA_PORT, MSP_LCD_COMMUNICATION_MODE_BIT);
	commonDelay(250*100);
	commonDelay(250*100);
	commonDelay(250*100);
	commonDelay(250*100);
	
	MSP_LCD_DATA_PORT |= BIT4 | BIT5;
	MSP_LCD_DATA_PORT &= ~BIT6 & ~BIT7;
	
	lcdExecuteCommand();
	commonDelay(100*100); //10ms
	lcdExecuteCommand();
	commonDelay(100*100); //10ms
	lcdExecuteCommand();
	commonDelay(100*100); //10ms	
	
	MSP_LCD_DATA_PORT &= ~BIT4;
	lcdExecuteCommand();
	
	lcdSendCommand(MSP_LCD_COMMAND_DISPLAY_ON);
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);

	commonDelay(250*100);
	commonDelay(250*100);
	commonDelay(250*100);
	commonDelay(250*100);

}

void lcdClearDisplay(void)
{
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
}

void lcdGoToFirstLine(void)
{
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
}

void lcdGoToSecondLine(void)
{
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
}

void lcdSendString(char *string)
{
	while(*string)
		lcdSendData(*string++);  
}
