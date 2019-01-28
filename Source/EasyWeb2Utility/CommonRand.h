//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// PRNG - definitions.
//---------------------------------------------------------------------------

#pragma once

/** @addtogroup Rand
 *  @{
 */

/**
 * Initializes the Pseudo-Random Number Generator based on the 
 * temperature of the CPU
 *
 * @param[in]  max   Upper limit of the numbers get from the PRNG.
 * @param[in]  min   Lower limit of the numbers get from the PRNG.
 */
void randInit(int max, int min);

/**
 * Gets the random number from the PRNG.
 *
 * @return     Random number from the generator.
 * @note       Not for crypto use.
 */
int randGet();

/**
 * Change the upper limit of the PRNG
 *
 * @param[in]  max   New upper limit.
 */
void randChangeUpperLimit(int max);

/**
 * Change the lower limit of the PRNG
 *
 * @param[in]  min   New lower limit.
 */
void randChangeLowerLimit(int min);

/* @} */
