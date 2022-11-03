#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void init_level(const char* file_path, Grid* grille){
	// ouverture du fichier en mode lecture
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; /// nombre de ligne
	int number_goals = 0;
	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	grille->game_grid = malloc(sizeof(enum CaseType)); // allocation tab dans grille.game_grid
	int current_row = 0;
	int current_goal = 0;
	int i =0; // indice du tableau game_grid
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			// chaque entité (pointeur) lue est placée dans la grille en utilisant la enum
			grille->game_grid[i++] = (*buffer=='#')?WALL : (*buffer=='$')?BOX : (*buffer=='@')? PLAYER : (*buffer=='.')?GOAL : (*buffer==' ')?NONE : '\0' ; 
			current_column += 1;
			buffer += 1;
			
		}	
		grille->column_number = current_column; //setting column_number
		current_row += 1;
	}
	grille->row_number = current_row; //setting row	_number
	// fermeture du fichier
	fclose(file);
}
