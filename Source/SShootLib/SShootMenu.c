//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "SShootMenu.h"
#include "SShootCommon.h"
#include "SShootData.h"
#include "EasyWeb2Utility/EW2.h"

char gSpaces[] = "                 ";

void internal_moveSecondLineRight()
{
	int i;
	for (i = 0; i < 17; i++)
	{
		lcdSendCommand(MSP_LCD_COMMAND_DATA_ROLL_RIGHT);
		commonDelay(1000);
	}
}

void internal_moveSecondLineLeft()
{
	int i;
	for (i = 0; i < 17; i++)
	{
		lcdSendCommand(MSP_LCD_COMMAND_DATA_ROLL_LEFT);
		commonDelay(1000);
	}
}

void internal_menuMainMoveRight(char* string)
{
	internal_moveSecondLineRight();
	lcdSendCommand(MSP_LCD_COMMAND_SET_CURSOR_HOME);
	lcdSendString(gSpaces);
	lcdSendString(string);
	internal_moveSecondLineRight();
}

void internal_menuMainMoveLeft(char* string)
{
	internal_moveSecondLineLeft();
	lcdSendCommand(MSP_LCD_COMMAND_SET_CURSOR_HOME);
	lcdSendString(gSpaces);
	lcdSendString(string);
	internal_moveSecondLineLeft();
}

MainLoopState menuMainWindow()
{
	MainLoopState ret = Game;
	
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
	lcdSendString("   ");
	lcdSendString(STR_MENU_MAIN_SELECT_INFO);
	internal_menuMainMoveRight(STR_MENU_MAIN_ITEM_PLAY);

	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);

	while (buttonsIsPressed(MSP_BUTTON_THIRD))
	{
		if (buttonsIsPressed(MSP_BUTTON_SECOND))
		{
			switch(ret)
			{
			case Game:
				internal_menuMainMoveRight(STR_MENU_MAIN_ITEM_SETTINGS);
				ret = Game;
				break;
			case Settings:
				internal_menuMainMoveRight(STR_MENU_MAIN_ITEM_HIGHSCORES);
				ret = HighScore;
				break;
			case HighScore:
				internal_menuMainMoveRight(STR_MENU_MAIN_ITEM_ABOUT);
				ret = About;
				break;
			case About:
				internal_menuMainMoveRight(STR_MENU_MAIN_ITEM_PLAY);
				ret = Game;
				break;
			}
		}

		if (buttonsIsPressed(MSP_BUTTON_FIRST))
		{
			switch(ret)
			{
			case Game:
				internal_menuMainMoveLeft(STR_MENU_MAIN_ITEM_ABOUT);
				ret = About;
				break;
			case Settings:
				internal_menuMainMoveLeft(STR_MENU_MAIN_ITEM_PLAY);
				ret = Game;
				break;
			case HighScore:
				internal_menuMainMoveLeft(STR_MENU_MAIN_ITEM_SETTINGS);
				ret = Settings;
				break;
			case About:
				internal_menuMainMoveLeft(STR_MENU_MAIN_ITEM_HIGHSCORES);
				ret = HighScore;
				break;
			}
		}
	}

	return ret;

}


MainLoopState menuAbout()
{
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);

	lcdSendString(STR_ABOUT_NAME);
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
	
	lcdSendString("                 ");
	lcdSendString(STR_ABOUT_BY);
	internal_moveSecondLineLeft();
	commonDelay(65450);	
	internal_moveSecondLineLeft();
	commonDelay(100);
	lcdSendCommand(MSP_LCD_COMMAND_SET_CURSOR_HOME);

	lcdSendString("                 ");
	lcdSendString(STR_ABOUT_AUTHOR_ONE);
	internal_moveSecondLineLeft();
	commonDelay(65450);	
	internal_moveSecondLineLeft();
	commonDelay(100);
	lcdSendCommand(MSP_LCD_COMMAND_SET_CURSOR_HOME);
	
	lcdSendString("                 ");
	lcdSendString(STR_ABOUT_AUTHOR_TWO);
	internal_moveSecondLineLeft();
	commonDelay(65450);	
	internal_moveSecondLineLeft();
	commonDelay(100);
	lcdSendCommand(MSP_LCD_COMMAND_SET_CURSOR_HOME);

	lcdSendString("                 ");
	lcdSendString(STR_ABOUT_AUTHOR_THREE);
	internal_moveSecondLineLeft();
	commonDelay(65450);	
	internal_moveSecondLineLeft();
	commonDelay(100);
	lcdSendCommand(MSP_LCD_COMMAND_SET_CURSOR_HOME);


	return MainScreen;
}


MainLoopState menuSettings()
{
	// @TODO implement
	return MainScreen;
}

MainLoopState menuHighScores()
{
	// @TODO implement
	return MainScreen;
}
