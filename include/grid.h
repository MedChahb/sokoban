/**
 * @file grid.h
 * @author Mohammed chahbaoui Mohamed yassine azaza (you@domain.com)
 * @brief hearder pour le grid.c
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GRID_HEADER
#define GRID_HEADER

#include <stdio.h>
#include "player.h"
/**
 * @brief specifie chaque caractere de la grille par un nom
 * 
 */
enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' '
};
/**
 *\typedef typedef struct Grid;
 * type synonyme de \c struct \c Grid
 * @struct Grid grid.h
 * @brief Cette structure contient la grille et ces dimensions.
 * concernant la grille du jeu et son contenu
 */
typedef struct {
	enum CaseType* game_grid; /**< Tableau contenant les entités présents dans le jeu */
	int column_number; /**< Nombre de colonne de game_grid */
	int row_number; /**< Nomber de ligne de game_grid */
	struct player Player; /**< Le joueur avec ces coordonnées */
}Grid ;



void init_level(const char* file_path, Grid* grille);
void display(Grid* grille);
void move_player(Grid* grille, enum Direction dir);

#endif
