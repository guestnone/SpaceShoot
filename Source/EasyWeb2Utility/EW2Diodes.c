//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// Diode related functions - implementation.
//---------------------------------------------------------------------------

#include "EW2Diodes.h"

#include <msp430x14x.h>

void diodesSetUpPorts(void)
{
	// Initialize the Status diode
	P2DIR |= BIT1;
	// Initialize the Relay diodes
	P1DIR |= BIT5;
    P1DIR |= BIT6;
}

void diodesSwitch(int type)
{
	switch (type)
	{
		// Switch on/off the status diode
	case MSP_DIODES_STATUS:
		P2OUT ^= BIT1;
		break;
		// Switch on/off the relay diode
	case MSP_DIODES_RELAY_TYPE1:
		P1OUT ^= BIT5;
		break;
		// Switch on/off the relay diode
	case MSP_DIODES_RELAY_TYPE2:
		P1OUT ^= BIT6;
		break;
	}
}

//off all diodes
void diodesTurnOffAll()
{
	P2OUT &= ~BIT1; 
	P1OUT &= ~BIT5;
	P1OUT &= ~BIT6;
}
