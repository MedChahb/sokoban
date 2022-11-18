/**
 * @file player.h
 * @brief header de player.c
 * @author mohammed chabaoui Mohamed yassine azaza
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright (c) 2022 
 */
//----------

/**
 * @enum
 * @brief specifie chaque direction donnée par le joueur
 */

enum Direction {
	TOP = 'z',
	BOTTOM = 's',
	LEFT = 'q',
	RIGHT = 'd',
	
};

/**
 * @struct player
 * @brief structure contient les coordonées de player
 * 
 */
struct player{
	int x;/**< point colonne */
	int y;/**< point ligne  */
};


