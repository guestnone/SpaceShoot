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



#define MAIN_INIT_BAUDRATE 1200

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
	void uartStartUp(MAIN_INIT_BAUDRATE);
	
}

int main()
{
	int x, y;
	char tab[10][10];
	mainStartUpDevice();
	
	
	return 0;
}