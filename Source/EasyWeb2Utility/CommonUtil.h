//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once

#define EVER (;;)

/**
 * Our own bool type, since we don't know if old IAR C Compiler
 * supports this type.
 */
typedef int bool;
#define true 1
#define false 0

#define MSP_SET_BIT(var,bitno) ((var) |= 1 << (bitno))
#define MSP_CLEAR_BIT(var,bitno) ((var) &= ~(1 << (bitno)))

void commonDelay(unsigned int us);