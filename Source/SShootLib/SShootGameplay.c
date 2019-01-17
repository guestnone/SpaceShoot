//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------


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

typedef struct playerObject
{
	char lives;
	char y;
	char isPowerUpActive;
	powerUp powerup;
	playerBullet playerBullets[2];
}playerObject;

typedef enum typeOfObject
{
	enemy,
	barrier,
	enemyBullet,
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
typedef struct playerBullet
{
	char x;
	char y;
	char IsDeleted;
}playerBullet;


gameObject gameObjects[10];
playerObject player;
void shootPlayerBullet()
{
	for(int i=0;i<AMMOUNT_OF_PLAYER_BULLETS;++i)
	{
		if(player.playerBullets[i].isDeleted=1)
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
		if(gameObjects[i].isDeleted=1)
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
char getObjectType()
{
	randChangeLowerLimit(0);

	randChangeUpperLimit(98);
	result = randGet();
	if(result<=50)
	{
		return enemy;
	}
	if(result <= 90)
	{
		return barrier;
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
			if(gameObjects[i].isDeleted = 1)
			{
				gameObjects[i].y=y;
				gameObjects[i].x=END_OF_GAMEFIELD;
				gameObjects.type=type;
				gameObjects.isDeleted=0;
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
				case playerBullet:
					gameObjects[i].x++;
				break;
				
			}
		}
	}
	
	for(int i=0;i<AMMOUNT_OF_PLAYER_BULLETS;++i)
	{
		if(playerBullets[i].isDeleted=0)
		{
			playerBullets[i].x++;
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
				case barrier:
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
					pickUpPowerUp(hpPowerUp);
					break;
				case barrierPowerUp:
					pickUpPowerUp(barrierPowerUp);
					break;
				case laserPowerUp(laserPowerUp);
					pickUpPowerUp(laserPowerUp);
					break;
				case decreaseSpeedPowerUp:;
					pickUpPowerUp(decreaseSpeedPowerUp);
					break;
			}
		}
		for(int u=0;u<AMMOUNT_OF_PLAYER_BULLETS;++u)
		{
			if(gameObjects[i].idDeleted==0 && gameObjects[i].type = enemy && player.playerBullets[u].isDeleted==0 && gameObjects[i].x ==player.playerBullets[u].x  && gameObjects[i].y==player.playerBullets[u].y )
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
