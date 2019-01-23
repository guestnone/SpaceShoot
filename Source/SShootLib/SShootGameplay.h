//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once

#include "SShootCommon.h"

/** PowerUp */
typedef enum PowerUp
{
	/** desc */
	hp,
	/** desc */
	barrier,
	/** desc */
	laser,
	/** desc */
	speed
} PowerUp;

/** desc */
typedef struct PlayerBullet
{
	/** desc */
	char x;
	/** desc */
	char y;
	/** desc */
	char isDeleted;
} PlayerBullet;

/** desc */
typedef struct PlayerObject
{
	/** desc */
	char lives;
	/** desc */
	char y;
	/** desc */
	char isPowerUpActive;
	/** desc */
	PowerUp powerup;
	/** desc */
	PlayerBullet playerBullets[2];
	/** desc */
    char isDead;
} PlayerObject;

/** desc */
typedef enum TypeOfObject
{
	/** desc */
	enemy,
	/** desc */
	theBarrier,
	/** desc */
	enemyBullet,
	/** desc */
    thePlayerBullet,
    /** desc */
	hpPowerUp,
	/** desc */
	barrierPowerUp,
	/** desc */
	laserPowerUp,
	/** desc */
	decreaseSpeedPowerUp
} TypeOfObject;

/** desc */
typedef struct GameObject
{
	/** desc */
	char x;
	/** desc */
	char y;
	/** desc */
	TypeOfObject type;
	/** desc */
	char isDeleted;
} GameObject;

/**
 * todo doc
 * 
 * @note Internal Function
 */
void shootPlayerBullet();

/**
 * { function_description }
 *
 * @param[in]  x     { parameter_description }
 * @param[in]  y     { parameter_description }
 * 
 * @note Internal Function
 */
void shootEnemyBullet(char x, char y);

/**
 * Gets the y position.
 *
 * @return     The y position.
 * 
 * @note Internal Function
 */
char getYPos();

/**
 * Gets the object type.
 *
 * @return     The object type.
 * 
 * @note Internal Function
 */
TypeOfObject getObjectType();

/**
 * Puts an object on gamefield.
 * 
 * @note Internal Function
 */
void putObjectOnGamefield();

/**
 * { function_description }
 * 
 * @note Internal Function
 */
void updateFastElementsPositions();

/**
 * { function_description }
 * 
 * @note Internal Function
 */
void updateSlowElementsPositions();

/**
 * Decreases the health for the player by 1.
 * 
 * @note Internal Function
 */
void decreaseHp();

/**
 * 
 *
 * @param[in]  powerup  The powerup
 * 
 * @note Internal Function
 */
void pickUpPowerUp(PowerUp powerup);

/**
 * 
 *
 * @param[in]  idOfEnemy  The identifier of enemy
 * 
 * @note Internal Function
 */
void collisionOfPlayerBulletWithEnemy(int idOfEnemy);

/**
 * Perfoms the colission detection between a player and the objects/enemies.
 * 
 * @note Internal Function
 */
void detectCollisions();

/**
 * Refreshes the LCD screen based on the state of the gameplay.
 * 
 * @note Internal Function
 */
void gmplRefreshDisplay();

/**
 * Inokes the actual gameplay loop of the game.
 * 
 * @note Internal Function
 */
void gmplMainPart();

/**
 * Invokes the high score input screen.
 * 
 * @note Internal Function
 */
void gmplHighScoreInput();

/**
 * Initializes the game part based on the selected ship.
 *
 * @param[in]  ship  The ship that was chosen.
 * 
 * @note Internal Function
 */
void gmplSetUp(ShipType ship);

/**
 * Enters the main game loop
 *
 * @return     Main menu loop state
 */
MainLoopState gmplLoopEnter();

/**
 * Invokes the ship select screen for the user. Used to get the chosen ship type.
 *
 * @return     Chosen ship
 * 
 * @note Internal Function
 */
ShipType gmplShipSelect();
