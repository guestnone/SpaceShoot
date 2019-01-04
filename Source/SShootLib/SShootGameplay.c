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

char beginOfObstacles = 0;
char beginOfBullets   = 0;
char beginOfPowerUp   = 0;
char lifesLeft=3;

char idOfBullet=0;
typedef struct playerBullet
{
	char x;
	char y;
	char isDown=1;
} playerBullets[2];


typedef enum powerUpType
{
	HPUp,
	Defense,
	LaserPowerUp,
	DecreaseSpeed
}powUpType;


void gmplUpdateObjectsPositions()
{
	beginOfObstacles=(beginOfObstacles+1)%16;
	obstacles[0][beginOfObstacles]=0;
	obstacles[1][beginOfObstacles]=0;
	
	
	
	/*
	obstacles[0][0]=0;
	obstacles[0][0]=0;
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
	}*/
}

void gmplDetectPlayerBulletCollision()
{
		
}
void gmplPlayerShootBullet()
{
	playerBullets[idOfBullet].x=player
}

void gmplEnemyShootBullet()
{

}
void gmplUpdateBulltetsPositions()
{
	beginOfBullets=(beginOfBullets+1)%16;
	bullets[0][beginOfBullets=0;
	bullets[1][beginOfBullets]=0;
	
	/*
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
	*/
}
void gmplUpdatePowerUpPosition()
{
	
	beginOfPowerUp=(beginOfPowerUp+1)%16;
	
	/*
	if(powerUpXpos!=0)
	{
		powerUpXpos--;
	}
	*/
}

void gmplResolveObjectCollision()
{	
	// do napisania funkcje HpDown
	
	if(playerYPos == 0 && obstacles[0][beginOfObstacles]!=0)
	{
		HpDown();	
	}
	if(playerYPos == 1&& obstacles[1][beginOfObstacles]!=0)
	{
		HpDown();
	}
	
	if(playerYPos == 0 && bullets[0][beginOfBullets]!=0)
	{
		HpDown();	
	}
	if(playerYPos == 1&& bullets[1][BeginOfBullets]!=0)
	{
		HpDown();
	}
	
	if(playerYPos == powerUpYPos && beginOfPowerUp == powerUpXPos)
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
	
	
	/*
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
	}*/
	
}
void HpDown()
{
	lifesLeft--;
	if(lifesLeft==0)
	{
		gameOver();	
	}
}
