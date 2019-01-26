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
#define AMOUNT_OF_PLAYER_BULLETS 2
#define END_OF_GAMEFIELD 15
#define BEGIN_OF_GAMEFIELD 0
#define AMOUNT_OF_ENEMY_BULLETS 2
#define POWER_UP_MAX_TIME 10
#define SPEED_DECREASE 10
#define TIME_DELAY_INCREASE_VALUE 3000 


#define PLAYER_SHIP_CHAR MSP_LCD_CUSTOM_CHAR_0
#define ENEMY_CHAR MSP_LCD_CUSTOM_CHAR_1
#define BARRIER_CHAR MSP_LCD_CUSTOM_CHAR_2


int score=0;

int gSlowdownTimer = 10000;
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

	randChangeUpperLimit(10);
	
	return randGet()%2;
}

TypeOfObject getRandomObjectType()
{
	if(gPlayer.isPowerUpActive==0)
	{
		randChangeLowerLimit(0);

		randChangeUpperLimit(98);
	}
	else
	{
		randChangeLowerLimit(0);
		randChangeUpperLimit(90);
	}
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
		TypeOfObject type = getRandomObjectType();
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
	int i;
	for(i=0;i<AMOUNT_OF_OBJECTS; i++)
	{
		if(gGameObjects[i].isDeleted==0 && gGameObjects[i].type == enemyBullet)
		{
			gGameObjects[i].x--;
			if(gGameObjects[i].x==254)
			{
				gGameObjects[i].isDeleted = 1;
			}
		}
	}

	for(i=0; i<AMOUNT_OF_PLAYER_BULLETS; ++i)
	{
		if(gPlayer.playerBullets[i].isDeleted == 0)
		{
			gPlayer.playerBullets[i].x++;
			if(gPlayer.playerBullets[i].x==16)
				gPlayer.playerBullets[i].isDeleted=1;
		}
	}
}

void updateSlowElementsPositions()
{
	int i;
	for (i = 0; i<AMOUNT_OF_OBJECTS; i++)
	{
		if (gGameObjects[i].isDeleted == 0 && gGameObjects[i].type != enemyBullet)
		{
			gGameObjects[i].x--;
			if(gGameObjects[i].x==254)
			{
				gGameObjects[i].isDeleted = 1;
			}
		}
	}
}

void pickUpPowerUp(PowerUp powerup)
{
	gPlayer.powerup = powerup;
	score += 2;
	switch(powerup)
	{
		case hp:
			if(gPlayer.lives<3)
				gPlayer.lives++;
		break;
		case barrier:
			gPlayer.powerUpRemainingTime=POWER_UP_MAX_TIME;
			gPlayer.isPowerUpActive=1;
			gPlayer.powerup=barrier;
		break;
		case laser:
			gPlayer.powerUpRemainingTime=POWER_UP_MAX_TIME;
			gPlayer.isPowerUpActive=1;
			gPlayer.powerup=laser;
		break;
		case speed:
			gPlayer.powerUpRemainingTime=POWER_UP_MAX_TIME;
			gSlowdownTimer += TIME_DELAY_INCREASE_VALUE;
		break;
		
	}
}

void decreasePowerUpRemaingTime()
{
	gPlayer.powerUpRemainingTime--;
	if(gPlayer.powerUpRemainingTime==0)
	{
		gPlayer.isPowerUpActive=0;
	}
}

void detectCollisions()
{
	int i; int u;
	for (i=0; i<AMOUNT_OF_OBJECTS; ++i)
	{
		//collision of player with enemy items
		if (gGameObjects[i].isDeleted == 0 && gGameObjects[i].x == 0 && gGameObjects[i].y == gPlayer.y )
		{
			switch (gGameObjects[i].type)
			{
				case enemy:
				case barrier:
				case enemyBullet:
					if(gPlayer.isPowerUpActive==1 && gPlayer.powerup==barrier)
						break;
					gPlayer.lives--;
					gGameObjects[i].isDeleted = 1;
					break;
				case hpPowerUp:
					pickUpPowerUp(hp);
					gGameObjects[i].isDeleted = 1;
					break;
				case barrierPowerUp:
					pickUpPowerUp(barrier);
					gGameObjects[i].isDeleted = 1;
					break;
                case laserPowerUp:
					pickUpPowerUp(laser);
					gGameObjects[i].isDeleted = 1;
					break;
				case decreaseSpeedPowerUp:
					pickUpPowerUp(speed);
					gGameObjects[i].isDeleted = 1;
					break;
			}
		}
		//collision of player bullet with enemy
		for (u = 0; u<AMOUNT_OF_PLAYER_BULLETS; ++u)
		{
			if (gGameObjects[i].isDeleted == 0 && gGameObjects[i].type == enemy
                           && gPlayer.playerBullets[u].isDeleted == 0
                           && gGameObjects[i].x == gPlayer.playerBullets[u].x
                           && gGameObjects[i].y == gPlayer.playerBullets[u].y )
			{
				// enemy
				gGameObjects[i].isDeleted=1;
				gPlayer.playerBullets[u].isDeleted=1;
				score += 5;
			}
			if (gGameObjects[i].isDeleted == 0 
                            && gGameObjects[i].type == barrier
			&& gPlayer.isPowerUpActive==1 
                          && gPlayer.powerup == laser
                           && gPlayer.playerBullets[u].isDeleted == 0
                           && gGameObjects[i].x == gPlayer.playerBullets[u].x
                           && gGameObjects[i].y == gPlayer.playerBullets[u].y )
			{
				// barrier
				gGameObjects[i].isDeleted=1;
				gPlayer.playerBullets[u].isDeleted = 1;
				score += 10;
			}
			
		}
               
	}
}

