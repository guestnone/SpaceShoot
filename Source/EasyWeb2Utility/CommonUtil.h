//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// Common stuff - definitions.
//---------------------------------------------------------------------------

#pragma once

/** Custom boolean type (used to mostly shave a memory from linking a C standard libary) */
typedef enum {true = 1, false = 0 } bool;

/** @addtogroup Utility
 *  @{
 */

/**
 *  Delays the execution of the code by a given time.
 *  
 *  @param [in] us Time in nano-seconds.
 */
void commonDelay(unsigned int us);

/** Turns off the watchdog in the device. */
void commonTurnOffWatchdog(void);

/**
 *  Sets the bit in the variable/address to a positive value.
 *  
 *  @param [in] var Given variable.
 *  @param [in] bitno Given bit in that variable.
 */
#define MSP_SET_BIT(var,bitno) ((var) |= 1 << (bitno))

/**
 *  Sets the bit in the variable/address to a positive value.
 *
 *  @param [in] var Given variable.
 *  @param [in] bitno Given bit in that variable.
 */
#define MSP_CLEAR_BIT(var,bitno) ((var) &= ~(1 << (bitno)))

/* @} */
