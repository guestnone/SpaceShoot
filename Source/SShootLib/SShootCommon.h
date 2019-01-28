/** @addtogroup Common
 *  @{
 */

#pragma once

/**
 * The mode in which the program is running.
 */
typedef enum
{
	/** Main menu */
	MainScreen = 0,
	/** Gameplay mode */
	Game,
	/** About screen */
	About
} MainLoopState;

/** Type of the ship chosen by the player */
typedef enum
{
	First,
	Second,
	Third,
	Fourth
} ShipType;

/* @} */
