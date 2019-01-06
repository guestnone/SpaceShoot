//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

enum ShipType
{
	First,
	Second,
	Third,
	Fourth
};

void gmplUpdatePositions();

void gmplResolveCollision();


void gmplMainPart();

void gmplHighScoreInput();

void gmplSetUp();


MainLoopState gmplLoopEnter();

ShipType gmplShipSelect();