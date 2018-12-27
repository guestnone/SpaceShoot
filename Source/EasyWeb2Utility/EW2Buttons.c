//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "EW2Buttons.h"

#include <msp430x14x.h>

void buttonsStartUp()
{
	P4DIR &= ~(BIT4 // One
	         | BIT5 // Two
			 | BIT6 // Three
			 | BIT7 // Four
			 ); 
}

bool buttonsIsPressed(int button)
{
	switch(button)
	{
	case MSP_BUTTON_FIRST:
		if ((P4IN & BIT4) ==0)
			return true;
		break;
	case MSP_BUTTON_SECOND:
		if ((P4IN & BIT5) ==0)
			return true;
		break;
	case MSP_BUTTON_THIRD:
		if ((P4IN & BIT6) ==0)
			return true;
		break;
	case MSP_BUTTON_FOURTH:
		if ((P4IN & BIT7) ==0)
			return true;
		break;
	default:
		return false;
	}
    return false;
}