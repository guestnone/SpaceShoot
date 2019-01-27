//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
	This source file is released under the MIT License.
	See LICENSE.md for full terms. This notice is not to be removed.
*/
//---------------------------------------------------------------------------

#pragma once

#include "SShootCommon.h"

/** @addtogroup Gameplay
 *  @{
 */

/** Type of the Power Up that can be spawned. */
typedef enum PowerUp
{
	/** Health Pack */
	hp,
	/**  */
	barrier,
	/**  */
	laser,
	/** Slows down the ship */
	speed
} PowerUp;

/** Contains informations about the Bullet */
typedef struct Bullet
{
	/** X position on the map */
	char x;
	/** Y position on the map */
	char y;
	/** Check if the bullet was destroyed */
	char isDeleted;
} Bullet;

/**  Contains informations about the controllable player object. */
typedef struct PlayerObject
{
	/** Number of lives. */
	char lives;
	/** Y position on the map (X position is constant) */
	char y;
	/** Check if the Power up is active */
	char isPowerUpActive;
	/** Time in which the power up is active */
	char powerUpRemainingTime;
	
	/** Type of the Power Up picked by the player*/
	PowerUp powerup;
	/** Contains the bullets that were shot be the player */
	Bullet playerBullets[2];
	/** Check if the player is dead. */
    char isDead;
	
	
} PlayerObject;

/** Type of the object that can be spawned on the map. */
typedef enum TypeOfObject
{
	/** Enemy ship. */
	enemy,
	/** Barrier, which the player can collide with. */
	theBarrier,
	/** Bullet shot be the enemy. */
	enemyBullet,
	///** desc */
    //thePlayerBullet,
    /** Health pack - restores life */
	hpPowerUp,
	/** Shield - protect from collsion */
	barrierPowerUp,
	/** Laser - destroys enemies in its range */
	laserPowerUp,
	/** Speed decrease */
	decreaseSpeedPowerUp
} TypeOfObject;

/** Object other than player or its bullet that can be spawned on the map. */
typedef struct GameObject
{
	/** X position on the map */
	char x;
	/** Y position on the map */
	char y;
	/** Type of spawned object */
	TypeOfObject type;
	/** Check, if the object was destroyed */
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
TypeOfObject getRandomObjectType();

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

void decreasePowerUpRemaingTime();

/**
 * Performs the actual collision detection between object.
 */
void detectCollisions();

/**
 * Refreshes the LCD screen based on the state of the gameplay.
 * 
 * @note Internal Function
 */

char doIGenerateAnObject();


/**
 * Displays the Game over screen. Flashes a few times and print a word "GAME OVER"
 *
 * @note Internal Function
 */
void gmplDisplayGameOver();

/**
 * Updates the players LCD Screen based on the state of the game.
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

/** @} */