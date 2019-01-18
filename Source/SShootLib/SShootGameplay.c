//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#include "SShootGameplay.h"
#include "SShootData.h"
#include "EasyWeb2Utility/CommonRand.h"
#include "EasyWeb2Utility/CommonUtil.h"
#include "EasyWeb2Utility/EW2Lcd.h"
#include "EasyWeb2Utility/EW2Buttons.h"

char AMMOUNT_OF_OBJECTS =10;
char AMMOUNT_OF_PLAYER_BULLETS = 2;
char END_OF_GAMEFIELD =15;
char BEGIN_OF_GAMEFIELD = 0;

int gSlowdownTimer = 30000;

///////////begin of edit

typedef enum powerUp
{
	hp,barrier,laser,speed
}powerUp;

typedef struct playerBullet
{
	char x;
	char y;
	char isDeleted;
}playerBullet;


typedef struct playerObject
{
	char lives;
	char y;
	char isPowerUpActive;
	powerUp powerup;
	playerBullet playerBullets[2];
        char isDead;
} playerObject;

typedef enum typeOfObject
{
	enemy,
	theBarrier,
	enemyBullet,
        thePlayerBullet,
	hpPowerUp,
	barrierPowerUp,
	laserPowerUp,
	decreaseSpeedPowerUp
}typeOfObject;

typedef struct gameObject
{
	char x;
	char y;
	typeOfObject type;
	char isDeleted;
}gameObject;


gameObject gameObjects[10];
playerObject player;
void shootPlayerBullet()
{
	for(int i=0;i<AMMOUNT_OF_PLAYER_BULLETS;++i)
	{
		if(player.playerBullets[i].isDeleted == 1)
		{
			player.playerBullets[i].x=BEGIN_OF_GAMEFIELD+1;
			player.playerBullets[i].y=player.y;
			player.playerBullets[i].isDeleted=0;
			break;
		}
	}
}
void shootEnemyBullet(char x,char y)
{
	for(int i=0;i<AMMOUNT_OF_OBJECTS;++i)
	{
		if(gameObjects[i].isDeleted == 1)
		{
			gameObjects[i].isDeleted=0;
			gameObjects[i].y=y;
			gameObjects[i].x=x;
			break;
		}
	}
}

char getYPos()
{
	randChangeLowerLimit(0);

	randChangeUpperLimit(1);
	
	return randGet();
}

typeOfObject getObjectType()
{
	randChangeLowerLimit(0);

	randChangeUpperLimit(98);
	int result = randGet();
	if(result<=50)
	{
		return enemy;
	}
	if(result <= 90)
	{
		return theBarrier;
	}
	if(result <= 92)
	{
		return hpPowerUp;
	}
	if(result <= 94)
	{
		return barrierPowerUp;
	}
	if(result <= 96)
	{
		return laserPowerUp;
	}
	return decreaseSpeedPowerUp;
}
void putObjectOnGamefield()
{
		typeOfObject type = getObjectType();
		char y = getYPos();
		for(int i=0;i<AMMOUNT_OF_OBJECTS;++i)
		{
			if(gameObjects[i].isDeleted == 1)
			{
				gameObjects[i].y=y;
				gameObjects[i].x=END_OF_GAMEFIELD;
				gameObjects[i].type=type;
				gameObjects[i].isDeleted=0;
				break;
			}
		}
}
void updateFastElementsPositions()
{
	for(int i=0;i<AMMOUNT_OF_OBJECTS; i++)
	{
		if(gameObjects[i].isDeleted==0)
		{
			switch(gameObjects[i].type)
			{
				case enemyBullet:
					gameObjects[i].x--;
				break;
				case thePlayerBullet:
					gameObjects[i].x++;
				break;
				
			}
		}
	}
	
	for(int i=0;i<AMMOUNT_OF_PLAYER_BULLETS;++i)
	{
		if(player.playerBullets[i].isDeleted == 0)
		{
			player.playerBullets[i].x++;
		}
	}
}
void updateSlowElementsPositions()
{
	for(int i=0;i<AMMOUNT_OF_OBJECTS; i++)
	{
		if(gameObjects[i].isDeleted==0)
		{
			switch(gameObjects[i].type)
			{
				case enemy:
					gameObjects[i].x--;
				break;
				case theBarrier:
					gameObjects[i].x--;
				break;
				
				case hpPowerUp:
					gameObjects[i].x--;
				break;
				case barrierPowerUp:
					gameObjects[i].x--;
				break;
				case laserPowerUp:
					gameObjects[i].x--;
				break;
				case decreaseSpeedPowerUp:
					gameObjects[i].x--;
				break;
			}
		}
	}
}

