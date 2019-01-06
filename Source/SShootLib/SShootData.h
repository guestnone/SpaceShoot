//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

enum CustomCharacterType
{
	Empty
};

/************************************************************************/
/* 	                   SHIPS, ENEMIES AND OBJECT                        */
/************************************************************************/
char gShipData[4][5]
{
	{},
	{},
	{},
	{},
}


/************************************************************************/
/* 	                    POLISH LANGUAGE CHARACTERS                      */
/************************************************************************/

/************************************************************************/
/* 	                           LCD STRINGS                              */
/************************************************************************/
#define STR_MENU_MAIN_SELECT_INFO "Main Menu"
#define STR_MENU_MAIN_ITEM_PLAY "Play"
#define STR_MENU_MAIN_ITEM_HIGHSCORES "High Scores"
#define STR_MENU_MAIN_ITEM_SETTINGS "Settings"
#define STR_MENU_MAIN_ITEM_ABOUT "About"

#define STR_MENU_SHIPSEL_MAIN "Select your ship"
// @TODO came up with names
#define STR_MENU_SHIPSEL_NAME_ONE "First"
#define STR_MENU_SHIPSEL_NAME_TWO "Second"
#define STR_MENU_SHIPSEL_NAME_THREE "Third"
#define STR_MENU_SHIPSEL_NAME_FOUR "Fourth"

#define STR_MENU_SCORES_POINTS "pts."

#define STR_GAME_LIVES_LEFT " lives remains"

#define STR_ABOUT_NAME "Space Shooter"
#define STR_ABOUT_BY "by"
#define STR_ABOUT_AUTHOR_ONE "Patrick Recko"
#define STR_ABOUT_AUTHOR_TWO "Yan Yanutsevich"
#define STR_ABOUT_AUTHOR_THREE "Pawel Krzywosz"

#define STR_WAIT "WAIT!"

/************************************************************************/
/* 	                              OTHER                                 */
/************************************************************************/





dataCreateCustomScreenCharset();

dataSwitchCustomScreenCharset();