/**
 * @file grid.c
 * @author Mohammed chahbaoui et Mohamed yassine azaza 
 * @brief la création et l'affichage de la grille.\n
 * 
 */

#include "../include/grid.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * @brief permet de specifier la structure Grid.\n
 * @fn init_level(const char* file_path, Grid* grille)
 * @param file_path repertoire de fichier.
 * @param grille adresse de la structure Grid. 
 * @return intialise les variables de la structure Grid.
 */
void init_level(const char* file_path, Grid* grille){
	// ouverture du fichier en mode lecture
	grille->nbr_cibles=0;
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
			// parametrer le champs Player
			if (*buffer == PLAYER) {
				(grille->Player).x = current_column;
				(grille->Player).y = current_row;
			}

			if(*buffer==GOAL){
				grille->nbr_cibles++;
			}
			
			// chaque entité (pointeur) lue est placée dans la grille en utilisant la enum
			grille->game_grid[i++] = *buffer ; 
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
/**
 * @brief permet l'afichage de la grille.\n
 * @param grille adresse de la structure Grid.
 * @return un affichage de la grille sur le terminal.
 */
void display(Grid* grille){
	int colonne = grille->column_number; // nmbr de colonne de la grille
	int ligne = grille->row_number; // nmbr de ligne de la grille
	int taille_grille_1D = colonne*ligne ; //taille de la grille
	for (int i=0; i<=taille_grille_1D; i++){
		if(i%colonne==0) printf("\n"); // saut de ligne si en arrive a la fin du colonne
		printf("%c", grille->game_grid[i]);
	}
	printf("\ntape Z to go UP, S to go DOWN, D to go RIGHT or Q to go LEFT, X to exit the game\n");
	printf("\n");
}
