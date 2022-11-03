#include "grid.h"

// global variable contenent l'entité de la grille que le joueur a passé sur. (par defaut NONE)
enum CaseType entite = NONE;

void move_player(Grid* grille, enum Direction dir){
	int colonne = grille->column_number; // nmbr de colonne de la grille
	int ligne = grille->row_number; // nmbr de ligne de la grille
	int coord_player_1D = (grille->Player).x + (grille->Player).y *  colonne; // les coordonées du Player dans un tableau 1D depuis une grille (2D)
	int boolean = 1;
	
	
	switch(dir){
		case TOP :// mouvement en haut décremente le y(en 2D) donc diminue les coord player en 1D par une valeur colonne
			  // d'apres la formule 
			
			// on enleve le joueur de la grille pour le moment 
			grille->game_grid[coord_player_1D] = entite; 
			
			
			// m-a-j des coord (en 1D et 2D)
			(grille->Player).y -=1;
			coord_player_1D -= colonne;
			
			// on change l'entité à ce que le joueur a passé sur
			entite = grille->game_grid[coord_player_1D];
			
			// s'assurer de ne pas depasser un murs ou un box (ne pas depasser les boxs === ne pas sortir de la zone
			// puisque la grille est entouré des murs)
			if (grille->game_grid[coord_player_1D] == BOX || grille->game_grid[coord_player_1D] == WALL){
				// on rechange les coords de tel sort qu'on a rien fait
				(grille->Player).y +=1;
				coord_player_1D += colonne;
				// entite = NONE ou GOAL pas d'autre ,sinon en revient au defaut (NONE)
				entite = NONE;
				boolean = 0;
				printf("\!! MOUVEMENT INVALIDE !!\n\n");
			}
			
			
			// placement du PLayer apres maj des son coord 
			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
			
			
		case BOTTOM:			 

			grille->game_grid[coord_player_1D] = entite; 
			

			(grille->Player).y +=1;
			coord_player_1D += colonne;
			
			entite = grille->game_grid[coord_player_1D];

			if (grille->game_grid[coord_player_1D] == BOX || grille->game_grid[coord_player_1D] == WALL){

				(grille->Player).y -=1;
				coord_player_1D -= colonne;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				entite = NONE;
				boolean = 0;
			}
			
			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
			
		case RIGHT:
			
			grille->game_grid[coord_player_1D] = entite;
			
			(grille->Player).x +=1;
			coord_player_1D += 1;
			
			entite = grille->game_grid[coord_player_1D];

			if (grille->game_grid[coord_player_1D] == BOX || grille->game_grid[coord_player_1D] == WALL){
				(grille->Player).x -=1;
				coord_player_1D -= 1;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				entite = NONE;
				boolean = 0;
			}
			

			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
			
		case LEFT:
		
			grille->game_grid[coord_player_1D] = entite;
			
			(grille->Player).x -=1;
			coord_player_1D -= 1;
			
			entite = grille->game_grid[coord_player_1D];
			
			if (grille->game_grid[coord_player_1D] == BOX || grille->game_grid[coord_player_1D] == WALL){
				(grille->Player).x +=1;
				coord_player_1D += 1;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				entite = NONE;
				boolean = 0;
			}
			
			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
			
		default :
			printf("\ninvalide key\n");			
		
	
	}
	// affichage la grille aprés le mvmt	
	if (boolean)		
	display(grille);		   
}
