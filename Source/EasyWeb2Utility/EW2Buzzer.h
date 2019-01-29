//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
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
 *  Emits the sound from the buzzer on the board. 
 *  
 *  @param [in] note Pitch from which the sound will be emitted.
 *  @param [in] duration Emission time.
 */
void buzzing(unsigned int note, unsigned int duration);

/* @} */
