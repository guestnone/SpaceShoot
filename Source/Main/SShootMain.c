//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include <EasyWeb2Utility/CommonUtil.h>
#include <EasyWeb2Utility/EW2Buttons.h>
#include <EasyWeb2Utility/EW2Buzzer.h>
#include <EasyWeb2Utility/EW2Diodes.h>
#include <EasyWeb2Utility/EW2Lcd.h>
#include <EasyWeb2Utility/EW2Uart.h>
#include <EasyWeb2Utility/CommonRand.h>
#include <SShootLib/SShootMainLoop.h>

#include <stdlib.h>

#define MAIN_INIT_BAUDRATE 1200
//#define MAIN_EW2LIBTEST_MODE 1

int main()
{
    commonTurnOffWatchdog();
	buttonsSetUpPorts();
	buzzerSetUpPorts();
	diodesSetUpPorts();
	lcdSetUpPorts();
	uartSetUpPorts();
	
	lcdStartUp();
	
	//uartStartUp(MAIN_INIT_BAUDRATE);
	mainloopEnter();

	
	return 0;
}


