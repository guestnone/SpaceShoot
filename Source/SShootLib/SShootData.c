//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

void dataCreateCustomScreenCharset(char chars[8][8])
{
	SEND_CMD(CG_RAM_ADDR);
	for(int i=0;i<8;i++)
	{
		for(int u=0;u<8;u++)
		{
			SEND_CHAR(chars[i][u]);
		}
	}
}
