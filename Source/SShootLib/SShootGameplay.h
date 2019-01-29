//---------------------------------------------------------------------------
/*  SPDX-License-Identifier: Expat
	
	Copyright (C) 2018-2019 Patrick Rećko, Yan Yanutsevich, Paweł Krzywosz
	
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
	/** Shield on the player */
	barrier,
	/** Destroys all enemies that are on the line */
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
	/** Remaining time in which the power up is active */
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
	/** Health pack - restores life */
	hpPowerUp,
	/** Shield - protect from collision */
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
 * Handles creation of the players bullet.
 * 
 * @param[in] y Player's current position.
 * 
 * @note Internal Function
 */
void shootPlayerBullet(char y);

/**
 * Handles creation of the enemy's bullet.
 *
 * @param[in]  x     Enemy's current X position
 * @param[in]  y     Enemy's current X position
 * 
 * @note Internal Function
 */
void shootEnemyBullet(char x, char y);

/**
 * Gets the random Y position.
 *
 * Used during non-player object placement.
 *
 * @return     The y position.
 * 
 * @note Internal Function
 */
char getYPos();

/**
 * Gets the randomly generated object ID.
 * Used during creation a new field object.
 *
 * @return     The object type.
 * 
 * @note Internal Function
 */
TypeOfObject getRandomObjectType();

/**
 * Puts an object on game-field.
 * 
 * @note Internal Function
 */
void putObjectOnGamefield();

/**
 * Updates the positions of the enemy bullets.
 * 
 * @note Internal Function
 */
void updateFastElementsPositions();

/**
 * Updates the positions of everything except enemy bullets.
 * 
 * @note Internal Function
 */
void updateSlowElementsPositions();

/**
 * Handles the power-ups logic when they were picked during gameplay.
 *
 * @param[in]  powerup  Picked power-up.
 * 
 * @note Internal Function
 */
void pickUpPowerUp(PowerUp powerup);

/**
 * Handles the timer for shield power-up and disable it if ran out of time.
 * 
 * @note Internal Function
 */
void decreasePowerUpRemaingTime();

/**
 * Performs the actual collision detection between object.
 *
 * @note Internal Function
 */
void detectCollisions();

/**
 * Internal check for generating a object.
 * 
 * @note Internal Function
 */
char doIGenerateAnObject();

/**
 * Update the number of lightened-up diodes with number of life's
 *
 * @param[in]  play Current player.
 * 
 * @note Internal Function
 * If number of life's is over or equal 3, all the diodes will be turned on.
 */
void diodesLives(PlayerObject play);


/**
 * @brief Displays the Game over screen.
 *
 * Flashes a few times and prints a word "GAME OVER"
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
 * Invokes the actual gameplay loop of the game.
 * 
 * @note Internal Function
 */
void gmplMainPart();

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
