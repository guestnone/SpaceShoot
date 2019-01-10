//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// UART controller related functions - definitions.
//---------------------------------------------------------------------------

#pragma once

/** Ports used to perform trasmission between devices */
#define MSP_UART_TRANSMIT_PORT  0x10                 // P3.4
#define MSP_UART_RECIEVE_PORT   0x20                 // P3.5

/** Buffers used to recieve and transmit data between connected device. */
#define MSP_UART_TRANSMIT_BUFFER TXBUF0
#define MSP_UART_RECIEVE_BUFFER RXBUF0 

/**
 * Sets up the ports for UART controller.
 * 
 * @note This doesn't initializes the controller.
 * Please, call the uartStartUp function to properly initialize the controller.
 */
void uartSetUpPorts(void);

/**
 * Initializes the UART controller/
 *
 * @param[in]  baudRate  The rate in which the data are transmitted.
 * @note Supported values are: 1200, 2400, 9600 and 115200.
 */
void uartStartUp(unsigned int baudRate);

/**
 * Sends one character to the recieving device.
 *
 * @param[in]  character  Given character
 */
void uartTransmitCharacter(unsigned char character);

/**
 * Sends the series of characters to the recieving device.
 *
 * @param      string  Given set of characters.
 */
void uartTransmitString(char *string);
