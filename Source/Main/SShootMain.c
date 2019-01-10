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
//#include <SShootLib/SShootMainLoop.h>

#include <stdlib.h>

#define MAIN_INIT_BAUDRATE 1200
//#define MAIN_EW2LIBTEST_MODE 1

int main()
{
	commonTurnOffWatchdog();
	
	// port set-up
	buttonsSetUpPorts();
	buzzerSetUpPorts();
	diodesSetUpPorts();
	commonDelay(100*100); //10ms
	lcdSetUpPorts();
	uartSetUpPorts();
	
	commonDelay(100*100); //10ms
	lcdStartUp();
	
	uartStartUp(MAIN_INIT_BAUDRATE);
	
	lcdSendCharacter('B');
	lcdSendCharacter('B');
	lcdSendCharacter('C');
	randInit(150, 50);
	lcdSendCharacter('B');
	lcdSendCharacter('B');
	lcdSendCharacter('C');
	int rand = randGet();
	lcdSendCharacter('B');
	lcdSendCharacter('B');
	lcdSendCharacter('C');
	buzzerSwitch(MSP_BUZZER_TYPE1);
	buzzerSwitch(MSP_BUZZER_TYPE1);
	buzzerSwitch(MSP_BUZZER_TYPE1);
	buzzerSwitch(MSP_BUZZER_TYPE1);
	buzzerSwitch(MSP_BUZZER_TYPE1);
	
	while(true) {
	diodesSwitch(MSP_DIODES_STATUS);
	if ( buttonsIsPressed(MSP_BUTTON_FIRST))
	diodesSwitch(MSP_DIODES_RELAY_TYPE1);
	if ( buttonsIsPressed(MSP_BUTTON_SECOND))
	diodesSwitch(MSP_DIODES_RELAY_TYPE2);
	}
	// @todo plug (implemented) tests for EW2 lib
	
	return 0;
}
/**
#else
int main()
{
	mainStartUpDevice();
	mainloopEnter();

	
	return 0;
}
#endif
*/
