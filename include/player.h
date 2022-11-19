/**
 * @file player.h
 * @brief header de player.c
 * @author mohammed chabaoui et Mohamed yassine azaza
 */
//----------

/**
 * @enum
 * @brief specifie chaque direction donnée par le joueur.\n
 */

enum Direction {
	TOP = 'z',/**< 'z'*/
	BOTTOM = 's',/**< 's'*/
	LEFT = 'q',/**< 'q'*/
	RIGHT = 'd',/**< 'd'*/
	
};

/**
 * @struct player
 * @brief structure contient les coordonées de player.\n
 */
struct player{
	int x;/**< coordoonée colonne. */
	int y;/**< coordoonée ligne.  */
};


