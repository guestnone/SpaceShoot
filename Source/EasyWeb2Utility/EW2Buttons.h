//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// Button related functions - definitions.
//---------------------------------------------------------------------------
#pragma once
#include "CommonUtil.h"

/** @addtogroup Buttons
 *  @{
 */

/** The first button that the user wants to check. */
#define MSP_BUTTON_FIRST 0
/** The second button that the user wants to check. */
#define MSP_BUTTON_SECOND 1
/** The third button that the user wants to check. */
#define MSP_BUTTON_THIRD 2
/** The fourth button that the user wants to check. */
#define MSP_BUTTON_FOURTH 3

/** Initializes the buttons by setting up proper ports. */
void buttonsSetUpPorts();

/**
 *  Checks, if the given button is pressed
 *  
 *  @param [in] button Selected button
 *  @return true if pressed, otherwise false.
 */
bool buttonsIsPressed(int button);

/* @} */
