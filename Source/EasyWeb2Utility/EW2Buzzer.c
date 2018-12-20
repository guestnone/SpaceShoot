//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "EW2Buzzer.h"

#include <msp430x14x.h>

void buzzerSetUpPorts(void)
{
	P4SEL = 0;
	P4OUT = 0;
	P4DIR = BIT2 | BIT3;
}

void buzzerSwitch(int type)
{
	switch(type)
	{
	case MSP_BUZZER_TYPE1:
		P4OUT ^= BIT2;
		break;
	case MSP_BUZZER_TYPE1:
		P4OUT ^= BIT3;
		break;
	}
}

void buzzerReset()
{
	P4OUT &= ~BIT2;
	P4OUT &= ~BIT3;
}