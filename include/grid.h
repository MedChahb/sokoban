/**
 * @file grid.h
 * @author Mohammed chahbaoui et Mohamed yassine azaza
 * @brief hearder pour le grid.c
 * 
 */

#ifndef GRID_HEADER
#define GRID_HEADER

#include <stdio.h>
#include "player.h"
/**
 * @enum
 * @brief specifie chaque charactaire du la Grille par un nom.\n
 */
enum CaseType{
	WALL = '#',/**< '#'*/
	BOX = '$',/**< '$'*/
	PLAYER = '@',/**< '@'*/
	GOAL = '.',/**< '.'*/
	NONE = ' '/**< ' ' (espace)*/
};
/**
 *\typedef typedef struct Grid;
 * type synonyme de \c struct \c Grid
 * @struct Grid grid.h
 * @brief structure qui contient la grille et ces dimensions avec les coordonnées du Player.\n
 */
typedef struct {
	enum CaseType* game_grid; /**< Tableau contenant les entités présents dans le jeu */
	int column_number; /**< Nombre de colonne de game_grid */
	int nbr_cibles; /**< Nombre de cibles avant le commencement du jeu*/
	int nbr_cibles_couvert; /**< Nombre de cibles convertes */
	int row_number; /**< Nomber de ligne de game_grid */
	struct player Player; /**< Le joueur avec ces coordonnées */
}Grid ;



void init_level(const char* file_path, Grid* grille);
void display(Grid* grille);
void move_player(Grid* grille, enum Direction dir);
void coord_goals(Grid* grille);

#endif
