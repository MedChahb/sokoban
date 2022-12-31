/**
 * @file player.c
 * @author Mohammed chahbaoui et Mohamed yassine azaza.
 * @brief mise à jour de la position de joueur selon la direction entrée.\n
 * 
 */

#include "../include/grid.h"
#include <stdlib.h>

int* tab_coord_cibles; // un tableau global contenant les coord de tous les cibles (avant de jouer)
enum CaseType box_passe_sur = NONE;
enum CaseType entite = NONE;
/**
 * @brief change les coordonnées du joueur selon la direction.\n 
 * 
 * @param grille adresse de la structure Grid.
 * @param dir direction où on va déplacer le joueur.
 * @return renvoie la grille après le changement de la position de joueur et les box.
 */
void move_player(Grid* grille, enum Direction dir){
	int colonne = grille->column_number; // nmbr de colonne de la grille
	int ligne = grille->row_number; // nmbr de ligne de la grille
	int coord_player_1D = (grille->Player).x + (grille->Player).y *  colonne; // les coordonées du Player dans un tableau 1D depuis une grille (2D)
	int boolean = 1; // si boolean affiche la grille sinon rien
	
	
	switch(dir){
		case TOP :// mouvement en haut décremente le y(en 2D) donc diminue les coord player en 1D par une valeur colonne
			  // d'apres la formule 
			
			// on enleve le joueur de la grille pour le moment 
			grille->game_grid[coord_player_1D] = NONE; 
			
			
			// m-a-j des coord (en 1D et 2D)
			(grille->Player).y -=1;
			coord_player_1D -= colonne;
			
			entite = grille->game_grid[coord_player_1D] ;
			
			// s'assurer de ne pas depasser un murs ou un box (ne pas depasser les boxs === ne pas sortir de la zone
			// puisque la grille est entouré des murs)
			// si on passera sur un WALL OU Entre un WALL (OU un autre BOX) et le joueur y a Box 
			enum CaseType dessus_de_ou_on_vas = grille->game_grid[coord_player_1D - colonne];
			if (grille->game_grid[coord_player_1D] == WALL ||((dessus_de_ou_on_vas == WALL || dessus_de_ou_on_vas == BOX)&& grille->game_grid[coord_player_1D] == BOX)){ 
				// on rechange les coords de tel sort qu'on a rien fait
				(grille->Player).y +=1;
				coord_player_1D += colonne;
				boolean = 0;
				printf("\n!! MOUVEMENT INVALIDE !!\n");
			}
			
			if (grille->game_grid[coord_player_1D] == BOX ){
				int coord_box_1D = coord_player_1D;
				int ou_mettre_box = coord_player_1D - colonne; // ou sera le box apres mvmt
				box_passe_sur = grille->game_grid[ou_mettre_box];
				grille->game_grid[ou_mettre_box] = BOX; // placer le box
			}
			
			// placement du PLayer apres maj des son coord 
			grille->game_grid[coord_player_1D] = PLAYER; 

			break;
			
			
		case BOTTOM:			 

			grille->game_grid[coord_player_1D] = NONE; 
			

			(grille->Player).y +=1;
			coord_player_1D += colonne;
			
			entite = grille->game_grid[coord_player_1D] ;

			enum CaseType dessous_de_ou_on_vas = grille->game_grid[coord_player_1D + colonne];
			if (grille->game_grid[coord_player_1D] == WALL || ((dessous_de_ou_on_vas == WALL || dessous_de_ou_on_vas == BOX) && grille->game_grid[coord_player_1D] == BOX)){

				(grille->Player).y -=1;
				coord_player_1D -= colonne;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				boolean = 0;
			}

			if (grille->game_grid[coord_player_1D] == BOX ){
				int coord_box_1D = coord_player_1D;
				int ou_mettre_box = coord_player_1D + colonne; // ou sera le box apres mvmt
				box_passe_sur = grille->game_grid[ou_mettre_box];
				grille->game_grid[ou_mettre_box] = BOX; // placer le box
			}
			
			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
			
		case RIGHT:
			
			grille->game_grid[coord_player_1D] = NONE;
			
			(grille->Player).x +=1;
			coord_player_1D += 1;

			entite = grille->game_grid[coord_player_1D] ;

			enum CaseType right_de_ou_on_vas = grille->game_grid[coord_player_1D +1 ];
			if (grille->game_grid[coord_player_1D] == WALL ||((right_de_ou_on_vas == WALL || right_de_ou_on_vas == BOX)&& grille->game_grid[coord_player_1D] == BOX)){
				(grille->Player).x -=1;
				coord_player_1D -= 1;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				boolean = 0;
			}
			if (grille->game_grid[coord_player_1D] == BOX ){
				int coord_box_1D = coord_player_1D;
				int ou_mettre_box = coord_player_1D + 1; // ou sera le box apres mvmt
				box_passe_sur = grille->game_grid[ou_mettre_box];
				grille->game_grid[ou_mettre_box] = BOX; // placer le box
			}


			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
			
		case LEFT:
		
			grille->game_grid[coord_player_1D] = NONE;
			
			(grille->Player).x -=1;
			coord_player_1D -= 1;
			
			entite = grille->game_grid[coord_player_1D] ;

			enum CaseType left_de_ou_on_vas = grille->game_grid[coord_player_1D - 1];
			if (grille->game_grid[coord_player_1D] == WALL ||((left_de_ou_on_vas == WALL || left_de_ou_on_vas == BOX)&& grille->game_grid[coord_player_1D] == BOX)){
				(grille->Player).x +=1;
				coord_player_1D += 1;
				printf("\n!! MOUVEMENT INVALIDE !!\n\n");
				boolean = 0;
			}

			if (grille->game_grid[coord_player_1D] == BOX ){
				int coord_box_1D = coord_player_1D;
				int ou_mettre_box = coord_player_1D - 1; // ou sera le box apres mvmt
				box_passe_sur = grille->game_grid[ou_mettre_box];
				grille->game_grid[ou_mettre_box] = BOX; // placer le box
			}
			
			grille->game_grid[coord_player_1D] = PLAYER; 
			break;
			
		default :
			printf("\ninvalide key\n");	
		
	}

	for(int i=0 ; i<grille->nbr_cibles; i++){
		// replacer les cibles supprimés pendant le mouvement de PLayer et BOX	
		if(grille->game_grid[tab_coord_cibles[i]]==NONE){
			grille->game_grid[tab_coord_cibles[i]] = GOAL;
		}
	}
	// si le mvmt donné est valide alors 
	if (boolean){
		for(int i=0 ; i<grille->nbr_cibles; i++){
		// replacer les cibles supprimés pendant le mouvement de PLayer et BOX	
		if(grille->game_grid[tab_coord_cibles[i]]==NONE){
			grille->game_grid[tab_coord_cibles[i]] = GOAL;
			}
		}
		// aficher la grille
		display(grille);
		cible_couvert(grille);
	}			
}

void coord_goals(Grid* grille){
	int size_grid = grille->column_number * grille->row_number;
	int j = 0;
	tab_coord_cibles = malloc(sizeof(int)*grille->nbr_cibles);
	for(int i=0 ; i<size_grid ; i++){
		if(grille->game_grid[i]==GOAL){
			tab_coord_cibles[j] = i;
			j++;
		}
	}
}

void cible_couvert(Grid* grille){
	int colonne = grille->column_number; // nmbr de colonne de la grille
	int ligne = grille->row_number; // nmbr de ligne de la grille

	int nbr_cible_non_couvert=0;
	for(int i=0; i<grille->nbr_cibles; i++){
		if(grille->game_grid[tab_coord_cibles[i]]!=BOX){
			nbr_cible_non_couvert++;
		}
	}
	// m-à-j du champs nbr_cibles_couvert apres chaque appel (mvmt)
	grille->nbr_cibles_couvert = grille->nbr_cibles - nbr_cible_non_couvert;
}