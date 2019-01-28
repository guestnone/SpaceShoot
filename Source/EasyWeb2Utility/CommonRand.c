//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// PRNG - implementation.
//---------------------------------------------------------------------------

#include "CommonRand.h"

#include <msp430x14x.h>

static unsigned int gRandSeed = 1;
static unsigned int gRandMin = 1;
static unsigned int gRandMax = 1;

void randInit(int max, int min)
{
  
	ADC12CTL0 = ADC12ON|REFON|SHT0_15; 
	ADC12CTL1 = SHP|CSTARTADD_0;
	ADC12MCTL0 = INCH_10|SREF_1;
	for(int k=0; k < 0x3600; k++);
 
	CCR0 = 50000;
	TACTL = TASSEL_2 | ID_3 | MC_1;
	CCTL0 = CCIE;
	_BIS_SR(GIE);

	ADC12CTL0 |= ENC;

	P2OUT ^= BIT1;
	ADC12CTL0 |= ADC12SC;
	while((ADC12CTL1 & ADC12BUSY) == 1);
	gRandSeed = ADC12MEM0 * 1.0318-2777.4647;

	gRandMax = max;
	gRandMin = min;        
        
}

int randGet()
{
	gRandSeed = (gRandSeed * 1103515245U + 12345U) & 0x7fffffffU;
	char ret = gRandSeed % gRandMax;
	ret = ret % gRandMax;
	if (ret < gRandMin)
		return gRandMin;
	else
		return (int)ret;
}

void randChangeUpperLimit(int max)
{
	gRandMax = max;
}

void randChangeLowerLimit(int min)
{
	gRandMin = min;
}

