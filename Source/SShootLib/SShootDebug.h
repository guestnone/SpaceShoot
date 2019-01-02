//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once

#include "SShootConfig.h"

#ifdef SSHOOT_DEBUG

/** Type of the channel for the message. */
enum LogChannel
{
	Debug = 0,
	Warning = 1,
	Error = 2
};

/**
 * Sends the log message to UART output.
 *
 * @param      message  Text of the message.
 * @param[in]  channel  Type of message.
 * 
 * @note Internal function, please use the LOG macro.
 */
void debugUartLog(char* message, LogChannel channel);

/**
 * Shortcut for sending the log message to the UART output. Dependent on SSHOOT_DEBUG variable
 * (used to turn on/off the debug mode, if off it will do nothing)
 *
 * @param      msg   Text of the message.
 * @param      chan  Type of message.
 */
#define LOG(msg, chan) debugUartLog(msg, chan);

#else

#define LOG(msg) ((void)0)

#endif