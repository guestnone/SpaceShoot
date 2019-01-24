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

#define AMOUNT_OF_OBJECTS 10
char AMOUNT_OF_PLAYER_BULLETS = 2;
char END_OF_GAMEFIELD = 15;
char BEGIN_OF_GAMEFIELD = 0;
#define AMOUNT_OF_ENEMY_BULLETS 2

#define PLAYER_SHIP_CHAR MSP_LCD_CUSTOM_CHAR_0
#define ENEMY_CHAR MSP_LCD_CUSTOM_CHAR_1
#define BARRIER_CHAR MSP_LCD_CUSTOM_CHAR_2

int gSlowdownTimer = 30000;
GameObject gGameObjects[AMOUNT_OF_OBJECTS];
PlayerObject gPlayer;
Bullet enemyBullets[AMOUNT_OF_ENEMY_BULLETS];


void shootPlayerBullet()
{
	for (int i=0;i<AMOUNT_OF_PLAYER_BULLETS;++i)
	{
		if (gPlayer.playerBullets[i].isDeleted == 1)
		{
			gPlayer.playerBullets[i].x = BEGIN_OF_GAMEFIELD + 1;
			gPlayer.playerBullets[i].y = gPlayer.y;
			gPlayer.playerBullets[i].isDeleted = 0;
			break;
		}
	}
}
void shootEnemyBullet(char x,char y)
{
	for (int i=0; i<AMOUNT_OF_OBJECTS; ++i)
	{
		if (gGameObjects[i].isDeleted == 1)
		{
			gGameObjects[i].isDeleted = 0;
			gGameObjects[i].y = y;
			gGameObjects[i].x = x;
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

TypeOfObject getObjectType()
{
	randChangeLowerLimit(0);

	randChangeUpperLimit(98);
	int result = randGet();
	if (result <= 50)
	{
		return enemy;
	}
	if (result <= 90)
	{
		return theBarrier;
	}
	if (result <= 92)
	{
		return hpPowerUp;
	}
	if (result <= 94)
	{
		return barrierPowerUp;
	}
	if (result <= 96)
	{
		return laserPowerUp;
	}
	return decreaseSpeedPowerUp;
}
void putObjectOnGamefield()
{
		TypeOfObject type = getObjectType();
		char y = getYPos();
		for (int i=0; i<AMOUNT_OF_OBJECTS; ++i)
		{
			if (gGameObjects[i].isDeleted == 1)
			{
				gGameObjects[i].y = y;
				gGameObjects[i].x = END_OF_GAMEFIELD;
				gGameObjects[i].type = type;
				gGameObjects[i].isDeleted = 0;
				break;
			}
		}
}
void updateFastElementsPositions()
{
	
        
        for(int i=0;i<AMOUNT_OF_ENEMY_BULLETS;++i)
        {
          if(enemyBullets[i].isDeleted == 0)
          {
            enemyBullets[i].x--; 
          }
        }
	
	for(int i=0; i<AMOUNT_OF_PLAYER_BULLETS; ++i)
	{
		if(gPlayer.playerBullets[i].isDeleted == 0)
		{
			gPlayer.playerBullets[i].x++;
		}
	}
}
void updateSlowElementsPositions()
{
	for (int i = 0; i<AMOUNT_OF_OBJECTS; i++)
	{
		if (gGameObjects[i].isDeleted == 0)
		{
			switch (gGameObjects[i].type)
			{
			case enemy:
				gGameObjects[i].x--;
			break;
			case theBarrier:
				gGameObjects[i].x--;
			break;
				
			case hpPowerUp:
				gGameObjects[i].x--;
			break;
			case barrierPowerUp:
				gGameObjects[i].x--;
			break;
			case laserPowerUp:
				gGameObjects[i].x--;
			break;
			case decreaseSpeedPowerUp:
				gGameObjects[i].x--;
			break;
			}
		}
	}
}

void decreaseHp()
{
	gPlayer.lives--;
	
}

void pickUpPowerUp(PowerUp powerup)
{
	gPlayer.powerup = powerup;
}

void CollisionOfPlayerBulletWithEnemy(int idOfEnemy)
{
	gGameObjects[idOfEnemy].isDeleted=1;
	decreaseHp();
}

void detectCollisions()
{
	for (int i=0; i<AMOUNT_OF_OBJECTS; ++i)
	{
		if (gGameObjects[i].isDeleted == 0 && gGameObjects[i].x == 0 && gGameObjects[i].y == gPlayer.y )
		{
			switch (gGameObjects[i].type)
			{
				
				case enemy:
					decreaseHp();
					break;
				case barrier:
					decreaseHp();
					break;
				//case enemyBullet:
				//	decreaseHp();
				//	break;
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
		for (int u = 0; u<AMOUNT_OF_PLAYER_BULLETS; ++u)
		{
			if (gGameObjects[i].isDeleted == 0 && gGameObjects[i].type == enemy
                           && gPlayer.playerBullets[u].isDeleted == 0
                           && gGameObjects[i].x == gPlayer.playerBullets[u].x
                           && gGameObjects[i].y == gPlayer.playerBullets[u].y )
			{
				CollisionOfPlayerBulletWithEnemy(i);
			}
		}
                for(int i=0;i<AMOUNT_OF_PLAYER_BULLETS)
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
	for (int i = 0; i < 2; i++)
		for (int j = 2; j < 16; j++)
			tmpDisplay[i][j] = 0;

	if (gPlayer.isDead == 0)
		tmpDisplay[gPlayer.y][0] = PLAYER_SHIP_CHAR;
	else
		tmpDisplay[gPlayer.y][0] = 42;

	for (int go = 0; go < AMOUNT_OF_OBJECTS; go++)
	{
		if (gGameObjects[go].isDeleted == 0)
		{
			if (gGameObjects[go].type == enemy)
			{
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = ENEMY_CHAR;
			}

			if (gGameObjects[go].type == theBarrier)
			{
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = BARRIER_CHAR;
			}

			/*if (gGameObjects[go].type == enemyBullet || gGameObjects[go].type == thePlayerBullet)
			{
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = 183; // 01111011
			}*/

			if (gGameObjects[go].type == hpPowerUp)
			{
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = 157; // 11011001
			}

			if (gGameObjects[go].type == barrierPowerUp)
			{
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] =60 // 1100011
			}

			if (gGameObjects[go].type == laserPowerUp)
			{
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = 164; // 01001010
			}

			if (gGameObjects[go].type == decreaseSpeedPowerUp)
			{
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = 21; // 01010001
			}
		}
	}

	for (int pb = 0; pb < AMOUNT_OF_PLAYER_BULLETS; pb++)
	{
		if (gPlayer.playerBullets[pb].isDeleted == 0)
		{
			tmpDisplay[gPlayer.playerBullets[pb].y][gPlayer.playerBullets[pb].x] = 183; // 01111011
		}
	}
        
        
        
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
	lcdSendString(tmpDisplay[0]);
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
	lcdSendString(tmpDisplay[1]);

}

void gmplMainPart()
{
	while (1)
	{
		int slowCounter = 0;
		if (slowCounter == 20)
		{
			gSlowdownTimer = gSlowdownTimer - 1000;
                       
		}
                putObjectOnGamefield();
                

		// pawełs code gets called here

		if (gPlayer.isDead == 1)
		{	
			gmplRefreshDisplay();
                        commonDelay(20000);
			gmplDisplayGameOver();
			break;
		}

		gmplRefreshDisplay();

		commonDelay(gSlowdownTimer);
                slowCounter++;
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
	gPlayer.lives = 3;
	gPlayer.y = 0;
	gPlayer.isPowerUpActive = 0;
	gPlayer.isDead = 0;

	for(int i = 0; i<AMOUNT_OF_OBJECTS; ++i)
	{
		gGameObjects[i].isDeleted = 1;
	}
	
	for(int i = 0; i<AMOUNT_OF_PLAYER_BULLETS; ++i)
	{
		gPlayer.playerBullets[i].isDeleted = 1;
	}
        for(int i=0; i < AMOUNT_OF_ENEMY_BULLETS; i++)
        {
                enemyBullets[i].isDeleted=1; 
        }

	gSlowdownTimer = 30000;
}

MainLoopState gmplLoopEnter()
{
	ShipType sType = gmplShipSelect();
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
	gmplSetUp(sType);
	gmplMainPart();

	return MainScreen;
}
