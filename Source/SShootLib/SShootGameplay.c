//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------


char obstacles[2][16];
char bullets[2][16];
char powerUpXPos;
char powerUpYPos;
char powerUpType;
char playerYPos=0;

typedef enum powerUpType
{
	HPUp,
	Defense,
	LaserPowerUp,
	DecreaseSpeed
}powUpType;


void gmplUpdateObjectsPositions()
{
	
	obstacles[0][0]=0;
	obstacles[1][0]=0;
	
	for(int i=0;i<2;i++)
	{
		for(int u=1;u<16;u++)
		{
			if(obstacles[i][u]!=0)
			{
				obstacles[i][u-1]=obstacles[i][u];
				obstacles[i][u]=0;
			}
		}
	}
}
void gmplUpdateBulltetsPositions()
{
	bulltes[0][0]=0;
	bullets[1][0]=0;
	for(int i=0;i<2;i++)
	{
		for(int u=1;u<16;u++)
		{
			if(bullets[u]!=0)
			{
				bullets[i][u-1]=bullets[i][u];
				bullters[i][u]=0;
				
			}
		}
	}
}
void gmplUpdatePowerUpPosition()
{
	if(powerUpXpos!=0)
	{
		powerUpXpos--;
	}
}

void gmplResolveObjectCollision()
{	
	// do napisania funkcje HpDown
	if(playerYPos == 0 && obstacles[0][0]!=0)
	{
		HpDown();	
	}
	if(playerYPos == 1&& obstacles[1][0]!=0)
	{
		HpDown();
	}
	
	if(playerYPos == 0 && bullets[0][0]!=0)
	{
		HpDown();	
	}
	if(playerYPos == 1&& bullets[1][0]!=0)
	{
		HpDown();
	}
	
	if(playerYPos == powerUpYPos && powerUpXPos == 0)
	{
		//do napisania: funkcje do odpalania PowerUpów
		switch(powUpType)
		{
			case HPUp:
				
				break;
			case Defense:
				
				break;
			case LaserPowerUp:
				
				break;
			case DecreaseSpeed:
				
				break;
		}
	}
	
}

