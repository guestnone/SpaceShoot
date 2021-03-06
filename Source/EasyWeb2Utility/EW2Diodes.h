//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// Diode related functions - definitions.
//---------------------------------------------------------------------------

#pragma once

/** @addtogroup Diodes
 *  @{
 */

#define MSP_DIODES_STATUS      0 /**< Status diode */
#define MSP_DIODES_RELAY_TYPE1 1 /**< First diode plugged onto the relay */
#define MSP_DIODES_RELAY_TYPE2 2 /**< Second diode plugged onto the relay */

/** Initializes the diodes by setting up proper ports. */
void diodesSetUpPorts(void);

/**
 *  Switches the given diode to the state negative from now.
 *
 *  @param[in] type Type of the diode. 
 */
void diodesSwitch(int type);

/** Switches off all the diodes on the board. */
void diodesTurnOffAll(void);

/**
 * Turns on the selected diode based on the given type.
 * 
 * @param[in] type Type of the diode. 
 */
void diodesTurnOn(int type);

/**
 * Turns on the selected diode based on the given type.
 * 
 * @param[in] type Type of the diode. 
 */
void diodesTurnOff(int type);

/* @} */
