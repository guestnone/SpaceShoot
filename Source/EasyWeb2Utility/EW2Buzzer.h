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

/** Initializes the buzzers by setting up proper ports. */
void initBuzzer();
/**
 *  Emits or silence the given buzzer on the board. 
 *  
 *  @param [in] type Description for type
 */
void buzzing(unsigned int note, unsigned int duration);
void playSoundForOn();
void playSoundForShot();
void playSoundForSwitch();
void playSoundForBoom();
