//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// LCD controller related functions - implementation.
//---------------------------------------------------------------------------

#include "EW2Lcd.h"
#include "CommonUtil.h"

#include <msp430x14x.h>

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
	temp = d & 0xf0;
	
	MSP_LCD_DATA_PORT &= 0x0f;
	MSP_LCD_DATA_PORT |= temp;
	
	MSP_SET_BIT(MSP_LCD_DATA_PORT, COMMUNICATION_MODE_BIT);
	lcdExecuteCommand();
	
	// lower nibble
	temp = d & 0x0f;
	temp = temp << 4;
	
	MSP_LCD_DATA_PORT &= 0x0f;
	MSP_LCD_DATA_PORT |= temp;
	
	MSP_SET_BIT(MSP_LCD_DATA_PORT, COMMUNICATION_MODE_BIT);
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
	temp = d & 0xf0;
	
	MSP_LCD_DATA_PORT &= 0x0f;
	MSP_LCD_DATA_PORT |= temp;
	
	MSP_CLEAR_BIT(MSP_LCD_DATA_PORT, COMMUNICATION_MODE_BIT);
	lcdExecuteCommand();
	
	// lower nibble
	temp = d & 0x0f;
	temp = temp << 4;
	
	MSP_LCD_DATA_PORT &= 0x0f;
	MSP_LCD_DATA_PORT |= temp;
	
	MSP_CLEAR_BIT(MSP_LCD_DATA_PORT, COMMUNICATION_MODE_BIT);
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
	lcdExecuteCommand();
	commonDelay(100*100); //10ms
	lcdExecuteCommand();
	commonDelay(100*100); //10ms
	
	LCD_DATA_PORT &= ~BIT4;
	lcdExecuteCommand();

	lcdSendCommand(DISPLAY_ON);
	lcdSendCommand(CLEAR_DISPLAY);

	// 100ms
	commonDelay(250*100);
	commonDelay(250*100);
	commonDelay(250*100);
	commonDelay(250*100);

}

void lcdClearDisplay(void)
{
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
}

void lcdUploadCustomCharacters(char *customCharSet, unsigned int numOfCharacters)
{
	int i;
	int j;

	lcdSendCommand(MSP_LCD_CHARACTER_GEN_RAM_ADDRESS);
	for (i = 0; i < numOfCharacters; i++)
	{
		for (j = 0; j < 8; j++)
		{
			lcdSendData(customCharSet[i][j]);
		}
	}
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