//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once

#define MSP_UART_TRANSMIT_PORT  0x10                 // P3.4
#define MSP_UART_RECIEVE_PORT   0x20                 // P3.5
#define MSP_UART_TRANSMIT_BUFFER TXBUF0
#define MSP_UART_RECIEVE_BUFFER RXBUF0 

void uartSetUpPorts(void);

void uartStartUp(unsigned int baudRate);

void uartTransmitCharacter(unsigned char character);

void uartTransmitString(char *string);