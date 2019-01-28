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

/**
 * This is the main entry point of the program. It sets up the hardware and then passes the excecution 
 * to the game librarys main loop
 */
int main()
{
    
	commonTurnOffWatchdog();
	buttonsSetUpPorts();
	initBuzzer();
	diodesSetUpPorts();
	lcdSetUpPorts();
	
	lcdStartUp();
	
	mainloopEnter();

	
	return 0;
}


