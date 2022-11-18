#ifndef GRID_HEADER
#define GRID_HEADER

#include <stdio.h>
#include "player.h"
enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' '
};
/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
typedef struct {
	enum CaseType* game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nomber de ligne de game_grid
	struct player Player;
}Grid ;



void init_level(const char* file_path, Grid* grille);
void display(Grid* grille);
void move_player(Grid* grille, enum Direction dir);

#endif