//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick ReÄ‡ko, Yan Yanutsevich, PaweÅ‚ Krzywosz
	
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

void diodesTurnOn(int type)
{
 switch (type)              // w zale¿noœci od tego, na ktorej diodzie pracujemy
    {
    case MSP_DIODES_STATUS:
        P2OUT &= ~(1<<1);      //zapala diode 1
        break;
    case MSP_DIODES_RELAY_TYPE1:
        P1OUT |= (1<<5);      //zapala diode 2
        break;
    case MSP_DIODES_RELAY_TYPE2:
        P1OUT |= (1<<6);      //zapala diode 3
        break;
	default:
		break;
    }

}

void diodesTurnOff(int type)
{
  switch(type)
    {
    case MSP_DIODES_STATUS:
        P2OUT |= (1<<1);      //wylaczanie diody 1
        break;

    case MSP_DIODES_RELAY_TYPE1:
        P1OUT &= ~(1<<5);     //wylaczanie diody 2
        break;

    case MSP_DIODES_RELAY_TYPE2:
        P1OUT &= ~(1<<6);     //wylaczanie diody 3
        break;
	default:
		break;
    }

}

