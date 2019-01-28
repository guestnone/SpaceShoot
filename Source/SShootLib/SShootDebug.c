//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "SShootDebug.h"

#ifdef SSHOOT_DEBUG
#include <EasyWeb2Utility/EW2Uart.h>


void debugUartLog(char* message, LogChannel channel)
{
	char dbgLabel[] = "[DEBUG]: ";
	char warnLabel[] = "[WARNING]: ";
	char errLabel[] = "[ERROR]: ";
	switch(channel)
	{
	case Debug:
		uartTransmitString(dbgLabel);
		uartTransmitString(message);
		break;
	case Warning:
		uartTransmitString(warnLabel);
		uartTransmitString(message);
		break;
	case Error:
		uartTransmitString(errLabel);
		uartTransmitString(message);
		break;
	}
}


#endif
