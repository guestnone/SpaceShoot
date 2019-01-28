//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------


/** @addtogroup Common
 *  @{
 */

#pragma once

/**
 * The mode in which the program is running.
 */
typedef enum
{
	/** Main menu */
	MainScreen = 0,
	/** Gameplay mode */
	Game,
	/** About screen */
	About
} MainLoopState;

/** Type of the ship chosen by the player */
typedef enum
{
	First,
	Second,
	Third,
	Fourth
} ShipType;

/* @} */
