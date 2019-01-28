//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "SShootMainLoop.h"
#include "SShootMenu.h"
#include "SShootGameplay.h"
#include "EasyWeb2Utility/CommonUtil.h"

void mainloopEnter()
{
	MainLoopState mainLS = MainScreen;
        
	while(true)
	{
		if (mainLS == MainScreen)
		{
			mainLS = menuMainWindow();
		}

		if (mainLS == Game)
		{
			mainLS = gmplLoopEnter();
		}	

		if (mainLS == About)
		{
			mainLS = menuAbout();
		}		

	}

}
