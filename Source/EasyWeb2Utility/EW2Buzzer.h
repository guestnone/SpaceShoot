//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// Buzzer related functions - definitions.
//---------------------------------------------------------------------------
#pragma once

/** @addtogroup Buzzer
 *  @{
 */

/** First type of the buzzer that the user wants to use. */
#define MSP_BUZZER_TYPE1 0
/** Second type of the buzzer that the user wants to use. */
#define MSP_BUZZER_TYPE2 1

/** Initializes the buzzers by setting up proper ports. */
void buzzerSetUpPorts(void);

/**
 *  Emits or silence the given buzzer on the board. 
 *  
 *  @param [in] type Description for type
 */
void buzzerSwitch(int type);

/** Resets the buzzers to the off position */
void buzzerReset();

/* @} */
