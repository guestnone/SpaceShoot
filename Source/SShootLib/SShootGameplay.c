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
char playerXpos=0;
char beginOfObstacles = 0;
char beginOfBullets   = 0;
char beginOfPowerUp   = 0;
char lifesLeft=3;

char idOfBullet=0;
typedef struct playerBullet
{
	char x;
	char y;
	char isShot=0;
} playerBullets[2];


typedef enum powerUpType
{
	HPUp,
	Defense,
	LaserPowerUp,
	DecreaseSpeed
}powUpType;

void gmplUpdatePlayerXPos()
{
	playerXPos=(playerXPos+1)%16;	
}
void gmplUpdateObjectsPositions()
{
	beginOfObstacles=(beginOfObstacles+1)%16;
	obstacles[0][beginOfObstacles]=0;
	obstacles[1][beginOfObstacles]=0;
}

void gmplDetectPlayerBulletCollision()
{
		for(char i=0;i<2;++i)
		{
			char y = playerBullets[i].y;
			char x=(playerBullets[i].x + beginOfObstacles )%16;
			if(obstacles[y][x]==2)
			{
				enemyIsDown(y,x);	
			}
		}
}
void gmplPlayerShootBullet()
{
	playerBullets[idOfBullet].y=playerYPos;
	playerBullets[idOfBullet].x=0;
}
void gmplMovePlayerBullets()
{
	for(char i=0;i<2;++i)
	{
		if(playerBullets[i].isShot==true)
		{
			playerBullets[i].x=(playerBullets[i].x+1)%16;	
		}
	}
}
void gmplEnemyShootBullet(char y)
{
	bullets[y][beginOfBullets]=1;
}
void gmplUpdateEnemyBulltetsPositions()
{
	beginOfBullets=(beginOfBullets+1)%16;
	bullets[0][beginOfBullets=0;
	bullets[1][beginOfBullets]=0;
}
void gmplUpdatePowerUpPosition()
{
	
	beginOfPowerUp=(beginOfPowerUp+1)%16;
	
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
	
	
	
	
}
void HpDown()
{
	lifesLeft--;
	if(lifesLeft==0)
	{
		gameOver();	
	}
}
