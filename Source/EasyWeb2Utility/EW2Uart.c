//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------
// UART controller related functions - implementation.
//---------------------------------------------------------------------------

#include <msp430x14x.h>

#include "EW2Uart.h"

void uartSetUpPorts(void)
{
	P3SEL |= MSP_UART_TRANSMIT_PORT + MSP_UART_RECIEVE_PORT;
	P3DIR |= MSP_UART_TRANSMIT_PORT;
	P3DIR &= ~ MSP_UART_RECIEVE_PORT;
}

void uartStartUp(unsigned int baudRate)
{
	int i;
	BCSCTL1 |= XTS;
	// Oscillator flag clear
	do
	{
		IFG1 &= ~OFIFG;
		for (i = 0xFF; i > 0; i--);
	}
	while ((IFG1 & OFIFG));
	BCSCTL2 |= SELM1+SELM0 ;

	switch(baudRate)
	{
	case 1200:
	{
		ME1 |= UTXE0 + URXE0;
		UCTL0 |= CHAR;
		UTCTL0 |= SSEL0;
		UBR00 = 0x0A;
		UBR10 = 0x1A;
		UMCTL0 = 0x5B;
		UCTL0 &= ~SWRST;
		IE1 |= URXIE0;
		break;
	}
	case 2400:
	{
		ME1 |= UTXE0 + URXE0;
		UCTL0 |= CHAR;
		UTCTL0 |= SSEL0;
		UBR00 = 0x05;
		UBR10 = 0x0D;
		UMCTL0 = 0x24;
		UCTL0 &= ~SWRST;
		IE1 |= URXIE0;
		break;
	}
	case 9600:
	{
		ME1 |= UTXE0 + URXE0;
		UCTL0 |= CHAR;
		UTCTL0 |= SSEL0;
		UBR00 = 0x41;
		UBR10 = 0x03;
		UMCTL0 = 0x5B;
		UCTL0 &= ~SWRST;
		IE1 |= URXIE0;
		break;
	}
	case 115200:
	{
		ME1 |= UTXE0 + URXE0;
		UCTL0 |= CHAR;
		UTCTL0 |= SSEL0;
		UBR00 = 0x45;
		UBR10 = 0x00;
		UMCTL0 = 0x2A;
		UCTL0 &= ~SWRST;
		IE1 |= URXIE0;
		break;
	}
	default: // 1200 bps
	{
		ME1 |= UTXE0 + URXE0;
		UCTL0 |= CHAR;
		UTCTL0 |= SSEL0;
		UBR00 = 0x0A;
		UBR10 = 0x1A;
		UMCTL0 = 0x5B;
		UCTL0 &= ~SWRST;
		IE1 |= URXIE0;
		break;
	}
	}
}

void uartTransmitCharacter(unsigned char character)
{
	while ((IFG1 & UTXIFG0) == 0);
		MSP_UART_TRANSMIT_BUFFER = character;
}


void uartTransmitString(char *string)
{
	while(*string)
		uartTransmitCharacter(*string++);  
}
