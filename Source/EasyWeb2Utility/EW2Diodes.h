//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once

#define MSP_DIODES_STATUS      0
#define MSP_DIODES_RELAY_TYPE1 1
#define MSP_DIODES_RELAY_TYPE2 2


void diodesSetUpPorts(void);

void diodesSwitch(int type);