char doIGenerateAnObject()
{
	randChangeUpperLimit(10);

	randChangeLowerLimit(0);
	if(randGet()<3)
		return 1;
	return 0;
}

void gmplDisplayGameOver()
{
	int i; int j;
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
	
	for(i = 0; i < 5; i++)
	{
		lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
		for(j = 0; i < 16; i++)
 			lcdSendCharacter(240);
	
		lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
 		for(j = 0; i < 16; i++)
 				lcdSendCharacter(240);
	
		lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
		for(j = 0; i < 16; i++)
			lcdSendCharacter(32);
	
		lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
		for(j = 0; i < 16; i++)
			lcdSendCharacter(32);
		commonDelay(700);
	}
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1);
	lcdSendString("     GAME");
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
	lcdSendString("          OVER");
	commonDelay(50000);
	commonDelay(50000);
	commonDelay(50000);
	lcdSendCommand(MSP_LCD_COMMAND_CLEAR_DISPLAY);
}

void gmplRefreshDisplay()
{
	char tmpDisplay[2][16];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 16; j++)
			tmpDisplay[i][j] = 32;

	if (gPlayer.isDead == 0)
		tmpDisplay[gPlayer.y][0] = PLAYER_SHIP_CHAR;
	else
		tmpDisplay[gPlayer.y][0] = 42;
	
	for (int go = 0; go < AMOUNT_OF_OBJECTS; go++)
	{
		if (gGameObjects[go].isDeleted == 0)
		{
			switch(gGameObjects[go].type)
			{
			enemy:
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = ENEMY_CHAR;
				break;
			theBarrier:
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = BARRIER_CHAR;
				break;
			enemyBullet:
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = 183; // 01111011
				break;
			hpPowerUp:
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = 157; // 11011001
				break;
			barrierPowerUp:
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] =60; // 1100011
				break;
			laserPowerUp:
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = 164; // 01001010
				break;
			decreaseSpeedPowerUp:
				tmpDisplay[gGameObjects[go].y][gGameObjects[go].x] = 21; // 01010001
				break;
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
	for(int i = 0; i < 16; i++)
		lcdSendCharacter(tmpDisplay[0][i]);
	lcdSendCommand(MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2);
	for(int i = 0; i < 16; i++)
		lcdSendCharacter(tmpDisplay[1][i]);

}

void gmplMainPart()
{
	char doIUpdateSlowElements = 0;
	char doIGenarateAnObject = 0;
	int slowCounter = 0;
	putObjectOnGamefield();
	while (1)
	{
		score++;
		
		if (slowCounter == 2)
		{
			if(gSlowdownTimer >1000)
				gSlowdownTimer -= 1000;
			slowCounter = 0;
		}
		
		//putObjectOnGamefield();

                
		if(buttonsIsPressed(MSP_BUTTON_FIRST))
		{
			gPlayer.y=(gPlayer.y+1)%2;
		}

		
		detectCollisions();
		
		doIUpdateSlowElements=(doIUpdateSlowElements+1)%2;
		doIGenarateAnObject=(doIGenarateAnObject+1)%6;
		if(doIUpdateSlowElements==1)
		{
			updateSlowElementsPositions();            
		}
                
		if(doIGenarateAnObject==5)
			if(doIGenerateAnObject() == 1)
			{
				putObjectOnGamefield();
			}
		updateFastElementsPositions();
		
		if (gPlayer.lives == 0)
		{	
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
