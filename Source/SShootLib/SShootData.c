//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "SShootData.h"
#include "SShootCommon.h"
#include "EasyWeb2Utility/EW2Lcd.h"
#include "EasyWeb2Utility/EW2Buzzer.h"

/**
 * Contains all the choosable ship's custom character definitions.
 */
char AllShipData[4][8] = {
	/// first
	{16,9,6,31,31,6,9,16},
	/// second
	{6,9,18,21,21,18,9,6},
	/// third
	{24,4,26,17,17,26,4,24},
	/// fourth
	{0,17,26,5,5,26,17,0}
};

/**
 * Contains enemy and barrier custom character definitions.
 */
char AllEnemyData[2][8] = { 
	/// enemy
	{25,5,10,16,16,10,5,25},
	/// barrier
	{4,10,10,10,10,10,10,4}	
};

/**
 * Contains needed polish language custom character definitions.
 */
char PolishCharacters[2][8] = {
	/// ł
    {4,4,5,6,12,20,4,4}, 
    /// ć
    {2,4,14,17,16,16,17,14},
};

/**
 * Uploads one character into the LCD data port when active on CGRAM memory.
 *
 * @param      cPart  Data of the character set.
 * 
 * @note Internal Function, only used on implementation.
 */
void internal_uploadOneCSet(char cPart[8])
{
    for (int i = 0; i < 8; i++)
    {
         lcdSendData(cPart[i]);
    }
}

void dataUploadAllShipCustomChars()
{
    lcdSendCommand(MSP_LCD_CHARACTER_GEN_RAM_ADDRESS);
    internal_uploadOneCSet(AllShipData[0]);
    internal_uploadOneCSet(AllShipData[1]);
    internal_uploadOneCSet(AllShipData[2]);
    internal_uploadOneCSet(AllShipData[3]);
    lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
}

void dataSwitchCustomScreenCharset(ShipType ship)
{
	lcdSendCommand(MSP_LCD_CHARACTER_GEN_RAM_ADDRESS);
	switch(ship)
	{
	case First:
		internal_uploadOneCSet(AllShipData[0]);
		break;
	case Second:
		internal_uploadOneCSet(AllShipData[1]);
		break;
	case Third:
		internal_uploadOneCSet(AllShipData[2]);
		break;
	case Fourth:
		internal_uploadOneCSet(AllShipData[3]);
		break;
	}
	
	internal_uploadOneCSet(AllEnemyData[0]);
	internal_uploadOneCSet(AllEnemyData[1]);
    lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
}


void playSoundForOn()
{
	buzzing(560, 80);
	buzzing(560, 50);
	buzzing(560, 50);
	
	buzzing(100, 30);
	buzzing(100, 30);
	buzzing(100, 30);
	
	buzzing(560, 80);
	buzzing(560, 80);
}

void playSoundForSwitch()
{
	buzzing(600, 50);
	buzzing(560, 80);
}

void playSoundForBoom()
{
	buzzing(500, 100);
	buzzing(100, 80);
	buzzing(500, 40);
}

void playSoundForShot()
{
	buzzing(1000, 80);
	buzzing(1000, 70);
}

