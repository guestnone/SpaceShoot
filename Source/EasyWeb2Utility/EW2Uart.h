//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// UART controller related functions - definitions.
//---------------------------------------------------------------------------

#pragma once

/** @addtogroup UART
 *  @{
 */

/** Port used to perform transmission to the connected device */
#define MSP_UART_TRANSMIT_PORT  0x10                 // P3.4
/** Port used to receive data from connected device */
#define MSP_UART_RECIEVE_PORT   0x20                 // P3.5

/** Buffers used to transmit data to connected device. */
#define MSP_UART_TRANSMIT_BUFFER TXBUF0
/** Buffers used to receive data from connected device. */
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
 * Sends one character to the receiving device.
 *
 * @param[in]  character  Given character
 */
void uartTransmitCharacter(unsigned char character);

/**
 * Sends the series of characters to the receiving device.
 *
 * @param      string  Given set of characters.
 */
void uartTransmitString(char *string);

/* @} */
