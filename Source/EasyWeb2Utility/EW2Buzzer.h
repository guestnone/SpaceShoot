//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once


#define MSP_BUZZER_TYPE1 0
#define MSP_BUZZER_TYPE2 1


void buzzerSetUpPorts(void);

void buzzerSwitch(int type);

void buzzerReset();
