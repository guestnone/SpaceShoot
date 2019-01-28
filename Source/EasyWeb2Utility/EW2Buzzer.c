//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// Buzzer related functions - implementation.
//---------------------------------------------------------------------------

#include "EW2Buzzer.h"
#include "CommonUtil.h"
#include <msp430x14x.h>


void initBuzzer(){
  P4DIR |= BIT2;
  P4DIR |= BIT3;
}

void buzzing(unsigned int note, unsigned int duration)
{
    short delayB = (short)(10000/note);
    short time = (short)((duration*100)/(delayB*2));
    for (char i=0;i<time;i++)
    {
        P4OUT |= BIT3;
        commonDelay(delayB);
        P4OUT &= ~BIT3;    
        commonDelay(delayB);
    }
    commonDelay(20);
}