void gmplPrepareStuff()
{
	for(int i=0;i<AMMOUNT_OF_OBJECTS;++i)
	{
		gameObjects[i].isDeleted=1;
	}
	for(int i=0;i<AMMOUNT_OF_PLAYER_BULLETS;++i)
	{
		player.playerBullets[i].isDeleted=1;
	}
	
	player.lives=3;
	player.y=0;
	player.isPowerUpActive=0;
}
void decreaseHp()
{
	player.lives--;
	
}
void pickUpPowerUp(powerUp powerup)
{
	player.powerup = powerup;
}
void CollisionOfPlayerBulletWithEnemy(int idOfEnemy)
{
	gameObjects[idOfEnemy].isDeleted=1;
	decreaseHp();
}
void detectCollisions()
{
	for(int i=0;i<AMMOUNT_OF_OBJECTS;++i)
	{
		if(gameObjects[i].isDeleted==0 && gameObjects[i].x==0 && gameObjects[i].y==player.y )
		{
			switch(gameObjects[i].type)
			{
				
				case enemy:
					decreaseHp();
					break;
				case barrier:
					decreaseHp();
					break;
				case enemyBullet:
					decreaseHp();
					break;
				case hpPowerUp:
					pickUpPowerUp(hp);
					break;
				case barrierPowerUp:
					pickUpPowerUp(barrier);
					break;
                                case laserPowerUp:
					pickUpPowerUp(laser);
					break;
				case decreaseSpeedPowerUp:
					pickUpPowerUp(speed);
					break;
			}
		}
		for(int u=0;u<AMMOUNT_OF_PLAYER_BULLETS;++u)
		{
			if(gameObjects[i].isDeleted==0 && gameObjects[i].type == enemy
                           && player.playerBullets[u].isDeleted==0
                           && gameObjects[i].x == player.playerBullets[u].x
                           && gameObjects[i].y == player.playerBullets[u].y )
			{
				CollisionOfPlayerBulletWithEnemy(i);
			}
		}
	}
}
char doIGenerateAnObject()
{
	randChangeUpperLimit(10);

	randChangeLowerLimit(0);
	if(randGet()>3)
		return 0;
	return 1;
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

		if (player.isDead == 1)
		{
			gmplDisplayGameOver();
		}
		commonDelay(gSlowdownTimer);
	}

}




ShipType gmplShipSelect()
{
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
	ShipType ret = First;
	char pressed = 0;
	dataUploadAllShipCustomChars();
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
	lcdSendString("Select a Ship");
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
	lcdSendString("1.");
	lcdSendCharacter(MSP_LCD_CUSTOM_CHAR_0);
	lcdSendString(" 2.");
	lcdSendCharacter(MSP_LCD_CUSTOM_CHAR_1);
	lcdSendString(" 3.");
	lcdSendCharacter(MSP_LCD_CUSTOM_CHAR_2);
	lcdSendString(" 4.");
	lcdSendCharacter(MSP_LCD_CUSTOM_CHAR_3);
	
	
	
	while (pressed == 0)
	{
		if (buttonsIsPressed(MSP_BUTTON_FIRST))
		{
			ret = First;
			pressed = 1;
		}
		
		if (buttonsIsPressed(MSP_BUTTON_SECOND))
		{
			ret = Second;
			pressed = 1;
		}
		    
		if (buttonsIsPressed(MSP_BUTTON_THIRD))
		{
			ret = Third;
			pressed = 1;
		}
		    
		if (buttonsIsPressed(MSP_BUTTON_FOURTH))
		{
			ret = Fourth;
			pressed = 1;
		}
	}
		    
	return ret;
}

void gmplSetUp(ShipType ship)
{
	// set the characters
	
	dataSwitchCustomScreenCharset(ship);
	
	// set the variables
	player.lives = 3;
	player.y = 0;
	player.isPowerUpActive = 0;
	player.playerBullets[0].isDeleted = 1;
	player.playerBullets[1].isDeleted = 1;
	player.isDead = 0;
	
	for (int i = 0; i < 10; i++)
	{
		 gameObjects[i].isDeleted = 1;
	}
}

MainLoopState gmplLoopEnter()
{
	ShipType sType = gmplShipSelect();
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
	gmplSetUp(sType);
	//gmplMainPart();

	return MainScreen;
}
