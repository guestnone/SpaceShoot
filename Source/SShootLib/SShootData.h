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
char FirstShipData[8] = {16,9,6,31,31,6,9,16};
char SecondShipData[8] = {6,9,18,21,21,18,9,6};
char ThirdShipData[8] = {24,4,26,17,17,26,4,24};
char FourthShipData[8] = {0,17,26,5,5,26,17,0};

char AllShipData[4][8] = {
	{16,9,6,31,31,6,9,16},	//firest
	{6,9,18,21,21,18,9,6},	//second
	{24,4,26,17,17,26,4,24},	//third
	{0,17,26,5,5,26,17,0}	//fourth
};

char AllEnemyData[2][8] ={ 
	{25,5,10,16,16,10,5,25},	// enemy
	{4,10,10,10,10,10,10,4}	// barrier
};


/************************************************************************/
/* 	                    POLISH LANGUAGE CHARACTERS                      */
/************************************************************************/

char polishCharacters[8][8] = {

    {4,0,31,2,4,8,31,0}, //ż albo ź
    {1,2,0,4,10,17,10,4}, //ó
    {4,4,5,6,12,20,4,4}, //ł
    {0,0,14,17,31,16,15,4}, //ę
    {4,10,17,31,17,17,18,1}, //ą
    {2,4,14,17,16,16,17,14}, //ć
    {2,4,22,25,17,17,17,17}, //ń
    {2,4,14,17,12,2,17,14} // ś

};

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
#define STR_ABOUT_AUTHOR_THREE "Paweł Krzywosz"

#define STR_WAIT "WAIT!"

/************************************************************************/
/* 	                              OTHER                                 */
/************************************************************************/





void dataCreateCustomScreenCharset();

void dataSwitchCustomScreenCharset();
