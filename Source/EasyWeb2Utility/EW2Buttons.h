//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once

/** Macros wrapping the selected buttons */
#define MSP_BUTTON_FIRST 0
#define MSP_BUTTON_SECOND 1
#define MSP_BUTTON_THIRD 2
#define MSP_BUTTON_FOURTH 3

/** Initialize the buttons on EasyWeb2 Board */
void buttonsStartUp();

/**
 *  Checks, if the given button is pressed
 *  
 *  @param [in] button Selected button
 *  @return true if pressed, otherwise false.
 */
bool buttonsIsPressed(int button);