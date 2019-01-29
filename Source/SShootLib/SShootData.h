//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once

#include "SShootCommon.h"

/** @addtogroup Data
 *  @{
 */
	
/************************************************************************/
/* 	                           LCD STRINGS                              */
/************************************************************************/
#define STR_MENU_MAIN_SELECT_INFO "Main Menu"
#define STR_MENU_MAIN_ITEM_PLAY "Play"
#define STR_MENU_MAIN_ITEM_ABOUT "About"

#define STR_MENU_SHIPSEL_MAIN "Select your ship"

#define STR_ABOUT_NAME "Space Shooter"
#define STR_ABOUT_BY "by"
#define STR_ABOUT_AUTHOR_ONE "Patrick Recko"
#define STR_ABOUT_AUTHOR_TWO "Yan Yanutsevich"
#define STR_ABOUT_AUTHOR_THREE "Pawel Krzywosz"

/************************************************************************/
/* 	                              OTHER                                 */
/************************************************************************/

/**
 * Uploads all ship characters into CGRAM. Used on Ship selections.
 */
void dataUploadAllShipCustomChars();

/**
 * Prepares the gameplay's custom character set based on the ship type.
 *
 * @param[in]  ship  Chosen ship type.
 */
void dataSwitchCustomScreenCharset(ShipType ship);

/**
 * Emits the intro sound
 */
void playSoundForOn();

/**
 * Emits the bullet shot sound.
 */
void playSoundForShot();

/**
 * Emits the menu position switch sound.
 */
void playSoundForSwitch();

/**
 * Emits the player's ship explosion sound.
 */
void playSoundForBoom();

/** @} */
