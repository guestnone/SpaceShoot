//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------


void commonDelay(unsigned int us)
{
	int count;
	for (count = 0 ; count != us; ++count)
	{
		_NOP();
		_NOP();
		_NOP();
		_NOP();
	}
}