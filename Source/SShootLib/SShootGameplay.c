//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "SShootGameplay.h"

/*

#include "EasyWeb2Utility/CommonRand.h"
#include "EasyWeb2Utility/CommonUtil.h"
#include "EasyWeb2Utility/EW2Lcd.h"
char obstacles[2][16];
char bullets[2][16];
char powerUpXPos;
char powerUpYPos;
//char powerUpType;
char playerYPos=0;
char playerXPos=0;
char beginOfObstacles = 0;
char beginOfBullets   = 0;
//char beginOfPowerUp   = 0;
char lifesLeft = 3 ;

int gSlowdownTimer = 30000;

bool isDead = false;

char idOfBullet=0;

typedef struct playerBullet
{
	char x;
	char y;
	char isShot;
} playerBullet;

playerBullet playerBullets[2];

typedef enum powerUpType
{
	HPUp,
	Defense,
	LaserPowerUp,
	DecreaseSpeed
} powerUpType;



typedef struct powerUp
{
	powerUpType powerUpType1;
	char x;
	char y;
	char beginOfPowerUp;
	
} powerUp1;

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

void clearJunk()
{
	obstacles[0][beginOfObstacles]=0;
	obstacles[1][beginOfObstacles]=0;	
}

void gmplDetectPlayerBulletCollision()
{
		for(char i=0;i<2;++i)
		{
			char y = playerBullets[i].y;
			char x = ((playerBullets[i].x) + beginOfObstacles )%16;
			if(obstacles[y][x]==2)
			{
				gmplEnemyIsDown(y,x);	
			}
		}
}

void gmplPutBarrierOnGamefield(char y)
{
	obstacles[y][(beginOfObstacles-1+16)%16]=1;
}
	
void gmplPutEnemyOnGamefield(char y)
{
	obstacles[y][(beginOfObstacles-1+16)%16]=2;
	gmplEnemyShootBullet(y);
	
}

void gmplPutPowerUpOnGamefield(char y, powerUpType put)
{
	powerUp1.powerUpType1 = put;
	powerUp1.x=0;
	powerUp1.y=y;
}

char gmplDoIGenerateNewObject()
{
	randChangeLowerLimit(0);
	randChangeUpperLimit(10);
	char result = randGet();
	if(result>5)
	{
		return 1;
	}
	else
	{
		return 0;	
	}
}

char gmplRandomObject()
{
	randChangeLowerLimit(0);
	randChangeUpperLimit(10);
	char result = randGet();
	if(result < 1)
	{
		return 0; 
	}
	else if(result <5)
	{
		return 1;
	}
	else 
	{
		return 2;	
	}
}

char gmplRandomYCoord()
{
	randChangeLowerLimit(0);
	randChangeUpperLimit(1);
	return randGet();
}

char gmplRandomPowerUp()
{
	randChangeLowerLimit(0);
	randChangeUpperLimit(3);
	return randGet();
}

void gmplGenerateNewObject()
{
	char y = gmplRandomYCoord();
	unsigned char typeOfObject = gmplRandomObject();
	if(typeOfObject==0)//power up
	switch(typeOfObject)
	{
		case 0://power up
			{
				char typeOfPowerUp = gmplRandomPowerUp();
				gmplPutPowerUpOnGamefield(y,typeOfPowerUp);
			}
			break;
		case 1://enemy
			gmplPutEnemyOnGamefield(y);
			break;
		case 2://barrier
			gmplPutBarrierOnGamefield(y);
			break;
	}
}

void gmplEnemyIsDown(char x,char y)
{
	obstacles[y][x]=0;	
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
	
	powerUp1.beginOfPowerUp=(beginOfPowerUp+1)%16;
	//or
	powerUp1.x--;
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
		isDead = true;
	}
}


void gmplDisplayGameOver()
{
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);

	lcdSendString("     GAME");
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
	lcdSendString("          OVER");
	commonDelay(20000);
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
}

void gmplRefreshDisplay()
{
	char tmpDisplay[2][16];


}

void gmplMainPart()
{
	while (1)
	{


		gmplRefreshDisplay();

		if (isDead)
		{
			gmplDisplayGameOver();
		}
		commonDelay(gSlowdownTimer);
	}

}


ShipType gmplShipSelect()
{

}
*/
MainLoopState gmplLoopEnter()
{
	//ShipType sType = gmplShipSelect();
	//gmplSetUp();
	//gmplMainPart();
	//gmplHighScoreInput();

	return MainScreen;
}
