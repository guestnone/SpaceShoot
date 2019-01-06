//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "SShootGameplay.h"

void gmplMainPart()
{
	// Paweł's stuff gets called here.
}

MainLoopState gmplLoopEnter()
{
	ShipType sType = gmplShipSelect();
	gmplSetUp();
	gmplMainPart();
	gmplHighScoreInput();

	return MainWindow;
}