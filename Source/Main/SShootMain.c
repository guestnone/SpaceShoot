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
#include <SShootLib/SShootMainLoop.h>

#define MAIN_INIT_BAUDRATE 1200
#define MAIN_EW2LIBTEST_MODE 1

void mainStartUpDevice()
{
	commonTurnOffWatchdog();
	
	// port set-up
	buttonsSetUpPorts();
	buzzerSetUpPorts();
	diodesSetUpPorts();
	lcdSetUpPorts();
	uartSetUpPorts();
	
	lcdStartUp();
	uartStartUp(MAIN_INIT_BAUDRATE);
	
}

if MAIN_EW2LIBTEST_MODE
int main()
{
	mainStartUpDevice();
	// @todo plug (implemented) tests for EW2 lib
	
	return 0;
}
#else
int main()
{
	mainStartUpDevice();
	mainloopEnter();

	
	return 0;
}
#endif